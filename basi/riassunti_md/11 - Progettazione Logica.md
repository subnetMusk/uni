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
