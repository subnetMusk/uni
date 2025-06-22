# Introduzione al Corso

## Sistemi Informativi

In un'organizzazione, ossia un insieme coordinato di individui e risorse che collaborano per il raggiungimento di obiettivi comuni, il **sistema informativo** rappresenta l’insieme di processi, regole e tecnologie finalizzate alla raccolta, all’elaborazione e alla gestione delle informazioni rilevanti. La componente automatizzata di questo sistema, basata su hardware, software e reti, prende il nome di **sistema informatico**, il cui scopo è supportare le attività quotidiane riducendo errori e tempi di gestione. Al cuore di questa architettura vi è la **base di dati**, che consiste in un insieme organizzato, persistente e condiviso di **dati** strutturati, progettati per memorizzare informazioni in modo efficiente e garantire l’accesso concorrente da parte di più utenti.

## Dati e Informazione

Un **dato** è un elemento grezzo, un fatto isolato o una misurazione (ad esempio un valore numerico o una stringa), privo di un significato contestuale. Quando i dati vengono sottoposti a elaborazioni quali selezione, aggregazione e analisi, si generano delle **informazioni**, ossia contenuti che offrono conoscenza significativa e supportano il processo decisionale. Il rapporto tra dati e informazione si sintetizza nell’equazione: **Dati + Elaborazione = Informazione**, dove il corretto trattamento dei dati alimenta analisi affidabili, come nel caso delle proiezioni demografiche ottenute da semplici rilevazioni statistiche.

## DBMS e Caratteristiche delle Basi di Dati

Un **DBMS (Database Management System)** è il software specializzato incaricato di creare, gestire e amministrare le basi di dati. Le principali caratteristiche di una **base di dati** sono:

- **Grandez­za**: capacità di memorizzare e gestire centinaia di milioni o miliardi di record.
- **Persistenza**: i dati sopravvivono all’esecuzione delle applicazioni e ai riavvii di sistema.
- **Condivisione**: supporto all’accesso simultaneo di più utenti preservando la coerenza.

Il DBMS garantisce inoltre funzionalità fondamentali, come la **privacy** tramite meccanismi di autenticazione e autorizzazione, l’**affidabilità** grazie al supporto alle transazioni (proprietà **ACID**: Atomicità, Consistenza, Isolamento, Durabilità), l’**efficienza** nell’ottimizzazione dell’uso di RAM, disco e CPU e la **flessibilità** nell’offerta di servizi aggiuntivi (backup, recovery, replicazione).

## Transazioni e Controllo della Concorrenza

Una **transazione** è una sequenza indivisibile di operazioni di lettura e scrittura sul database, trattata come un’unica unità logica. Le transazioni devono rispettare le proprietà **ACID**, garantendo che ogni modifica sia atomica e durevole, che il sistema rimanga consistente, e che le transazioni concorrenti non interferiscano tra loro. Il **controllo della concorrenza** si basa su tecniche quali il **locking** (blocchi condivisi o esclusivi) e protocolli come il **Two-Phase Locking (2PL)**, che prevengono anomalie quali letture sporche o perdite di aggiornamento. In caso di guasti, i meccanismi di **recovery** utilizzano tecniche di **UNDO** e **REDO** basate su log per ripristinare lo stato coerente del database.

## Modello Relazionale e Linguaggi

Il **modello relazionale**, introdotto da E. F. Codd nel 1970, organizza i dati in **relazioni** (tabelle) composte da attributi (colonne) e tuple (righe). Lo **schema** di una base di dati definisce la struttura delle relazioni e i domini di ciascun attributo, mentre l’**istanza** è l’insieme delle tuple correnti in esse memorizzate. L’interazione con un database relazionale avviene principalmente tramite **SQL**, un linguaggio dichiarativo che comprende:
- Il **DDL (Data Definition Language)** per creare, modificare e cancellare tabelle e vincoli.
- Il **DML (Data Manipulation Language)** per interrogare (SELECT) e modificare (INSERT, UPDATE, DELETE) i dati.

Le query SQL possono essere impiegate in modalità interattiva o integrate all’interno di applicazioni tramite API (ad esempio libpq per C).

## Vantaggi e Svantaggi dei DBMS

L’adozione di un DBMS comporta numerosi **vantaggi**, tra cui la riduzione delle ridondanze, l’indipendenza tra dati e applicazioni, la standardizzazione dei linguaggi di accesso e il supporto alle transazioni. Al contempo, presenta **svantaggi** quali la complessità di installazione e gestione, i costi elevati di licenze e infrastruttura, e la maggiore idoneità a scenari di larga scala piuttosto che a piccoli database semplici.

## Obiettivi del Corso

L’obiettivo principale di questo corso è fornire le competenze necessarie per progettare, implementare e interrogare basi di dati relazionali in modo robusto ed efficiente. Al termine del percorso, lo studente sarà in grado di modellare i requisiti con diagrammi ER, tradurli in schemi relazionali ottimizzati, scrivere query SQL avanzate, gestire transazioni e concorrenza, applicare tecniche di normalizzazione e creare indici per migliorare le prestazioni, oltre a integrare l’accesso ai dati all’interno di applicazioni software.

---

# Il modello relazionale

## Relazione matematica e modello relazionale

Il concetto di **relazione matematica** costituisce le fondamenta teoriche del modello relazionale: si tratta di un sottoinsieme del prodotto cartesiano dei domini D₁, D₂, …, Dₙ, dove ogni **n‑upla** è definita da valori ordinati e distinti. A partire da questa rappresentazione astratta, il **modello relazionale**, formalizzato da Edgar F. Codd nel 1970, introduce l’idea di organizzare i dati in **tabelle**, in cui ogni colonna corrisponde a un attributo e ogni riga a una tupla, garantendo una struttura uniforme e rigorosa.

## Istanza di relazione e istanza di base di dati

Quando si parla di **istanza di relazione**, si intende l’insieme di tutte le tuple attualmente presenti secondo uno schema R(A₁, A₂, …, Aₙ). Estendendo questo concetto, un **database relazionale** è composto da un insieme di relazioni R₁, R₂, …, Rₖ, ognuna definita sul proprio schema. Due proprietà cruciali delle istanze relazionali sono l’assenza di un ordine prefissato tra righe e colonne e l’unicità delle tuple, che evita duplicazioni e garantisce coerenza.

## Vincoli di integrità intrarelazionali

I **vincoli di integrità intrarelazionali** assicurano che i dati all’interno di una singola relazione rispettino regole semantiche di validità. I vincoli di **dominio** impongono che ogni valore appartenga al dominio previsto dall’attributo; i vincoli di **tupla** richiedono che una determinata condizione booleana sia soddisfatta da ciascuna riga, come nel caso di una formula che verifichi la correttezza di un calcolo tra attributi. Infine, i **vincoli di chiave** stabiliscono che esistano insiemi di attributi – le **superchiavi** – in grado di identificare univocamente ogni tupla, tra cui la **chiave primaria**, priva di valori nulli, rappresenta la scelta minima e non ridondante.

**Nota esami:** la verifica di superchiave e chiave è un tema ricorrente, ad esempio nel quiz dell’appello del 17 luglio 2024 (Q1).

## Vincoli di integrità interrelazionali

Per mantenere la coerenza tra più tabelle, si introducono i **vincoli di integrazione referenziale**: un valore presente in un attributo di relazione R₁ deve comparire come chiave primaria in una relazione R₂, assicurando che non vi siano riferimenti “orfani”. Le politiche di gestione di questi vincoli possono includere il rifiuto dell’operazione, la cancellazione a cascata delle tuple dipendenti o l’impostazione di valori nulli, a seconda delle esigenze applicative.

**Nota esami:** l’interazione tra vincoli di integrità e meccanismi di recovery costituisce un argomento avanzato spesso associato a esercizi complessi.

## Valori nulli

I **valori nulli** rappresentano l’assenza di una informazione valida e non appartengono al dominio di alcun attributo. È importante distinguere tra le diverse interpretazioni di null, che possono indicare uno stato sconosciuto, l’inesistenza di un dato o semplicemente l’indisponibilità dell’informazione. Alcuni vincoli, come la chiave primaria, proibiscono l’uso di null per garantire l’identificabilità completa delle tuple.

## Strutture nidificate e normalizzazione

