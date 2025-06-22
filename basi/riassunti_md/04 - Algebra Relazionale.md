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
