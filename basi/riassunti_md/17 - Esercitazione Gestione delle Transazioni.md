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
