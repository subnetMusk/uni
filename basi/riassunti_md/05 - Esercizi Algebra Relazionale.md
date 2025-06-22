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