Quando una relazione include dati ripetuti o strutture complesse, la **normalizzazione** suggerisce di scomporre tali elementi in relazioni separate per evitare ridondanza e garantire l’integrità. Ad esempio, dettagli di una ricevuta possono essere estratti in una relazione distinta, collegata tramite chiavi esterne. In alternativa, si può aggiungere un attributo artificiale, come un numero di riga, per preservare l’unicità delle tuple senza duplicare informazioni.



---

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


---

# L'Algebra Relazionale

## Linguaggi per basi di dati

Il termine **DDL (Data Definition Language)** racchiude le istruzioni SQL dedicate alla definizione della struttura di un database, incluse la **creazione** di tabelle, la specifica dei **tipi di dato** per gli attributi e l’imposizione di vincoli come **PRIMARY KEY** e **FOREIGN KEY**. Al contrario, il **DML (Data Manipulation Language)** comprende i comandi destinati alla **manipolazione** dei dati, come **SELECT**, **INSERT**, **UPDATE** e **DELETE**, fondamentali per interrogare e aggiornare le informazioni archiviate.

## Linguaggi di interrogazione

Gli approcci di interrogazione si dividono in metodi **dichiarativi** e **procedurali**. I linguaggi dichiarativi, come **SQL**, permettono di esprimere **cosa** si desidera ottenere, affidando al DBMS l’ottimizzazione del piano di esecuzione. I linguaggi procedurali, come l’**Algebra Relazionale** pura, descrivono invece il **come** ottenere il risultato, fornendo un controllo dettagliato sulla sequenza di operazioni.

## Operatori insiemistici

Gli operatori di insiemistica consentono di combinare i risultati di più relazioni. L’**unione (R ∪ S)** restituisce tutte le tuple presenti in R o in S, a condizione che condividano lo stesso schema. L’**intersezione (R ∩ S)** seleziona solo le tuple comuni, mentre la **differenza (R − S)** restituisce le tuple di R che non appaiono in S. Questi operatori sono essenziali per manipolare i risultati in modo flessibile, senza dover scrivere query multiple.

## Ridenominazione

L’operatore di **ridenominazione (ρ)** permette di modificare il nome di una relazione o dei suoi attributi al fine di evitare conflitti e migliorare la chiarezza delle query, senza alterare i dati sottostanti. Mediante ρ è possibile specificare alias temporanei per facilitare operazioni di **join** tra relazioni con colonne omonime.

## Selezione

L’operatore di **selezione (σ)** filtra le tuple di una relazione in base a una condizione booleana. Applicando σ, lo **schema** rimane invariato, mentre il numero di tuple si riduce a quelle che soddisfano il filtro. Questo meccanismo è alla base delle operazioni di filtro, consentendo di isolare i dati pertinenti per successive elaborazioni.

## Proiezione

L’operatore di **proiezione (π)** consente di estrarre solo un **sottoinsieme di attributi** da una relazione, eliminando eventuali duplicati. La cardinalità del risultato è al massimo pari a quella della relazione originale, ma può diminuire se gli attributi selezionati non costituiscono una **superchiave**, riducendo il numero di tuple duplicate.

## Join

L’operazione di **join** combina tuple di due relazioni in base a condizioni di uguaglianza o generali. Il **join naturale (⋈)** associa automaticamente le colonne con lo stesso nome, mentre l’**equi-join** e il **theta-join** consentono di specificare condizioni su attributi diversi. Quando esiste un vincolo di **chiave esterna** verso la **chiave primaria** in un’altra tabella, la cardinalità del risultato è pari a quella della relazione che contiene la chiave esterna.

## Join esterno

Gli **outer join** estendono il concetto di join includendo tuple che non trovano corrispondenze. Nel **left outer join**, tutte le tuple della tabella di sinistra vengono mantenute, assegnando **NULL** dove mancano i dati corrispondenti; il **right outer join** opera in modo speculare, mentre il **full outer join** conserva tutte le tuple di entrambe le relazioni.

## Semijoin

Il **semijoin (⋉)** restituisce solo le tuple della relazione di sinistra che trovano corrispondenza nella relazione di destra, senza includerne gli attributi. Questa operazione è particolarmente utile in contesti distribuiti, poiché riduce il trasferimento di dati mantenendo solo le tuple rilevanti.

## Prodotto cartesiano

Il **prodotto cartesiano (×)** combina ogni tupla di una relazione con tutte le tuple di un’altra, generando una relazione le cui tuple sono l’insieme di tutte le possibili concatenazioni. Pur essendo raramente utilizzato direttamente, il prodotto cartesiano è la base teorica da cui derivano altre forme di join.

## Equivalenze di espressioni

Le **equivalenze algebriche** permettono di ristrutturare le espressioni per ottimizzare l’esecuzione delle query. Ad esempio, la **distribuzione** di π su σ o di σ su unione può ridurre il numero di tuple intermedie, migliorando le prestazioni complessive del DBMS.

## Selezione con valori nulli

Le condizioni che coinvolgono **NULL** richiedono un’attenzione particolare: i confronti standard ignorano i valori nulli, e per gestirli correttamente si utilizzano **IS NULL** o **IS NOT NULL**, assicurando che le tuple con assenza di informazione siano trattate in modo appropriato.

## Viste

Le **viste** sono oggetti logici definiti da query SQL, che possono essere **virtuali** (ricalcolate ad ogni accesso) o **materializzate** (il risultato memorizzato fisicamente). Nel modello ANSI/SPARC, le viste appartengono al **livello esterno**, separato dal **livello logico** delle tabelle e dal **livello interno** di memorizzazione. Le viste sono fondamentali per semplificare query complesse e implementare controlli di **sicurezza**, sebbene l’**aggiornabilità** resti limitata a casi particolari, come le viste su singola tabella senza aggregazioni.


---

# Esercizi Algebra Relazionale

## Esercizio 1: Regioni con servizio "Babysitting"

L’obiettivo è individuare tutte le **regioni** in cui è attivo il servizio di **babysitting** offerto dai servizi sociali. La relazione di partenza è `SERVIZI_SOCIALI`, contenente l’attributo `SERVIZIO`.

**Procedura chiave**:
1. Applicare la selezione per isolare le tuple con `SERVIZIO = 'Babysitting'`:
   ```
   σ_SERVIZIO='Babysitting'(SERVIZI_SOCIALI)
   ```
2. Eseguire il join con la relazione `POSIZIONE` sulla corrispondenza tra città:
   ```
   SERVIZI_SOCIALI ⋈_{SERVIZI_SOCIALI.Citta = POSIZIONE.Citta} POSIZIONE
   ```
3. Proiettare l’attributo `Regione` per ottenere il risultato finale:
   ```
   π_Regione(risultato)
   ```

✦ **Nota esami**: l’uso di **self‑join** e di **proiezione** è ricorrente nelle prove di Algebra Relazionale & SQL (appello 24‑06‑2024).

## Esercizio 2: Città con almeno due servizi

In questo caso si tratta di trovare le **città** che offrono almeno due servizi distinti.

**Procedura chiave**:
1. Creare due alias della stessa relazione per eseguire un self‑join:
   ```
   S1 = SERVIZI_SOCIALI
   S2 = SERVIZI_SOCIALI
   ```
2. Eseguire il join con condizione sui servizi differenti ma stessa città:
   ```
   S = S1 ⋈_{S1.Citta = S2.Citta ∧ S1.Servizio <> S2.Servizio} S2
   ```
3. Proiettare l’attributo `Citta` per ottenere la lista finale:
   ```
   π_Citta(S)
   ```

✦ **Nota esami**: il self‑join con condizione supplementare e proiezione compare nell’appello del 17‑07‑2024.

## Esercizio 3: Città con al più un servizio

L’obiettivo è identificare le città in cui è offerto **al massimo un servizio**.

**Procedura chiave**:
1. Definire due alias della relazione:
   ```
   S1 = SERVIZI_SOCIALI
   S2 = SERVIZI_SOCIALI
   ```
2. Generare l’insieme delle città con più di un servizio:
   ```
   U = S1 ⋈_{S1.Citta = S2.Citta ∧ S1.Servizio <> S2.Servizio} S2
   ```
3. Calcolare la differenza tra tutte le città e quelle con più servizi:
   ```
   π_Citta(S1) − π_Citta(U)
   ```

✦ **Nota esami**: differenza di insiemi e self‑join sono richiesti in Algebra Relazionale & SQL (appello 26‑08‑2024).

## Esercizio 4: Minima spesa babysitting in città ≥200000 abitanti

