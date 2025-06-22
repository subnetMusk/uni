# Esercitazione Algebra Relazionale

## Esercizio 1: Proiezioni e Cardinalità

In questo esercizio l’obiettivo è comprendere come la **proiezione** influisca sulla **cardinalità** di una relazione in base alle sue **chiavi**. Data la relazione R(A, B, C, D, E):

- Una **chiave** di R è un insieme di attributi che garantisce l’unicità di ogni tupla.
- Per ogni sottoinsieme di attributi X applicato con l’operatore di proiezione π_X, se X contiene una **chiave** di R, allora il numero di tuple rimane invariato: |π_X(R)| = |R|. In caso contrario, |π_X(R)| ≤ |R|, poiché potrebbero essere eliminate tuple duplicate.
- Il compito richiede di identificare tutte le chiavi di R e di confrontare i vari insiemi X per determinare l’effetto sulla cardinalità.

✦ **Nota esami**: i concetti di chiave e proiezione compaiono frequentemente nelle prove di Algebra Relazionale & SQL.

## Esercizio 2: Join e Stima della Cardinalità

In questa prova si analizza il comportamento della **cardinalità** nel **join** tra due relazioni, distinguendo il caso di **integrità referenziale** da quello senza vincoli.

- Consideriamo R1(A, B, C) con |R1| = N1 e R2(D, E, F) con |R2| = N2, sapendo che C è **foreign key** verso D, che è **primary key** di R2.
- Quando si esegue il join `R1 ⋈ R2` sulle condizioni `C = D`, la cardinalità del risultato è pari a N1, poiché ogni tupla di R1 trova esattamente una corrispondenza.
- Invece, per join su attributi non vincolati (ad esempio `A = D` o `B = E`), l’intervallo possibile di cardinalità varia da 0 a `min(N1, N2)`.

✦ **Nota esami**: la stima della cardinalità in presenza o assenza di vincoli è tema ricorrente.

## Schema: FORNITORI, PEZZI e CATALOGO

```sql
FORNITORI(
    fid,
    fnome,
    indirizzo
)
PEZZI(
    pid,
    pnome,
    colore
)
CATALOGO(
    fid,
    pid,
    costo
)
```

## Esercizio 3.1: Nomi Fornitori di "Pezzi Rossi"

Per ottenere i **nomi** dei fornitori che offrono pezzi di colore rosso, si procede in tre fasi:

```sql
σ_colore='rosso'(PEZZI)
```
```sql
SERVIZI_ROSSI ⋈ CATALOGO
```
```sql
π_fnome(SERVIZI_ROSSI ⋈ CATALOGO)
```

✦ **Nota esami**: self‑join e proiezione appaiono in Algebra Relazionale & SQL.

## Esercizio 3.2: FID di Fornitori di "PezzoRosso" o "PezzoVerde"

```sql
T1 = σ_colore='rosso'(PEZZI)
T2 = σ_colore='verde'(PEZZI)
T = T1 ∪ T2
π_fid(T ⋈ CATALOGO)
```

✦ **Nota esami**: l’unione per gestire condizioni OR è un pattern comune.

## Esercizio 3.3: FID di Fornitori Rossi o Localizzati in "Via Cavour"

```sql
U1 = π_fid(σ_colore='rosso'(PEZZI) ⋈ CATALOGO)
U2 = π_fid(σ_indirizzo LIKE '%Via Cavour%'(FORNITORI))
U = U1 ∪ U2
```

## Esercizio 3.4: Fornitori che Forniscono sia Rossi che Verdi

```sql
T1 = π_fid(σ_colore='rosso'(PEZZI) ⋈ CATALOGO)
T2 = π_fid(σ_colore='verde'(PEZZI) ⋈ CATALOGO)
T = T1 ∩ T2
```

✦ **Nota esami**: intersezione e proiezione sono richieste in query avanzate.

## Esercizio 3.5: Coppie di Fornitori con Costo Comparativo

```sql
C1 = CATALOGO AS C1(fid1, pid, c1)
C2 = CATALOGO AS C2(fid2, pid, c2)
C1 ⋈_ (C1.pid = C2.pid AND C1.costo > C2.costo) C2
π_fid1, fid2
```

## Esercizio 3.6: PID Forniti da ≥2 Fornitori

```sql
SELF_JOIN = CATALOGO AS C1
    ⋈_ (C1.pid = C2.pid AND C1.fid <> C2.fid) CATALOGO AS C2
π_pid(SELF_JOIN)
```

## Esercizio 3.7: PID dei Pezzi Più Costosi Forniti da "UniPd"

```sql
U = σ_fnome='UniPd'(FORNITORI)
TC = U ⋈ CATALOGO
MOST_EXPENSIVE = π_pid(TC)
    - π_pid(TC AS T1
        ⋈_ (T1.pid = TC.pid AND T1.costo < TC.costo) TC AS T2)
```

## Esercizio 4: Query su IMPIEGATO-DIPARTIMENTO

```sql
IMPIEGATO(
    Matricola,
    Cognome,
    Stipendio,
    Dipartimento
)
DIPARTIMENTO(
    Codice,
    Nome,
    Sede,
    Direttore
)
```

### 4.1 Cognomi di Impiegati Non Direttori

```sql
D = π_Cognome(
    σ_Matricola = Codice(DIPARTIMENTO)
    ⋈ IMPIEGATO
)
ALL = π_Cognome(IMPIEGATO)
RESULT = ALL - D
```

### 4.2 Nomi di Dipartimenti con Impiegati > 60000

```sql
H = σ_Stipendio > 60000(IMPIEGATO)
D = H ⋈_ (Dipartimento = Codice) DIPARTIMENTO
π_Nome(D)
```

✦ **Nota esami**: differenza, join e selezione combinate sono elementi fondamentali nelle prove di Algebra Relazionale.
