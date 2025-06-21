# Pasta la Vista

Un progetto C/Multi–SQL per la gestione di una catena di ristoranti, che dimostra la creazione, popolazione e interrogazione di un database PostgreSQL.

---

## Descrizione

Questo tool in C centralizza le informazioni su filiali, personale, clienti, ordini, prenotazioni, piatti e ingredienti.  
Permette di:

- Verificare lo schema e la popolazione del DB (`db/database.sql`).
- Eseguire 10 query di esempio (in `src/queries.h`) e stampare i risultati in formato tabellare.
- Configurare dinamicamente i parametri di connessione tramite prompt da terminale.

---

## Struttura del progetto

```
progetto/
├── db/
│   └── database.sql            # DDL + INSERT per creare e popolare il DB
├── clear_build.sh          # script di pulizia degli artefatti di build
└── src/
    ├── CMakeLists.txt      # configurazione CMake
    ├── main.c              # entrypoint: prompt + esecuzione query
    ├── queries.h           # array di 10 query di esempio
    └── build/              # directory di build (creata automaticamente)
```

---

## Prerequisiti

- **PostgreSQL** in esecuzione (locale o remota).  
- **libpq** (client PostgreSQL) installata.  
- **CMake** ≥ 3.15.  
- **GCC/Clang** o compilatore C compatibile.  
- **bash** (per lo script di pulizia).

---

## Configurazione e build

1. **Genera e compila** (dalla cartella `src`):
   ```bash
   cd progetto/src
   cmake -S . -B build
   cmake --build build
   ```

2. **Esegui** l’applicazione:
   ```bash
   cmake --build build --target run
   ```
   oppure, direttamente:
   ```bash
   ./build/connessione_db
   ```

Durante l’esecuzione verranno richiesti:

- **Host** (es. `localhost`)  
- **Database** (es. `ristorante_db`)  
- **Utente** (es. `postgres`)  
- **Password**

---

## Pulizia degli artefatti

Per rimuovere tutti i file generati da CMake (cartella `src/build/`, Makefile, `CMakeCache.txt`, ecc.) esegui dalla root del progetto:

```bash
chmod +x clear_build.sh
./clear_build.sh
```

---

## Personalizzazione

- Modifica `db/database.sql` per aggiornare schema e dati.  
- Aggiorna `src/queries.h` per sostituire o aggiungere query.  
- Puoi passare una connection string completa come argomento:
  ```bash
  ./build/connessione_db "host=<host> dbname=<nome_db> user=<user> password=<psw>"
  ```