Lo scopo è trovare le città con **popolazione** di almeno 200000 abitanti in cui il costo del servizio di babysitting è **minimo**.

**Procedura chiave**:
1. Selezionare le città con popolazione ≥200000 e unire con i servizi:
   ```
   T = σ_Abitanti >= 200000(POSIZIONE) ⋈ SERVIZI_SOCIALI
   ```
2. Creare due alias per confrontare i costi:
   ```
   S1 = π_Citta,Spesa(T)
   S2 = π_Citta,Spesa(T)
   ```
3. Sottrarre le coppie con costo maggiore per isolare il minimo:
   ```
   π_Citta(S1) − π_Citta(S1 ⋈_{S1.Citta = S2.Citta ∧ S1.Spesa > S2.Spesa} S2)
   ```

✦ **Nota esami**: self‑join e operazione di differenza per identificare il minimo appaiono nell’appello del 12‑09‑2024.

## Esercizio 5: Città con esattamente un servizio nel 2022

Infine, si richiede l’elenco delle città che hanno offerto **esattamente un servizio** nell’anno 2022.

**Procedura chiave**:
1. Filtrare i record relativi all’anno 2022:
   ```
   U = σ_Anno = 2022(SERVIZI_SOCIALI)
   ```
2. Trovare le città con più di un servizio:
   ```
   V = U ⋈_{U.Citta = U2.Citta ∧ U.Servizio <> U2.Servizio} U (alias U2)
   ```
3. Calcolare la differenza per ottenere quelle con un solo servizio:
   ```
   π_Citta(U) − π_Citta(V)
   ```

✦ **Nota esami**: combinazione di filtro e self‑join, ricorrente in diverse versioni degli esami passati.


---

# Esercitazione Algebra Relazionale

## Esercizio 1: Proiezioni e Cardinalità

In questo esercizio l’obiettivo è comprendere come la **proiezione** influisca sulla **cardinalità** di una relazione in base alle sue **chiavi**. Data la relazione R(A, B, C, D, E):

- Una **chiave** di R è un insieme di attributi che garantisce l’unicità di ogni tupla.
- Per ogni sottoinsieme di attributi X applicato con l’operatore di proiezione π_X, se X contiene una **chiave** di R, allora il numero di tuple rimane invariato: |π_X(R)| = |R|. In caso contrario, |π_X(R)| ≤ |R|, poiché potrebbero essere eliminate tuple duplicate.
- Il compito richiede di identificare tutte le chiavi di R e di confrontare i vari insiemi X per determinare l’effetto sulla cardinalità.

✦ **Nota esami**: i concetti di chiave e proiezione compaiono frequentemente nelle prove di Algebra Relazionale & SQL.

## Esercizio 2: Join e Stima della Cardinalità

In questa prova si analizza il comportamento della **cardinalità** nel **join** tra due relazioni, distinguendo il caso di **integrità referenziale** da quello senza vincoli.

- Consideriamo R1(A, B, C) con |R1| = N1 e R2(D, E, F) con |R2| = N2, sapendo che C è **foreign key** verso D, che è **primary key** di R2.
- Quando si esegue il join `R1 ⋈ R2` sulle condizioni `C = D`, la cardinalità del risultato è pari a N1, poiché ogni tupla di R1 trova esattamente una corrispondenza.
- Invece, per join su attributi non vincolati (ad esempio `A = D` o `B = E`), l’intervallo possibile di cardinalità varia da 0 a `min(N1, N2)`.

✦ **Nota esami**: la stima della cardinalità in presenza o assenza di vincoli è tema ricorrente.

## Schema: FORNITORI, PEZZI e CATALOGO

```sql
FORNITORI(
    fid,
    fnome,
    indirizzo
)
PEZZI(
    pid,
    pnome,
    colore
)
CATALOGO(
    fid,
    pid,
    costo
)
```

## Esercizio 3.1: Nomi Fornitori di "Pezzi Rossi"

Per ottenere i **nomi** dei fornitori che offrono pezzi di colore rosso, si procede in tre fasi:

```sql
σ_colore='rosso'(PEZZI)
```
```sql
SERVIZI_ROSSI ⋈ CATALOGO
```
```sql
π_fnome(SERVIZI_ROSSI ⋈ CATALOGO)
```

✦ **Nota esami**: self‑join e proiezione appaiono in Algebra Relazionale & SQL.

## Esercizio 3.2: FID di Fornitori di "PezzoRosso" o "PezzoVerde"

```sql
T1 = σ_colore='rosso'(PEZZI)
T2 = σ_colore='verde'(PEZZI)
T = T1 ∪ T2
π_fid(T ⋈ CATALOGO)
```

✦ **Nota esami**: l’unione per gestire condizioni OR è un pattern comune.

## Esercizio 3.3: FID di Fornitori Rossi o Localizzati in "Via Cavour"

```sql
U1 = π_fid(σ_colore='rosso'(PEZZI) ⋈ CATALOGO)
U2 = π_fid(σ_indirizzo LIKE '%Via Cavour%'(FORNITORI))
U = U1 ∪ U2
```

## Esercizio 3.4: Fornitori che Forniscono sia Rossi che Verdi

```sql
T1 = π_fid(σ_colore='rosso'(PEZZI) ⋈ CATALOGO)
T2 = π_fid(σ_colore='verde'(PEZZI) ⋈ CATALOGO)
T = T1 ∩ T2
```

✦ **Nota esami**: intersezione e proiezione sono richieste in query avanzate.

## Esercizio 3.5: Coppie di Fornitori con Costo Comparativo

```sql
C1 = CATALOGO AS C1(fid1, pid, c1)
C2 = CATALOGO AS C2(fid2, pid, c2)
C1 ⋈_ (C1.pid = C2.pid AND C1.costo > C2.costo) C2
π_fid1, fid2
```

## Esercizio 3.6: PID Forniti da ≥2 Fornitori

```sql
SELF_JOIN = CATALOGO AS C1
    ⋈_ (C1.pid = C2.pid AND C1.fid <> C2.fid) CATALOGO AS C2
π_pid(SELF_JOIN)
```

## Esercizio 3.7: PID dei Pezzi Più Costosi Forniti da "UniPd"

```sql
U = σ_fnome='UniPd'(FORNITORI)
TC = U ⋈ CATALOGO
MOST_EXPENSIVE = π_pid(TC)
    - π_pid(TC AS T1
        ⋈_ (T1.pid = TC.pid AND T1.costo < TC.costo) TC AS T2)
```

## Esercizio 4: Query su IMPIEGATO-DIPARTIMENTO

```sql
IMPIEGATO(
    Matricola,
    Cognome,
    Stipendio,
    Dipartimento
)
DIPARTIMENTO(
    Codice,
    Nome,
    Sede,
    Direttore
)
```

### 4.1 Cognomi di Impiegati Non Direttori

```sql
D = π_Cognome(
    σ_Matricola = Codice(DIPARTIMENTO)
    ⋈ IMPIEGATO
)
ALL = π_Cognome(IMPIEGATO)
RESULT = ALL - D
```

### 4.2 Nomi di Dipartimenti con Impiegati > 60000

```sql
H = σ_Stipendio > 60000(IMPIEGATO)
D = H ⋈_ (Dipartimento = Codice) DIPARTIMENTO
π_Nome(D)
```

✦ **Nota esami**: differenza, join e selezione combinate sono elementi fondamentali nelle prove di Algebra Relazionale.


---

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


---

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


---

# Progettazione Concettuale

## Fasi di progettazione di un database

La **progettazione concettuale** rappresenta il primo passo nel ciclo di vita di un database: in questa fase si definisce **che cosa** il sistema deve rappresentare, a prescindere dalle soluzioni tecniche. Successivamente, lo schema concettuale viene tradotto nello **schema logico**, in cui si specificano strutture di tabelle e relazioni, e infine nello **schema fisico**, che dettaglia aspetti come indici, partizionamento e modalità di memorizzazione.

## Analisi dei requisiti

L’analisi dei requisiti costituisce la base per un modello solido: attraverso **interviste** con gli stakeholder, l’esame di documenti esistenti, normative e modulistica, si raccolgono informazioni essenziali. È fondamentale mantenere un livello di astrazione uniforme, utilizzare frasi standard per descrivere i concetti e costruire un **glossario** per gestire omonimi e sinonimi. Esplicitare i riferimenti e riorganizzare i concetti in cluster tematici aiuta a evitare fraintendimenti sin dalle prime bozze.

