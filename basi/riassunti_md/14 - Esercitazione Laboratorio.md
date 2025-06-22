# Esercitazione Laboratorio PostgreSQL e libpq

## Connessione al Database

Per stabilire una **connessione** a un database PostgreSQL si utilizza la funzione **PQconnectdb**, che accetta una stringa di connessione (connInfo) o un URI. La gestione degli errori è fondamentale per garantire che eventuali problemi vengano individuati immediatamente.

```c
PGconn *conn = PQconnectdb("host=localhost port=5432 dbname=esame user=utente password=segreta");
if (PQstatus(conn) != CONNECTION_OK) {
    fprintf(stderr, "Connessione fallita: %s", PQerrorMessage(conn));
    PQfinish(conn);
    exit(1);
}
```

Dopo aver utilizzato il database, la connessione va chiusa con **PQfinish(conn)**.

## Esecuzione di Comandi

Per inviare comandi **DDL/DML** (come CREATE, INSERT, SELECT) si utilizza **PQexec**. Il codice controlla lo stato del risultato tramite **PQresultStatus**:

```c
PGresult *res = PQexec(conn, "CREATE TABLE prova(id SERIAL PRIMARY KEY, nome TEXT);");
if (PQresultStatus(res) != PGRES_COMMAND_OK) {
    fprintf(stderr, "Errore creazione tabella: %s", PQerrorMessage(conn));
}
PQclear(res);
```

## Recupero dei Risultati

Quando la query restituisce tuple, si ottiene il numero di righe e di colonne con **PQntuples** e **PQnfields**, quindi si scorre il risultato con **PQgetvalue**:

```c
PGresult *res = PQexec(conn, "SELECT id, nome FROM prova;");
int rows = PQntuples(res);
int cols = PQnfields(res);
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        printf("%s	", PQgetvalue(res, i, j));
    }
    printf("
");
}
PQclear(res);
```

## Pulizia delle Risorse

È essenziale liberare la memoria del risultato e chiudere la connessione per evitare **memory leak**:

- **PQclear(res)**: rimuove il PGresult.
- **PQfinish(conn)**: chiude la connessione al DB.

## Iterazione sui Risultati

L’iterazione sui risultati si basa su un **ciclo** che utilizza **PQntuples** per contare le righe. Per ogni tupla, **PQgetvalue** e **PQgetisnull** permettono di leggere i valori e gestire i **NULL**.

## Input da Utente e File

Per leggere parametri da **argv** si impiega la firma **int main(int argc, char *argv[])**, mentre per input da file si usa **fopen**, **fscanf** o **fgets**, con gestione di **EOF** e chiusura con **fclose**.

## Insert tramite libpq

Un esempio di funzione per inserire uno studente con **sprintf**:

```c
void aggiungiStudente(PGconn *conn, const char *nome, int eta) {
    char query[256];
    sprintf(query, "INSERT INTO studenti(nome, eta) VALUES('%s', %d);", nome, eta);
    PGresult *res = PQexec(conn, query);
    PQclear(res);
}
```

## Prepared Statements

Per evitare il parsing ripetuto, si definiscono **prepared statements** con **PQprepare** e si eseguono con **PQexecPrepared**:

```c
PQprepare(conn, "stmt_insert", "INSERT INTO studenti(nome, eta) VALUES($1, $2);", 2, NULL);
const char *params[2] = { "Luca", "23" };
PGresult *res = PQexecPrepared(conn, "stmt_insert", 2, params, NULL, NULL, 0);
PQclear(res);
```

## Best Practice

- Utilizzare **PQfnumber** per recuperare l’indice di una colonna per nome, evitando dipendenza dall’ordine.
- Controllare sempre il risultato di ogni chiamata libpq e liberare le risorse.
- Gestire esplicitamente i casi di **NULL** con **PQgetisnull** e documentare il codice con commenti chiari.
