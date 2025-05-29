#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "queries.h"

static void exit_nicely(PGconn *conn) {
    PQfinish(conn);
    exit(EXIT_FAILURE);
}

int main(void) {
    char host[128], db[128], user[128], pass[128];

    // Prompt per i parametri di connessione
    printf("Host (es. localhost): ");
    if (!fgets(host, sizeof(host), stdin)) return 1;
    host[strcspn(host, "\n")] = '\0';

    printf("Database: ");
    if (!fgets(db, sizeof(db), stdin)) return 1;
    db[strcspn(db, "\n")] = '\0';

    printf("Utente: ");
    if (!fgets(user, sizeof(user), stdin)) return 1;
    user[strcspn(user, "\n")] = '\0';

    printf("Password: ");
    if (!fgets(pass, sizeof(pass), stdin)) return 1;
    pass[strcspn(pass, "\n")] = '\0';

    // Costruisci la connection string
    char conninfo[512];
    snprintf(conninfo, sizeof(conninfo),
             "host=%s dbname=%s user=%s password=%s",
             host, db, user, pass);

    // Connessione al database
    PGconn *conn = PQconnectdb(conninfo);
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connessione fallita: %s", PQerrorMessage(conn));
        exit_nicely(conn);
    }

    // Esecuzione delle query
    for (int i = 0; i < N_QUERIES; i++) {
        const char *sql = queries[i];
        if (sql[0] == '\0') {
            continue;
        }

        printf("\n--- Query %d ---\n%s\n", i + 1, sql);
        PGresult *res = PQexec(conn, sql);
        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            fprintf(stderr, "Errore esecuzione query %d: %s", i + 1, PQerrorMessage(conn));
            PQclear(res);
            continue;
        }

        int nfields = PQnfields(res);
        int nrows = PQntuples(res);

        // Stampa intestazioni
        for (int f = 0; f < nfields; f++) {
            printf("%-20s", PQfname(res, f));
        }
        printf("\n");
        for (int f = 0; f < nfields * 20; f++) putchar('-');
        printf("\n");

        // Stampa righe
        for (int r = 0; r < nrows; r++) {
            for (int f = 0; f < nfields; f++) {
                printf("%-20s", PQgetvalue(res, r, f));
            }
            printf("\n");
        }
        PQclear(res);
    }

    PQfinish(conn);
    printf("\nTutte le query sono state eseguite.\n");
    return EXIT_SUCCESS;
}