## Costrutti Entità-Relazione

Il modello **Entità-Relazione** si basa su tre costrutti principali: le **entità**, che rappresentano oggetti con esistenza autonoma e proprietà significative; gli **attributi**, che descrivono le caratteristiche di ogni entità; e le **relazioni**, che collegano tra loro i concetti coinvolti. Le **generalizzazioni** (o specializzazioni) permettono di modellare tipologie di entità più specifiche, ereditarie da un concetto più generico.

## Pattern di modellazione

Durante la modellazione possono emergere strutture complesse, come attributi multivalore o relazioni n-arie. In questi casi si ricorre alla **reificazione**, scomponendo gli attributi o le relazioni in nuove entità collegate da relazioni associative. Per gestire la validità temporale si introduce uno **storico** dei cambiamenti, definendo attributi di data inizio e fine. L’evoluzione degli stati di un concetto, ad esempio lo stato di approvazione di un progetto, viene rappresentata tramite generalizzazioni che descrivono le possibili transizioni.

## Strategie di progettazione

Esistono diverse strategie: l’approccio **top-down** parte da uno schema globale che viene poi dettagliato iterativamente; il **bottom-up** integra sottoschemi derivanti da specifiche funzionali; l’**inside-out** unisce i vantaggi di entrambi, focalizzandosi su parti critiche e poi espandendo il modello. Le operazioni di raffinamento includono la decomposizione di entità complesse, l’integrazione di modelli sovrapposti e ripetuti cicli di validazione e revisione.

## Metodologia e qualità dello schema

Una metodologia efficace prevede quattro passi: analisi dei requisiti, creazione di uno schema “scheletro”, raffinamenti iterativi e analisi della qualità finale. La qualità di uno schema si valuta in termini di **correttezza** (allineamento tra modello e requisiti), **completezza** (copertura di tutti i casi d’uso), **leggibilità** (posizionamento chiaro di entità e relazioni) e **minimalità**, evitando generalizzazioni o attributi superflui che possono complicare la manutenzione.

---

✦ **Nota esami**: la modellazione ER comparsa negli appelli del 24‑06‑2024 e del 17‑07‑2024 evidenzia l’importanza di padroneggiare questi concetti.

---

# Esercizi Progettazione Concettuale

## Esercizio 1: Serra PianteBellissime

L’obiettivo di questo esercizio è modellare la gestione di una serra denominata **PianteBellissime** attraverso un **diagramma ER** che rappresenti entità e relazioni fondamentali. Le entità coinvolte includono la **PiantaAltoFusto** (identificata da codice, specie e nome botanico, con attributi quali età, clima ideale e tipo di terriccio), la **PiantaFiorita** (caratterizzata dal nome botanico, dal periodo e dalla durata di fioritura, nonché dalla quantità disponibile e dal costo unitario), il **Terriccio**, i **Clienti** (distinti in sottotipi Privato e Negozianti con attributi aggiuntivi quali nome, cognome e codice fiscale), la **Vendita** e le associazioni **DettaglioFiorite** e **DettaglioAltoFusto** per rappresentare quantità e prezzo di vendita.

### Procedura

1. Definire le entità e annotare i relativi **attributi chiave** per ciascuna, distinguendo i sottotipi di Cliente in Privato e Negozianti.  
2. Stabilire le relazioni associative: impostare la relazione **Trattamento** tra PiantaAltoFusto e Terriccio, nonché le relazioni **AcquistoFiorite** e **AcquistoAltoFusto** tra Vendita e le entità delle piante.  
3. Rappresentare la **generalizzazione** Cliente → {Privato, Negozianti} per modellare i sottotipi e le loro proprietà specifiche.  
4. Esplicitare i **vincoli non ER-esprimibili**, come il fatto che la quantità disponibile in PiantaFiorita non possa essere negativa, che il prezzo di vendita vari in funzione del contesto e che i dati relativi ai Negozianti siano obbligatori solo per tale sottotipo.

✦ **Nota esami**: la modellazione di sottotipi e la definizione di vincoli temporali o di contesto ricorrono frequentemente negli esercizi di progettazione concettuale (Appelli 24-06-2024, 17-07-2024).  

## Esercizio 2: Gestione Eventi Fiera

In questo scenario, si richiede di progettare un modello concettuale per la gestione degli **eventi** in una fiera, includendo entità quali Evento, Padiglione, Espositore, Sessione, Relazione e Partecipante, quest’ultimo suddiviso in Speaker e Pagante, con l’obbligo del biglietto per i partecipanti paganti.

### Procedura

1. Identificare le entità principali e definire per ciascuna gli **attributi essenziali** (ad esempio nome, durata e sito web per Evento; codice e dimensione per Padiglione; dati di contatto per Espositore; titolo e orario per Sessione; titolo e speaker per Relazione).  
2. Modellare le relazioni chiave: **Occupa** (Evento–Padiglione con attributo giorno), **Espone** (Espositore–Evento–Padiglione), **Organizza** (Sessione–Padiglione), **Presenta** (Speaker–Relazione–Sessione) e **Iscrive** (Partecipante–Evento).  
3. Distinguere i sottotipi di Partecipante in Speaker e Pagante, assicurando l’attributo **biglietto** per quest’ultimo con id e costo.  
4. Specificare i **vincoli non ER-esprimibili**, come l’obbligo di consentire due relazioni con lo stesso titolo solo se collocate in sessioni diverse, la necessità del pagamento per i Paganti e la molteplicità 1:N in Occupa per eventi che si svolgono in giorni multipli.

✦ **Nota esami**: gli schemi n-ary e la gestione di sottotipi sono argomenti chiave nelle prove di progettazione (Appello 17-07-2024).  

## Esercizio 3: Procedimenti Sanzionatori

Questo esercizio richiede di modellare l’intero processo dei **procedimenti sanzionatori** per esercizi commerciali, integrando informazioni su Indagine, Edizione, Soggetto (con sottotipi PersonaFisica, Impresa e UnitàLocale), Procedimento e Documento.

### Procedura

1. Rilevare le entità e definirne gli **attributi univoci**: Indagine (nome, frequenza), Edizione (codice edizione, data inizio e fine), Soggetto (CF o PIVA e indirizzo), Procedimento (ID, date di inizio, esito e archiviazione) e Documento (ID, nome, tipo e data di produzione).  
2. Modellare le relazioni: **Avvia** (tra Edizione e Procedimento), **Riferisce** (tra Procedimento e Documento) e **Parte** (tra Impresa e UnitàLocale).  
3. Introdurre la generalizzazione di Soggetto in PersonaFisica, Impresa e UnitàLocale, esplicitando le differenze di chiavi e attributi.  
4. Definire i **vincoli non ER-esprimibili**, tra cui il vincolo di sequenza temporale per cui una diffida deve precedere una sanzione, la distinzione tra CF e PIVA per le imprese, e il legame obbligatorio tra soggetto locale e impresa centrale.

✦ **Nota esami**: la modellazione di vincoli temporali e generalizzazioni complesse è centrale nelle prove più avanzate (Appello 26-08-2024).  


---

# Progettazione Logica

## Obiettivo e fasi di progettazione logica

La **progettazione logica** ha il compito di tradurre lo **schema concettuale** basato sui diagrammi Entità-Relazione in uno **schema logico relazionale**, definendo esattamente quali dati verranno memorizzati e come. Questo processo distingue chiaramente il “CHE COSA” dai dati (lo schema concettuale) dal “COME” tali dati verranno strutturati a livello di tabelle e chiavi. Le fasi principali del processo sono tre:
1. **Ristrutturazione** dello schema E-R per adattare concetti come generalizzazioni e relazioni n-arie alla forma relazionale.
2. **Selezione** dello schema logico più adatto, decidendo quali entità e relazioni tradurre in tabelle e come rappresentare eventuali associazioni.
3. **Ottimizzazione** delle prestazioni attraverso l’analisi di fattori quali vincoli, ridondanze e possibili impatti sulle operazioni di lettura e scrittura.

## Analisi delle ridondanze

