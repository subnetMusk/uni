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
