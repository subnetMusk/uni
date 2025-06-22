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