Durante la traduzione, è fondamentale individuare eventuali **ridondanze**, ossia informazioni duplicabili da altri dati. Pur essendo talvolta utili per semplificare alcune query, le ridondanze provocano anomalie di aggiornamento e aumentano i costi di memorizzazione. Per gestirle efficacemente, si procede con una metodologia in tre passi:
1. Identificazione degli **attributi** o delle **relazioni** ridondanti tramite l’analisi delle frequenze di lettura e scrittura.
2. Valutazione del **trade-off** tra semplicità delle interrogazioni e costi di aggiornamento dei dati.
3. Decisione su **mantenere** o **eliminare** la ridondanza, bilanciando efficienza operativa e integrità.

## Eliminazione delle generalizzazioni

Il **modello relazionale** non supporta direttamente le generalizzazioni tipiche del diagramma E-R. Le principali strategie per tradurle sono tre:
1. Accorpare le entità specializzate nel **genitore**, introducendo attributi nullable per le proprietà specifiche.
2. Distribuire gli attributi dell’entità genitore nelle entità figlie nei casi di generalizzazione totale.
3. Introdurre una **tabella associativa** che rappresenti esplicitamente l’ereditarietà tra genitore e specializzazioni.

La scelta tra queste opzioni dipende dai pattern di accesso ai dati e dai vincoli di integrità richiesti dall’applicazione.

## Partizionamento e accorpamento di entità e relazioni

Per ottimizzare l’accesso ai dati, è spesso utile eseguire un **partizionamento verticale**, separando attributi frequentemente utilizzati insieme da quelli meno critici, oppure un **accorpamento** di entità e relazioni strettamente correlate per ridurre il numero di join. Questa analisi si basa sulla frequenza di accesso e sulle esigenze di coerenza, con l’obiettivo di minimizzare tuple nulle e join costosi.

## Scelta delle chiavi primarie

La definizione della **chiave primaria** è cruciale per garantire l’unicità e l’efficienza delle operazioni. I criteri principali includono semplicità, completezza (assenza di valori nulli) e frequenza di utilizzo nelle query. Qualora non esistano attributi naturali idonei, si possono introdurre **surrogate key** opportunamente codificate.

## Traduzione di entità e relazioni nel modello relazionale

La traduzione segue regole consolidate: un’entità diventa una **tabella** con gli attributi definiti e la chiave primaria corrispondente. Nelle relazioni **1:N**, la **foreign key** dell’entità lato 1 viene inserita nella tabella del lato N; per le relazioni **M:N**, si crea una **tabella associativa** contenente le chiavi esterne di entrambe le entità.

## Chiavi esterne e integrità referenziale

Le **foreign key** garantiscono il rispetto della **coerenza referenziale** tra tabelle. Le azioni di update e delete possono essere gestite tramite opzioni quali **CASCADE**, **SET NULL** o **NO ACTION**, a seconda dei requisiti di integrità e delle regole di business.

## Naming e vincoli di cardinalità

Una convenzione di **naming** chiara e descrittiva facilita la manutenzione del database nel tempo. I vincoli di cardinalità (minima e massima) si esprimono implicitamente tramite la **nullability** degli attributi e le chiavi primarie; per vincoli più complessi, si possono utilizzare **CHECK** a livello di tabella.

---

✦ **Nota esami**: la capacità di tradurre diagrammi ER in schemi relazionali ottimizzati è frequentemente verificata negli appelli, rendendo indispensabile la padronanza di queste strategie.


---

# Normalizzazione

## Forme Normali e Normalizzazione

Le **Forme Normali** rappresentano criteri di qualità per uno schema relazionale, volte a prevenire anomalie come inserimenti, cancellazioni o aggiornamenti indesiderati. La **normalizzazione** è il processo che trasforma iterativamente uno schema per soddisfare progressivamente queste forme normali, garantendo un’organizzazione dei dati più robusta e priva di ridondanze inutili.

## Anomalie nelle Basi di Dati

In uno schema non normalizzato si possono verificare tre tipologie di anomalie:
- **Anomalia di aggiornamento**, quando una singola modifica richiede l’aggiornamento di più tuple ridondanti.
- **Anomalia di cancellazione**, in cui l’eliminazione di una tupla provoca la perdita di informazioni correlate ma distinte.
- **Anomalia di inserimento**, che impedisce l’aggiunta di nuove entità in assenza di dati fittizi.

La normalizzazione mira a eliminare questi difetti, migliorando coerenza e manutenibilità.

## Dipendenze Funzionali

Una **Dipendenza Funzionale (FD)** X→Y in una relazione R garantisce che, se due tuple concordano su X, debbano coerentemente concordare su Y. Le FD possono essere di diverso tipo:
- **FD banali**, quando Y è sottinsieme di X.
- FD ordinarie che modellano regole come “Impiegato→Stipendio” o “Progetto→Bilancio”.
✦ **Nota esami**: identificazione delle FD e delle chiavi candidate è fondamentale, come verificato nell’appello del 24‑06‑2024.

## Chiavi e FD “Buone”

Una FD X→Y è definita **buona** se X contiene una superchiave, assicurando che non introduca anomalie. La ricerca delle chiavi candidate passa attraverso il calcolo delle chiusure degli attributi rispetto all’insieme di FD.

## Boyce-Codd Normal Form (BCNF)

La **BCNF** impone che per ogni FD non banale X→Y, X sia una superchiave. Se una FD viola questa condizione, lo schema deve essere decomposto in relazioni che soddisfino BCNF, garantendo la rimozione di ridondanze e dipendenze indesiderate.

## Decomposizioni

Una decomposizione è **senza perdita** se la join delle relazioni risultanti ricostruisce lo schema originale, condizione verificata quando l’intersezione degli attributi è chiave di almeno una delle nuove relazioni. Inoltre, la **conservazione delle dipendenze** assicura che ogni FD originaria sia rappresentata in uno degli schemi decomposti.

## Terza Forma Normale (3NF)

La **3NF** richiede che per ogni FD non banale X→Y, o X sia superchiave, o ogni attributo di Y faccia parte di una chiave candidata. La procedura di sintesi in 3NF si articola in:

1. Calcolare una **copertura minima** delle FD, eliminando attributi e dipendenze ridondanti.
2. Raggruppare le FD in insiemi con la stessa chiusura.
3. Creare una relazione per ciascun gruppo di FD.
4. Rimuovere eventuali relazioni ridondanti e aggiungere quelle necessarie per mantenere le chiavi mancanti.

✦ **Nota esami**: decomposizione in 3NF di R(A–I) con G={AB→C, AD→GH, BD→EF, A→I} è stata richiesta nell’appello del 12‑09‑2024.

## Implicazione e Chiusura di Attributi

La **chiusura** X⁺ di un insieme di attributi X è l’insieme di tutti gli attributi determinabili da X mediante le FD. Il calcolo avviene iterativamente, aggiungendo ogni attributo Y quando esiste una FD Z→Y con Z ⊆ X⁺.

## Coperture Ridotte di FD

Una **copertura ridotta** è un insieme di FD non ridondanti e con primi membri minimi. Si ottiene decomponendo le dipendenze con più attributi sul lato destro e rimuovendo quelle che non contribuiscono all’implicazione complessiva.

## Qualità delle Decomposizioni

Una decomposizione ottimale deve essere:
- **Senza perdita**, per ricostruire il database originale.
- **Conservativa**, per mantenere tutte le FD.
- Garantire che ogni relazione risultante rispetti le forme normali desiderate.

## Normalizzazione nella Progettazione

La normalizzazione non è solo teoria, ma assume un ruolo pratico nella progettazione dei database, dove aiuta a:
- Verificare la correttezza degli schemi concettuali.
- Ottimizzare la struttura logica.
- Ridurre i costi di manutenzione e migliorare le prestazioni complessive.


---

# Esercizi Normalizzazione

✦ Documento di riferimento: **Esercitazione Normalizzazione** (Prof. de Leoni) fileciteturn16file0

## Esercizio 1: BCNF su R(A, B, C, D)

In questo esercizio si verifica la conformità a **BCNF** (Boyce‑Codd Normal Form) per lo schema R(A, B, C, D) dato l’insieme di **dipendenze funzionali** F = {C→D, C→A, B→C}.  

**Procedura**:
1. **Calcolo delle chiavi candidate**:  
   - Calcolare la chiusura di B: B⁺ = {B, C, A, D} ⇒ **B** è chiave candidata.  
   - Calcolare la chiusura di C: C⁺ = {C, A, D} (non include B) ⇒ **C** non è chiave.
