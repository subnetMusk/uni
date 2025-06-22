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
