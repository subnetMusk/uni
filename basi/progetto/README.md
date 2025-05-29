# Pasta la Vista

Un progetto C/Multi–SQL che dimostra la creazione, popolazione e interrogazione di una base di dati PostgreSQL per la gestione di una catena di ristoranti.

---

## Descrizione

Questo progetto propone la realizzazione di una base di dati finalizzata a supportare la gestione di una catena di ristoranti. Il sistema centralizza le informazioni relative a:

- **Filiali** e alle loro scorte  
- **Personale** (manager, cuochi, camerieri, capisala)  
- **Clientela**  
- **Ordini** (asporto e domicilio)  
- **Prenotazioni** in loco (sale e tavoli)  
- **Piatti** e relativi **ingredienti**  
- **Fornitori** e relative forniture  

Ogni filiale registra:
- Il numero di coperti disponibili in tempo reale  
- Le prenotazioni associate ai tavoli  
- Il monitoraggio delle scorte di ingredienti per garantire la disponibilità dei piatti  

Ogni ordine:
- È associato a uno o più piatti del menù  
- Riporta data e ora di emissione, cliente e indirizzo di consegna (se applicabile)  

Ogni fornitura:
- È validata dal manager della filiale  
- Contiene uno o più ingredienti in quantità variabile  

---

## Scopo del progetto

- **Verificare** lo schema e la popolazione del database (`db/init.sql`).  
- **Dimostrare** 10 query di esempio (in `src/queries.h`) che coprono operazioni di selezione, filtro, aggregazione e join.  
- **Fornire** uno script C multipiattaforma che, tramite prompt interattivo, si connette al database e stampa i risultati in formato tabellare.  
- **Garantire** portabilità su macOS, Linux e Windows usando CMake e `find_package(PostgreSQL)` senza hard-coding di path.

---

## Struttura del progetto

```
progetto/
├── src/
│   ├── CMakeLists.txt      # configurazione build CMake e target 
│   ├── main.c              # entrypoint: prompt + esecuzione query
│   └── queries.h           # array con le 10 query di esempio
└── db/
    └── init.sql            # DDL + INSERT per creare e popolare il DB
```

---

## Prerequisiti

- **PostgreSQL** in esecuzione (locale o remota).  
- **libpq** (client PostgreSQL) installata.  
- **CMake** ≥ 3.15.  
- **GCC/Clang** o compilatore C compatibile.

---

## Inizializzare il database

1. Avvia PostgreSQL (se non già in esecuzione).  
2. Crea un database di test:
   ```bash
   createdb ristorante_db
   ```  
3. Esegui lo script di setup dalla root del progetto:
   ```bash
   psql -d ristorante_db -f db/init.sql
   ```

---

## Build

```bash
cd src
mkdir -p build && cd build
cmake ..
cmake --build .
```

L’eseguibile generato si chiamerà `connessione_db` (su Windows `connessione_db.exe`).

---

## Uso

```bash
./connessione_db
```

Verrà richiesto:

- **Host** (es. `localhost`)  
- **Database** (es. `ristorante_db`)  
- **Utente** (es. `postgres`)  
- **Password**

Al termine verranno eseguite le 10 query di esempio e mostrati i risultati in tabelle formattate.

---

## Personalizzazione

- Modifica `db/init.sql` per aggiornare schema e dati di test.  
- Aggiorna `src/queries.h` per cambiare o aggiungere query.  
- Puoi anche passare la connection string completa come argomento:
  ```bash
  ./connessione_db "host=localhost dbname=ristorante_db user=postgres password=segreta"
  ```

---

## Licenza

Rilasciato sotto **MIT License**.