2. **Individuazione delle FD violanti BCNF**:  
   - Una FD X→Y viola BCNF se X non è superchiave.  
   - Qui, C→D e C→A violano BCNF perché C non è superchiave.
3. **Decomposizione in BCNF**:  
   1. Da C→D si crea R₁(C, D) e il rimanente R'(A, B, C).  
   2. Su R' applicare C→A: genera R₂(C, A) e R₃(B, C).  
   3. Lo schema finale in BCNF è composto dalle relazioni **R₁(C, D)**, **R₂(C, A)** e **R₃(B, C)**.

## Esercizio 2: Decomposizione in 3NF di R(E, N, L, C, S, D, M, P, A)

Lo scopo è normalizzare lo schema R(E, N, L, C, S, D, M, P, A) in **Terza Forma Normale (3NF)** per F = {E→NS, NL→EMD, EN→LCD, C→S, D→M, M→D, EPD→A, NLCP→A}.

**Procedura in 3 passi**:
1. **Espansione delle FD**:  
   - Ogni FD con **RHS** multiplo X→YZ viene suddivisa in X→Y e X→Z.
2. **Rimozione di attributi ridondanti nel LHS**:  
   - Per ciascuna FD, verificare se rimuovendo un attributo dalla parte sinistra la FD rimane implicata; in tal caso, eliminare l’attributo.
3. **Eliminazione di FD ridondanti**:  
   - Testare ogni FD: se può essere dedotta da altre, eliminarla.  
   → Si ottiene una **copertura ridotta** G:
   ```
   E→N, E→S, NL→E, NL→M, NL→D,
   E→L, E→C, E→D, C→S, D→M,
   M→D, EP→A, NLP→A
   ```
4. **Calcolo delle chiusure per chiavi**:  
   - NLP⁺ = {N, L, P, A, E, D, C, S, M} ⇒ **NLP** è chiave.  
   - EP⁺ = {E, P, A, D, C, S, M, N, L} ⇒ **EP** è chiave.
5. **Sintesi dello schema 3NF**:  
   1. Raggruppare le FD di G con la stessa chiusura e creare una relazione per ciascun gruppo:  
      - R₁(E, N, S, L, C, D)  
      - R₂(N, L, E, M, D)  
      - R₃(C, S)  
      - R₄(D, M)  
      - R₅(M, D)  
      - R₆(E, P, A)  
      - R₇(N, L, P, A)  
   2. Rimuovere eventuali relazioni completamente ridondanti (sottoinsiemi).  
   3. Aggiungere relazioni per garantire la presenza di tutte le chiavi, se necessario (ad esempio R_key1(EP), R_key2(NLP)).

## Esercizio 3: 3NF e verifica BCNF su R(A, B, C, D, E, F)

Per lo schema R(A, B, C, D, E, F) con F = {CE→A, C→D, A→B, D→BE, B→F, AD→CF}, si richiede la normalizzazione in 3NF e l’eventuale verifica di BCNF.

**Passaggi chiave**:
1. **Copertura ridotta**:  
   - Trasformare F in una copertura con FD a singolo attributo sul RHS:  
     C→A, C→D, A→B, D→B, D→E, B→F, AD→C.
2. **Individuazione chiavi candidate**:  
   - C⁺ = {C, A, D, B, E, F} ⇒ **C** è chiave.  
   - AD⁺ = {A, D, C, B, E, F} ⇒ **AD** è chiave.
3. **Identificazione FD che violano 3NF**:  
   - FD non banali X→Y in cui X non è superchiave e Y non fa parte di una chiave:  
     A→B, D→B, D→E, B→F.
4. **Creazione dello schema 3NF**:  
   - R₁(C, A, D) con chiavi {C, AD}  
   - R₂(A, B) con chiave A  
   - R₃(D, B, E) con chiave D  
   - R₄(B, F) con chiave B
5. **Verifica BCNF**:  
   - In ciascuna relazione risultante, ogni FD ha parte sinistra superchiave ⇒ lo schema è in BCNF.

## Esercizio 4: 3NF su R(A, B, C, D, E, F, G)

L’ultimo esercizio normalizza lo schema R(A, B, C, D, E, F, G) con F = {AF→BE, EF→BCD, A→F, B→C}.

**Procedura**:
1. **Copertura ridotta**:  
   - Scomporre il RHS multiplo:  
     A→B, A→E, A→F, EF→B, EF→D, B→C.
2. **Determinazione chiavi candidate**:  
   - A⁺ = {A, B, E, F, C, D}  
   - A unito a G (AG) copre tutti gli attributi ⇒ chiavi candidate: **A**, **G**.
3. **Individuazione FD che violano 3NF**:  
   - EF→B, EF→D e B→C poiché X non è superchiave e Y non parte di chiave.
4. **Sintesi dello schema 3NF**:  
   1. Gruppi di FD: {A→B, A→E, A→F}, {EF→B, EF→D}, {B→C}  
   2. Relazioni risultanti:  
      - R₁(A, B, E, F)  
      - R₂(E, F, B, D)  
      - R₃(B, C)  
   3. Aggiungere R₄(G) per rappresentare la chiave G isolata.

---

✦ **Nota esami**: queste procedure di decomposizione in 3NF e BCNF sono fondamentali nelle prove di **normalizzazione** (Appelli vari). fileciteturn36file0


---

# Esercitazione Laboratorio PostgreSQL e libpq

## Connessione al Database

Per stabilire una **connessione** a un database PostgreSQL si utilizza la funzione **PQconnectdb**, che accetta una stringa di connessione (connInfo) o un URI. La gestione degli errori è fondamentale per garantire che eventuali problemi vengano individuati immediatamente.

```c
PGconn *conn = PQconnectdb("host=localhost port=5432 dbname=esame user=utente password=segreta");
if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connessione fallita: %s", PQerrorMessage(conn));
    PQfinish(conn);
    exit(1);
}
```

Dopo aver utilizzato il database, la connessione va chiusa con **PQfinish(conn)**.

## Esecuzione di Comandi

Per inviare comandi **DDL/DML** (come CREATE, INSERT, SELECT) si utilizza **PQexec**. Il codice controlla lo stato del risultato tramite **PQresultStatus**:

```c
PGresult *res = PQexec(conn, "CREATE TABLE prova(id SERIAL PRIMARY KEY, nome TEXT);");
if (PQresultStatus(res) != PGRES_COMMAND_OK) {
    fprintf(stderr, "Errore creazione tabella: %s", PQerrorMessage(conn));
}
PQclear(res);
```

## Recupero dei Risultati

Quando la query restituisce tuple, si ottiene il numero di righe e di colonne con **PQntuples** e **PQnfields**, quindi si scorre il risultato con **PQgetvalue**:

```c
PGresult *res = PQexec(conn, "SELECT id, nome FROM prova;");
int rows = PQntuples(res);
int cols = PQnfields(res);
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        printf("%s	", PQgetvalue(res, i, j));
    }
    printf("
");
}
PQclear(res);
```

## Pulizia delle Risorse

È essenziale liberare la memoria del risultato e chiudere la connessione per evitare **memory leak**:

- **PQclear(res)**: rimuove il PGresult.
- **PQfinish(conn)**: chiude la connessione al DB.

## Iterazione sui Risultati

L’iterazione sui risultati si basa su un **ciclo** che utilizza **PQntuples** per contare le righe. Per ogni tupla, **PQgetvalue** e **PQgetisnull** permettono di leggere i valori e gestire i **NULL**.

## Input da Utente e File

Per leggere parametri da **argv** si impiega la firma **int main(int argc, char *argv[])**, mentre per input da file si usa **fopen**, **fscanf** o **fgets**, con gestione di **EOF** e chiusura con **fclose**.

## Insert tramite libpq

Un esempio di funzione per inserire uno studente con **sprintf**:

```c
void aggiungiStudente(PGconn *conn, const char *nome, int eta) {
    char query[256];
    sprintf(query, "INSERT INTO studenti(nome, eta) VALUES('%s', %d);", nome, eta);
    PGresult *res = PQexec(conn, query);
    PQclear(res);
}
```

## Prepared Statements

Per evitare il parsing ripetuto, si definiscono **prepared statements** con **PQprepare** e si eseguono con **PQexecPrepared**:

```c
PQprepare(conn, "stmt_insert", "INSERT INTO studenti(nome, eta) VALUES($1, $2);", 2, NULL);
const char *params[2] = { "Luca", "23" };
PGresult *res = PQexecPrepared(conn, "stmt_insert", 2, params, NULL, NULL, 0);
PQclear(res);
```

