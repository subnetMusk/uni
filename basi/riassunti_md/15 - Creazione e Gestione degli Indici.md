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
