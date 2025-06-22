# Concetti Avanzati di SQL

## Vincoli di integrità generici (CHECK e ASSERTION)

I vincoli di **CHECK** permettono di definire condizioni di validità all’interno di una singola tupla o tra tuple diverse. Ad esempio, la tabella `Persona` può garantire che l’età sia compresa tra 17 e 99 anni e che lo stipendio di un dipendente non superi quello del proprio capo:

```sql
CREATE TABLE Persona (
    ID SERIAL PRIMARY KEY,
    Eta INT CHECK (Eta > 16 AND Eta < 100),
    Stipendio NUMERIC,
    IDCapo INT,
    CHECK (
        Stipendio <= (
            SELECT MAX(D2.Stipendio)
            FROM Persona D2
            WHERE D2.ID = Persona.IDCapo
        )
    )
);
```

Un **ASSERTION** è un vincolo a livello di schema che estende il concetto di CHECK su intere relazioni. Sebbene poco supportate dai DBMS standard, possono esprimere regole globali:

```sql
CREATE ASSERTION StipendioNonSuperiore
CHECK (
    NOT EXISTS (
        SELECT *
        FROM Persona P1, Persona P2
        WHERE P1.IDCapo = P2.ID
          AND P1.Stipendio > P2.Stipendio
    )
);
```

## Viste avanzate

Le **viste** avanzate semplificano query ricorrenti e implementano controlli di sicurezza sui dati. Con l’opzione **WITH CHECK OPTION** si assicura che ogni aggiornamento alle tuple mantenga le condizioni della vista:

```sql
CREATE VIEW ImpiegatiAttivi AS
    SELECT ID, Nome, Dipartimento
    FROM Impiegati
    WHERE Stato = 'attivo'
WITH CHECK OPTION;
```

Questa clausola impedisce inserimenti o modifiche che violino il filtro `Stato = 'attivo'`.

## Funzioni scalari

Le **funzioni scalari** operano su singoli valori restituendo un risultato elementare. Tra le più utilizzate:

```sql
SELECT
    LOWER(Nome) AS nome_minuscolo,
    UPPER(Cognome) AS cognome_maiuscolo,
    EXTRACT(YEAR FROM DataNascita) AS anno_nascita,
    CAST(Stipendio AS INTEGER) AS stipendio_intero
FROM Dipendenti;
```

Questi esempi mostrano trasformazioni di stringhe, estrazione di componenti temporali e conversione di tipi.

## Controllo dell’accesso e privilegi

La gestione di **GRANT** e **REVOKE** definisce i privilegi sulle risorse del database. È possibile concedere permessi specifici a ruoli o utenti, anche con l’opzione **WITH GRANT OPTION** per propagare ulteriori assegnazioni:

```sql
GRANT SELECT, INSERT ON Clienti TO Operatore;
REVOKE DELETE ON Clienti FROM UtenteNonAutorizzato;
GRANT SELECT ON Impiegati TO Manager WITH GRANT OPTION;
```

Queste dichiarazioni gestiscono l’accesso in lettura, in scrittura e la possibilità di delegare.

## Best practice per autorizzazioni tramite viste

Per limitare l’accesso a sottoinsiemi di dati si possono utilizzare viste protette dai privilegi diretti sulla tabella di base:

```sql
CREATE VIEW ImpiegatiNonCapo AS
    SELECT ID, Nome
    FROM Impiegati
    WHERE ID NOT IN (SELECT DISTINCT IDCapo FROM Impiegati);

GRANT SELECT ON ImpiegatiNonCapo TO Public;
GRANT INSERT ON ImpiegatiNonCapo TO HRDepartment;
```

In questo modo si offre un’interfaccia controllata, mantenendo intatti i permessi originali sulle tabelle sottostanti.