## Best Practice

- Utilizzare **PQfnumber** per recuperare l’indice di una colonna per nome, evitando dipendenza dall’ordine.
- Controllare sempre il risultato di ogni chiamata libpq e liberare le risorse.
- Gestire esplicitamente i casi di **NULL** con **PQgetisnull** e documentare il codice con commenti chiari.


---

# Creazione e Gestione degli Indici

## Il ruolo degli indici

Un indice in un database è una **struttura ausiliaria** che associa a ciascuna **chiave di ricerca** un puntatore alle tuple corrispondenti, con l’obiettivo di migliorare drasticamente le prestazioni delle operazioni di **ricerca** e di **filtro**. Mentre l’accesso diretto su tabelle non indicizzate richiede la scansione completa delle righe, un indice basato su **B+Tree** o su **hash** consente di ridurre il numero di operazioni di I/O necessarie, accelerando query su valori specifici e su intervalli di valori. Tuttavia, l’introduzione di un indice comporta un **overhead** durante le **operazioni di inserimento**, **cancellazione** e **aggiornamento**, oltre a un incremento dello spazio occupato su disco.

## Metriche di valutazione degli indici

Per valutare l’efficacia di un indice è necessario considerare diverse metriche. Il **tempo di accesso** misura quanti passaggi di livello dell’albero o di bucket sono richiesti per individuare una chiave. Il **tempo di inserimento** e di **cancellazione** indica quanto l’indice rallenta le operazioni di aggiornamento rispetto a una tabella non indicizzata. Infine, l’**occupazione di spazio** confronta la dimensione dell’indice con quella della tabella: un indice troppo voluminoso può vanificare i vantaggi prestazionali a causa di costi di I/O aggiuntivi.

## Indice primario vs indice secondario

Un **indice primario** definisce l’ordinamento fisico delle tuple secondo la chiave di ricerca, e ne esiste al massimo uno per tabella. Questo tipo di indice garantisce la massima efficienza per le operazioni che sfruttano la chiave primaria. Al contrario, un **indice secondario** non altera l’ordinamento fisico e può essere creato su uno o più attributi aggiuntivi: esso supporta query non basate sulla chiave primaria, ma richiede un accesso indiretto, con costi maggiori per la navigazione dei nodi.

## Strutture di base: B+Tree e hash

Gli **alberi bilanciati** come i **B+Tree** rappresentano lo standard per gli indici su intervalli di valori: solo i nodi foglia contengono i puntatori alle tuple, e una lista concatenata dei foglia facilita le scansioni in ordine. Le operazioni di **inserimento** possono causare lo **split** di un nodo e propagare le modifiche verso l’alto, mentre le **cancellazioni** possono portare a una **fusione** dei nodi. In alternativa, gli **indici hash** utilizzano una funzione di **hash** per mappare le chiavi in bucket; garantiscono un accesso medio in **O(1)**, ma non supportano in modo efficiente le ricerche per intervallo o l’**ORDER BY**.

## Indici compositi

Un **indice composito** definito su più attributi, ad esempio `(A, B)`, sfrutta un ordinamento lessicografico: è efficace quando una query specifica il primo attributo `A` e, opzionalmente, filtra anche per `B`. Se invece si cerca solo su `B`, l’indice perde di efficienza, poiché non è in grado di sfruttare l’ordinamento sul secondo attributo senza una scansione supplementare.

## Sintassi SQL in PostgreSQL

In PostgreSQL la creazione di un indice avviene con il comando **CREATE INDEX**, specificando il tipo di indice desiderato (`btree` è predefinito, `hash` è supportato solo per indici su singoli attributi). Per rimuovere un indice, si utilizza **DROP INDEX**. Ecco un esempio:

```sql
CREATE UNIQUE INDEX idx_clienti_email
    ON clienti (email)
    USING btree;

DROP INDEX idx_clienti_email;
```

Inoltre, PostgreSQL crea automaticamente un indice `btree` univoco sulle **chiavi primarie**, semplificando la definizione di vincoli di unicità.

---

✦ **Nota esami**: la scelta del tipo di indice più efficiente per una query specifica è un quesito ricorrente nei quiz sugli indici degli appelli (24‑06‑2024 Q3; 17‑07‑2024 Q3; 26‑08‑2024 Q3; 12‑09‑2024 Q1). fileciteturn38file0


---

# Gestione delle Transazioni

## Definizione di Transazione

Una **transazione** rappresenta una sequenza indivisibile di operazioni di lettura e scrittura effettuate sul database: inizia con un comando di avvio, include tutte le istruzioni DML necessarie e termina con un **COMMIT** o un **ROLLBACK**. Il **COMMIT** rende permanenti tutte le modifiche apportate dalla transazione, mentre il **ROLLBACK** annulla ogni cambiamento come se la transazione non fosse mai stata eseguita. Questo garantisce che le operazioni vengano trattate come un’unità atomica, prevenendo stati intermedi incoerenti nel database. fileciteturn19file0turn39file0

## Proprietà ACID

Le transazioni devono rispettare quattro proprietà fondamentali, note come **ACID**, che assicurano correttezza e affidabilità:
1. **Atomicità**: tutte le modifiche vengono applicate interamente o non vengono applicate affatto, grazie ai meccanismi di UNDO in caso di fallimento prima del COMMIT e di REDO per garantire durabilità dopo il COMMIT.  
2. **Consistenza**: al termine della transazione, il database soddisfa tutti i vincoli definiti (chiavi, referenzialità e controlli CHECK).  
3. **Isolamento**: le transazioni concorrenti operano come se venissero eseguite in sequenza, senza vedere gli effetti intermedi di altre transazioni.  
4. **Durabilità**: una volta eseguito il COMMIT, le modifiche resistono anche in caso di caduta del sistema o di guasti hardware. fileciteturn19file0turn39file0

## Log e Ripristino (Recovery)

Il **log** del database funge da diario sequenziale delle operazioni e include voci di inizio transazione, modifiche *before-image* e *after-image*, nonché segnali di COMMIT e ABORT. L’adozione della tecnica **Write-Ahead Logging**, che prevede che le voci di log vengano scritte su memoria stabile prima delle modifiche effettive, garantisce la possibilità di recuperare il database in caso di crash.

Durante un **checkpoint**, il sistema registra lo stato corrente delle transazioni attive e forza la scrittura delle pagine modificate, rendendo più efficiente la fase di recovery. Esistono due modalità principali di ripristino:
1. **Ripresa a caldo (hot recovery)**: dopo un crash, si scorre all’indietro il log per eseguire le operazioni di UNDO sulle transazioni non committate e poi in avanti per effettuare i REDO di quelle committate successive all’ultimo checkpoint.  
2. **Ripresa a freddo (cold recovery)**: si riparte da un backup offline seguito da un warm recovery che applica le voci di log per riportare il database all’ultimo stato consistente. fileciteturn19file0turn39file0

## Anomalie e Controllo della Concorrenza

L’esecuzione concorrente di più transazioni può generare anomalie quali **perdita di aggiornamento**, **lettura sporca**, **letture non ripetibili**, **aggiornamenti fantasma** e **inserimenti fantasma**. Per definire il grado di isolamento e i fenomeni che si vogliono consentire, SQL prevede diversi livelli di isolamento: **READ UNCOMMITTED**, **READ COMMITTED**, **REPEATABLE READ** e **SERIALIZABLE**, ciascuno con un diverso trade‑off tra performance e coerenza.

Uno **schedule** è una sequenza di operazioni intercalate di diverse transazioni. Se esiste uno schedule seriale che produce lo stesso risultato, lo schedule è **serializzabile**. Si distinguono due criteri:
- **Conflict-serializzabilità**, basata sul grafo dei conflitti tra operazioni, che deve essere aciclico.  
- **View-serializzabilità**, focalizzata sulle relazioni di lettura‑scrittura e sull’ordine finale delle scritture. fileciteturn19file0turn39file0

## Locking e Protocollo Two-Phase Locking (2PL)

Per garantire la **serializzabilità** si utilizza il **protocollo Two‑Phase Locking (2PL)**, che prevede una fase crescente di acquisizione dei lock e una fase decrescente di rilascio. I **lock** possono essere **condivisi (S)** per le letture o **esclusivi (X)** per le scritture. Questo schema previene conflitti, ma può causare **deadlock**, risolti mediante politiche di timeout o di ordinamento FIFO per l’attesa dei lock. fileciteturn19file0turn39file0


