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