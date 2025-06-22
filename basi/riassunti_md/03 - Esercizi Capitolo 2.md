# Esercizi Capitolo 2

## Esercizio 1: Prestiti di biblioteca personale

Nel contesto di una biblioteca personale, il **modello relazionale** si concretizza nella definizione di una tabella dedicata ai prestiti:

```sql
PRESTITO(
  Titolo,
  Nome,
  DataInizioPres,
  DataFinePrestito
)
```

L’unica **assunzione** rilevante è che un amico non possa prendere in prestito lo stesso libro due volte contemporaneamente, garantendo così l’unicità della combinazione Titolo–Nome–DataInizioPres.

### Procedura essenziale

1. Individuare l’**entità** Prestito e i corrispondenti attributi chiave.
2. Validare i **domini**: Titolo e Nome come stringhe, DataInizioPres e DataFinePrestito come date.
3. Stabilire la **chiave primaria** su (Titolo, Nome, DataInizioPres) per assicurare l’univocità di ogni prestito.

✦ **Nota esami**: la transizione da **diagramma ER** a schema relazionale è un tema ricorrente negli appelli (24‑06‑2024, 17‑07‑2024). 

## Esercizio 2: Orario partenze stazione ferroviaria

Per modellare l’orario delle partenze e delle fermate in stazione, si utilizzano due relazioni correlate:

```sql
PARTENZE(
  Numero,
  Orario,
  Destinazione,
  Categoria
)

FERMATE(
  Treno,
  Stazione,
  Orario
)
```

Il **vincolo di integrità referenziale** impone che ogni valore di FERMATE.Treno sia presente come chiave primaria in PARTENZE.Numero, evitando riferimenti orfani.

### Procedura essenziale

1. Separare i dati **statici** (partenze) da quelli **variabili** (fermate), definendo due tabelle distinte.
2. Definire la **chiave primaria** di PARTENZE su Numero e quella di FERMATE come coppia (Treno, Stazione).
3. Applicare il **vincolo referenziale** tra FERMATE.Treno e PARTENZE.Numero per mantenere la coerenza.

✦ **Nota esami**: la gestione dei vincoli referenziali è spesso verificata in esercizi avanzati di progettazione logica.  

## Esercizio 3: Azienda con impiegati e filiali

La struttura prevede due tabelle principali, una per gli impiegati e l’altra per le filiali:

```sql
IMPIEGATI(
  CF,
  Cognome,
  Nome,
  DataNascita,
  CodFiliale
)

FILIALI(
  CodFiliale,
  Sede,
  CF_Direttore
)
```

I **vincoli referenziali** si articolano in due direzioni: ogni CodFiliale in IMPIEGATI deve esistere in FILIALI, mentre CF_Direttore in FILIALI deve corrispondere a un CF valido degli impiegati.

### Procedura essenziale

1. Identificare le **entità** IMPIEGATI e FILIALI insieme ai loro attributi distintivi.
2. Stabilire le **chiavi primarie**: CF per IMPIEGATI e CodFiliale per FILIALI.
3. Definire i **vincoli referenziali** su IMPIEGATI.CodFiliale → FILIALI.CodFiliale e FILIALI.CF_Direttore → IMPIEGATI.CF.

✦ **Nota esami**: diagramma ER e progettazione logica vengono frequentemente richiesti (24‑06‑2024, 17‑07‑2024).  

## Esercizio 7: Chiavi e vincoli su schema dato

Considerando lo schema complesso dei ricoveri, il primo passo è individuare le **chiavi candidate** e la **chiave primaria**. In seguito, si applicano i vincoli referenziali tra le relazioni coinvolte.

### Procedura essenziale

1. Elencare le **dipendenze funzionali** e calcolare le **chiusure** degli attributi per determinare le chiavi candidate e la chiave primaria.
2. Verificare i **vincoli referenziali** tra:
   - RICOVERI.Paziente → PAZIENTI.Cod  
   - RICOVERI.Reparto → REPARTI.Cod  
   - REPARTI.Primario → MEDICI.Matr  
   - MEDICI.Reparto → REPARTI.Cod  
3. Identificare gli **attributi nullabili** in base alle politiche di integrità e contesto applicativo.
4. Assicurarsi della **minimalità** di ogni chiave primaria eliminando eventuali attributi ridondanti.

✦ **Nota esami**: la verifica di superchiave e la normalizzazione sono temi centrali nei quiz di vari appelli (17‑07‑2024 Q1; 26‑08‑2024 Q1).  
