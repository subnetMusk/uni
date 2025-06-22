# Concetti di Base di SQL

## Introduzione e Categorie

**SQL** è il linguaggio standard per la definizione e la manipolazione di basi di dati relazionali. Si compone di due sotto-linguaggi complementari: il **DDL (Data Definition Language)**, utilizzato per definire strutture e vincoli, e il **DML (Data Manipulation Language)**, impiegato per interrogare e aggiornare i dati nel database.

## Definizione di Tabelle e Domini

La creazione di tabelle avviene tramite **CREATE TABLE**, che consente di specificare attributi, domini e vincoli come **NOT NULL**, **UNIQUE**, **PRIMARY KEY**, **DEFAULT**, **CHECK** e **FOREIGN KEY**:

```sql
CREATE TABLE Esempio (
	fk INT NOT NULL,
	nome VARCHAR(50) UNIQUE,
	data_creazione DATE DEFAULT CURRENT_DATE,
	PRIMARY KEY (fk),
	FOREIGN KEY (fk) REFERENCES AltraTabella(id)
);
```

Per definire domini riutilizzabili si usa **CREATE DOMAIN**, specificando il tipo di dati e vincoli di validazione:

```sql
CREATE DOMAIN PositiveInt AS INT
	CHECK (VALUE > 0);
```

## Vincoli di Integrità

I vincoli di **integrità intrarelazionale** garantiscono la correttezza dei dati all’interno della stessa tabella, mentre i vincoli **interrelazionali** (integrità referenziale) assicurano che i riferimenti tra tabelle rimangano validi. Di seguito un esempio che combina entrambi:

```sql
CREATE TABLE Ordini (
	id_ordine SERIAL PRIMARY KEY,
	importo NUMERIC CHECK (importo >= 0),
	id_cliente INT NOT NULL,
	FOREIGN KEY (id_cliente)
	    REFERENCES Clienti(id_cliente)
	    ON DELETE CASCADE
	    ON UPDATE SET NULL
);
```

## Operazioni di Manipolazione Dati (DML)

Le principali operazioni DML sono **INSERT**, **UPDATE** e **DELETE**, utilizzate rispettivamente per aggiungere, modificare e rimuovere record:

```sql
INSERT INTO Esempio (fk, nome)
	VALUES (1, 'Alice'),
	       (2, 'Bob');

UPDATE Esempio
	SET nome = 'Carlo'
	WHERE fk = 1;

DELETE FROM Esempio
	WHERE fk = 2;
```

## Query di Selezione (SELECT)

La clausola **SELECT** consente di estrarre dati dal database con filtri e ordinamenti. È possibile utilizzare **alias** e **DISTINCT** per eliminare duplicati:

```sql
SELECT E.fk, E.nome
FROM Esempio AS E
WHERE E.fk > 10
ORDER BY E.nome;
```

## Join e Prodotto Cartesiano

Gli **JOIN** combinano tabelle in base a condizioni logiche, mentre il **prodotto cartesiano** genera tutte le combinazioni possibili:

```sql
-- Inner join
SELECT *
FROM TabellaA AS A
JOIN TabellaB AS B
    ON A.id = B.a_id;

-- Left outer join
SELECT *
FROM TabellaA AS A
LEFT JOIN TabellaB AS B
    ON A.id = B.a_id;

-- Prodotto cartesiano
SELECT *
FROM TabellaA, TabellaB;
```

## Operatori Aggregati e Raggruppamenti

Gli operatori **COUNT**, **SUM**, **AVG**, **MIN**, **MAX** vengono utilizzati con **GROUP BY** per aggregare i dati e con **HAVING** per filtrarli:

```sql
SELECT categoria, COUNT(*) AS totale, AVG(prezzo) AS prezzo_medio
FROM Prodotti
GROUP BY categoria
HAVING AVG(prezzo) > 100;
```

## Set Combinatori e Subquery

Gli operatori di set (**UNION**, **INTERSECT**, **EXCEPT**) permettono di combinare i risultati di query diverse. Le **subquery** possono essere annidate in clausole **WHERE** o nella lista di selezione:

```sql
-- Operatori di set
SELECT id FROM TabellaA
UNION
SELECT id FROM TabellaB;

-- Subquery in WHERE
SELECT *
FROM Ordini
WHERE cliente_id IN (
	SELECT id
	FROM Clienti
	WHERE attivo = TRUE
);
```

## Best Practice e Sintassi

Per garantire **manutenibilità** e **leggibilità**, è consigliabile:
- Allineare e indentare chiaramente le query.
- Utilizzare alias significativi.
- Suddividere query complesse su più righe.
- Documentare la logica con commenti SQL.

---

✦ **Nota esami**: gli argomenti trattati qui sono frequentemente oggetto di domande pratiche negli appelli, soprattutto riguardo alla definizione di vincoli, operazioni DML e uso corretto di aggregazioni e subquery.
