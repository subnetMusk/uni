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