---

# Esercitazione Gestione delle Transazioni

## Esercizio 1: Ripresa a Freddo (Cold Recovery)

La **ripresa a freddo** consente di riportare il database a uno stato consistente dopo un crash totale, partendo da un backup offline e applicando successivamente le voci di log fino all’ultimo punto di coerenza.

**Procedimento chiave**

1. **Individuazione dell’ultimo checkpoint**  
   - Scorrere il log per identificare l’ultima entry di tipo `CK(T)` che indica il checkpoint.  

2. **Costruzione degli insiemi UNDO e REDO**  
   - Analizzare le voci di log fino al momento del crash:  
     - Se si incontra `COMMIT(T)`, aggiungere la transazione **T** all’insieme **REDO**.  
     - Altrimenti, includerla nell’insieme **UNDO**.  

3. **Fase UNDO**  
   - Percorrere il log all’indietro applicando, per ogni modifica **U(T, operazione, new_value, old_value)** di T ∈ UNDO, l’inversione che ripristina **old_value**.  

4. **Fase REDO**  
   - Scorrere il log in avanti eseguendo per ogni transazione T ∈ REDO le operazioni di **DML** (INSERT, DELETE, UPDATE) per rifissare le modifiche.  

✦ **Nota esami**: la sequenza di procedure per **UNDO/REDO** e la gestione dei checkpoint è frequentemente richiesta nei quiz di ripristino.

## Esercizio 2: Conflict-Serializzabilità

La **conflict-serializzabilità** verifica se uno **schedule** concorrente è equivalente a un’esecuzione seriale, basandosi sulla risoluzione dei **conflitti** tra operazioni di lettura e scrittura.

**Procedimento chiave**

1. **Costruzione del grafo di precedenza**  
   - Creare un nodo per ogni transazione.  
   - Aggiungere un arco **Ti → Tj** se un’operazione di Tj confligge con un’operazione di Ti (read/write o write/write) e avviene dopo.  

2. **Verifica dell’assenza di cicli**  
   - Controllare se il grafo è **aciclico**; in tal caso lo schedule è conflict-serializzabile.  

3. **Ricostruzione dello schedule seriale**  
   - Applicare un **ordinamento topologico** del grafo per ottenere l’ordine seriale equivalente.  

✦ **Nota esami**: la costruzione e l’analisi del grafo di conflitti è un tema ricorrente nei quiz di concorrenza.

## Esercizio 3: Conflict-Serializzabilità (Variante)

Questa variante applica lo stesso approccio del precedente ma parte da uno schedule differente.

**Procedura**

1. Estrarre il **grafo di precedenza** specifico dello schedule dato.  
2. Verificare la **presence** o meno di cicli nel grafo.  
3. Se il grafo è aciclico, eseguire un **topological sort** per ottenere lo schedule seriale equivalente.  

## Esercizio 4: View-Serializzabilità (VSR)

La **view-serializzabilità** considera non solo i conflitti ma anche le dipendenze di lettura‑scrittura e le scritture finali, garantendo che ogni transazione veda gli stessi valori di una versione seriale.

**Procedimento chiave**

1. **Identificare le letture**  
   - Per ogni operazione di lettura **rᵢ(x)** determinare la scrittura **wⱼ(x)** da cui deriva il valore (**read-from**).  

2. **Verificare l’ordine delle operazioni**  
   - Mantenere l’ordine tra scritture multiple su **x** e tra scritture e letture.  

3. **Costruzione del grafo di dipendenze per view**  
   - Inserire archi **Ti → Tj** se è necessario preservare l’ordine `read-from` o l’ordine delle **final writes**.  

4. **Controllo dell’acyclicità**  
   - Se il grafo non contiene cicli, lo schedule è **view-serializzabile**.  

✦ **Nota esami**: la definizione e la verifica di **view-serializzabilità** appaiono spesso nei quiz avanzati di concorrenza.

## Esercizio 5: Classificazione degli Schedule

Questo esercizio richiede di classificare uno schedule tra **Non-serializzabile (NonSR)**, **Conflict-serializzabile (CSR)** o **View-serializzabile (VSR)** e di elencare gli ordini seriali possibili.

**Procedura**

1. **Test di Conflict-Serializzabilità**  
   - Se il grafo di conflitti è aciclico ⇒ **CSR**; calcolare gli ordini tramite topological sort.  

2. **Test di View-Serializzabilità**  
   - In assenza di conflict-serializzabilità, costruire il grafo di view e verificarne l’acyclicità ⇒ **VSR**.  

3. **Verifica Non-Serializzabilità**  
   - Se entrambi i grafi presentano cicli ⇒ **NonSR**.  

4. **Elencare gli ordini seriali**  
   - Generare tutti gli **ordinamenti topologici** possibili del grafo corrispondente alla serializzabilità.  

✦ **Nota esami**: la classificazione completa e la generazione degli ordini seriali è un punto chiave dei quiz di schedulazione.  


---

# Conclusioni del Corso

## Ciclo di vita di un progetto DB

Il **ciclo di vita** di un progetto di database inizia con lo **studio di fattibilità**, che valuta requisiti funzionali e non funzionali, costi e benefici. Successivamente si procede con la **raccolta e analisi dei requisiti**, interagendo con gli stakeholder per definire casi d’uso e regole di business. Nella fase di **progettazione concettuale** si crea lo **schema ER** per rappresentare entità e relazioni. A seguire, la **progettazione logica** traduce questo schema in tabelle relazionali, mentre la **progettazione fisica** definisce indici, partizionamenti e parametri di memorizzazione. Infine, durante la **realizzazione** si implementa il database, si eseguono test di **validazione e collaudo**, e si avvia il **funzionamento in esercizio**, garantendo monitoraggio e manutenzione.

## Prodotti delle fasi

Ogni fase del progetto genera deliverable specifici: lo **schema concettuale ER** formalizza la struttura a livello logico, lo **schema logico relazionale** definisce tabelle, chiavi e vincoli, mentre lo **schema fisico** dettaglia strategie di indicizzazione, partizionamento e configurazioni di storage. A completare la documentazione vi è un manuale operativo che illustra dettagli tecnici e linee guida per l’utilizzo e la manutenzione del database.

## Linguaggi di interrogazione e accesso

Per interagire con il database relazionale si impiega l’**Algebra Relazionale**, che fornisce un approccio astratto al “cosa” richiedere, e **SQL**, il linguaggio standard che comprende istruzioni **DDL** (CREATE, ALTER, DROP) e **DML** (SELECT, INSERT, UPDATE, DELETE). L’accesso da applicazioni si realizza tramite API come **libpq** in C++, che offre funzioni quali **PQconnectdb** per stabilire la connessione, **PQexec** e **PQresultStatus** per eseguire comandi, **PQntuples** e **PQgetvalue** per recuperare dati, e **PQclear** con **PQfinish** per la gestione delle risorse.

## Gestione errori e manutenzione

Durante lo sviluppo e l’esercizio del database, la **diagnosi** e la **riparazione** degli errori richiedono l’analisi di messaggi di log e di errori di sistema. L’utilizzo di strumenti di **troubleshooting**, come la verifica delle query SQL e la revisione dei vincoli, è essenziale per individuare colli di bottiglia, errori di concorrenza o problemi di integrità, e per applicare patch o ottimizzazioni in modo mirato.

## Qualità del progetto: Normalizzazione e Transazioni

La **normalizzazione** in **3NF** e **BCNF** è alla base di schemi privi di ridondanze e di anomalie di inserimento, aggiornamento e cancellazione. Le **transazioni ACID** garantiscono **atomicità**, **consistenza**, **isolamento** e **durabilità**, mentre i meccanismi di **concorrenza** (locking, Two‑Phase Locking) e di **recovery** (UNDO/REDO, checkpoint) assicurano l’affidabilità del sistema anche in presenza di guasti.

## Best practice e consigli finali

Per produrre un database solido, è consigliabile adottare una **naming convention** chiara e coerente per entità, attributi e indici, accompagnata da **documentazione** esaustiva e commenti nel codice SQL. È fondamentale eseguire **test approfonditi**, includendo casi limite, simulazioni di concorrenza e di failure, e valutazioni di **performance** e **sicurezza** per garantire un funzionamento robusto e scalabile nel tempo.
