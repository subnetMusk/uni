# Esercizi Normalizzazione

✦ Documento di riferimento: **Esercitazione Normalizzazione** (Prof. de Leoni) fileciteturn16file0

## Esercizio 1: BCNF su R(A, B, C, D)

In questo esercizio si verifica la conformità a **BCNF** (Boyce‑Codd Normal Form) per lo schema R(A, B, C, D) dato l’insieme di **dipendenze funzionali** F = {C→D, C→A, B→C}.  

**Procedura**:
1. **Calcolo delle chiavi candidate**:  
   - Calcolare la chiusura di B: B⁺ = {B, C, A, D} ⇒ **B** è chiave candidata.  
   - Calcolare la chiusura di C: C⁺ = {C, A, D} (non include B) ⇒ **C** non è chiave.
2. **Individuazione delle FD violanti BCNF**:  
   - Una FD X→Y viola BCNF se X non è superchiave.  
   - Qui, C→D e C→A violano BCNF perché C non è superchiave.
3. **Decomposizione in BCNF**:  
   1. Da C→D si crea R₁(C, D) e il rimanente R'(A, B, C).  
   2. Su R' applicare C→A: genera R₂(C, A) e R₃(B, C).  
   3. Lo schema finale in BCNF è composto dalle relazioni **R₁(C, D)**, **R₂(C, A)** e **R₃(B, C)**.

## Esercizio 2: Decomposizione in 3NF di R(E, N, L, C, S, D, M, P, A)

Lo scopo è normalizzare lo schema R(E, N, L, C, S, D, M, P, A) in **Terza Forma Normale (3NF)** per F = {E→NS, NL→EMD, EN→LCD, C→S, D→M, M→D, EPD→A, NLCP→A}.

**Procedura in 3 passi**:
1. **Espansione delle FD**:  
   - Ogni FD con **RHS** multiplo X→YZ viene suddivisa in X→Y e X→Z.
2. **Rimozione di attributi ridondanti nel LHS**:  
   - Per ciascuna FD, verificare se rimuovendo un attributo dalla parte sinistra la FD rimane implicata; in tal caso, eliminare l’attributo.
3. **Eliminazione di FD ridondanti**:  
   - Testare ogni FD: se può essere dedotta da altre, eliminarla.  
   → Si ottiene una **copertura ridotta** G:
   ```
   E→N, E→S, NL→E, NL→M, NL→D,
   E→L, E→C, E→D, C→S, D→M,
   M→D, EP→A, NLP→A
   ```
4. **Calcolo delle chiusure per chiavi**:  
   - NLP⁺ = {N, L, P, A, E, D, C, S, M} ⇒ **NLP** è chiave.  
   - EP⁺ = {E, P, A, D, C, S, M, N, L} ⇒ **EP** è chiave.
5. **Sintesi dello schema 3NF**:  
   1. Raggruppare le FD di G con la stessa chiusura e creare una relazione per ciascun gruppo:  
      - R₁(E, N, S, L, C, D)  
      - R₂(N, L, E, M, D)  
      - R₃(C, S)  
      - R₄(D, M)  
      - R₅(M, D)  
      - R₆(E, P, A)  
      - R₇(N, L, P, A)  
   2. Rimuovere eventuali relazioni completamente ridondanti (sottoinsiemi).  
   3. Aggiungere relazioni per garantire la presenza di tutte le chiavi, se necessario (ad esempio R_key1(EP), R_key2(NLP)).

## Esercizio 3: 3NF e verifica BCNF su R(A, B, C, D, E, F)

Per lo schema R(A, B, C, D, E, F) con F = {CE→A, C→D, A→B, D→BE, B→F, AD→CF}, si richiede la normalizzazione in 3NF e l’eventuale verifica di BCNF.

**Passaggi chiave**:
1. **Copertura ridotta**:  
   - Trasformare F in una copertura con FD a singolo attributo sul RHS:  
     C→A, C→D, A→B, D→B, D→E, B→F, AD→C.
2. **Individuazione chiavi candidate**:  
   - C⁺ = {C, A, D, B, E, F} ⇒ **C** è chiave.  
   - AD⁺ = {A, D, C, B, E, F} ⇒ **AD** è chiave.
3. **Identificazione FD che violano 3NF**:  
   - FD non banali X→Y in cui X non è superchiave e Y non fa parte di una chiave:  
     A→B, D→B, D→E, B→F.
4. **Creazione dello schema 3NF**:  
   - R₁(C, A, D) con chiavi {C, AD}  
   - R₂(A, B) con chiave A  
   - R₃(D, B, E) con chiave D  
   - R₄(B, F) con chiave B
5. **Verifica BCNF**:  
   - In ciascuna relazione risultante, ogni FD ha parte sinistra superchiave ⇒ lo schema è in BCNF.

## Esercizio 4: 3NF su R(A, B, C, D, E, F, G)

L’ultimo esercizio normalizza lo schema R(A, B, C, D, E, F, G) con F = {AF→BE, EF→BCD, A→F, B→C}.

**Procedura**:
1. **Copertura ridotta**:  
   - Scomporre il RHS multiplo:  
     A→B, A→E, A→F, EF→B, EF→D, B→C.
2. **Determinazione chiavi candidate**:  
   - A⁺ = {A, B, E, F, C, D}  
   - A unito a G (AG) copre tutti gli attributi ⇒ chiavi candidate: **A**, **G**.
3. **Individuazione FD che violano 3NF**:  
   - EF→B, EF→D e B→C poiché X non è superchiave e Y non parte di chiave.
4. **Sintesi dello schema 3NF**:  
   1. Gruppi di FD: {A→B, A→E, A→F}, {EF→B, EF→D}, {B→C}  
   2. Relazioni risultanti:  
      - R₁(A, B, E, F)  
      - R₂(E, F, B, D)  
      - R₃(B, C)  
   3. Aggiungere R₄(G) per rappresentare la chiave G isolata.

---

✦ **Nota esami**: queste procedure di decomposizione in 3NF e BCNF sono fondamentali nelle prove di **normalizzazione** (Appelli vari). fileciteturn36file0
