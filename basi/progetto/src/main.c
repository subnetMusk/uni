#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "queries.h"

static void terminate_on_error(PGconn *conn) {
    PQfinish(conn);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    char conninfo[1024];
    PGconn *conn;

    if (argc > 1) {
        size_t pos = 0;
        for (int i = 1; i < argc; i++) {
            size_t len = strlen(argv[i]);
            if (pos + len + 1 >= sizeof(conninfo)) break;
            memcpy(conninfo + pos, argv[i], len);
            pos += len;
            conninfo[pos++] = (i+1<argc ? ' ' : '\0');
        }
    } else {
        char host[128], db[128], user[128], pass[128];
        printf("Host: "); fgets(host, sizeof(host), stdin); host[strcspn(host,"\n")]=0;
        printf("Database: "); fgets(db, sizeof(db), stdin); db[strcspn(db,"\n")]=0;
        printf("Utente: "); fgets(user, sizeof(user), stdin); user[strcspn(user,"\n")]=0;
        printf("Password: "); fgets(pass, sizeof(pass), stdin); pass[strcspn(pass,"\n")]=0;
        snprintf(conninfo, sizeof(conninfo),
                 "host=%s dbname=%s user=%s password=%s",
                 host, db, user, pass);
    }

    conn = PQconnectdb(conninfo);
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connessione fallita: %s", PQerrorMessage(conn));
        terminate_on_error(conn);
    }

    while (1) {
        printf("\n--- Menu Query ---\n");
        printf("1) Top N clienti per spesa totale in un intervallo\n");
        printf("2) Fornitori per numero di ingredienti distinti forniti a filiale\n");
        printf("3) Top N ingredienti più consumati in un intervallo\n");
        printf("4) Prime N filiali con un dato piatto disponibile\n");
        printf("5) Top N clienti con più prenotazioni in una filiale in un intervallo\n");
        printf("0) Esci\n");
        int scelta;
        if (scanf("%d", &scelta) != 1) break;
        if (scelta == 0) break;
        if (scelta < 1 || scelta > N_QUERIES) {
            printf("Scelta non valida\n");
            continue;
        }

        PGresult *res = NULL;
        const char *sql = queries[scelta-1];

        // Parametri per ciascuna query
        if (scelta == 1) {
            char sd[11], ed[11], lim[6];
            printf("Intervallo date (YYYY-MM-DD YYYY-MM-DD): ");
            scanf("%10s %10s", sd, ed);
            printf("Limit: "); scanf("%5s", lim);
            const char *p[] = { sd, ed, lim };
            res = PQexecParams(conn, sql, 3, NULL, p, NULL, NULL, 0);
        }
        else if (scelta == 2) {
            char fil[6], lim[6];
            printf("Filiale ID: "); scanf("%5s", fil);
            printf("Limit: "); scanf("%5s", lim);
            const char *p[] = { fil, lim };
            res = PQexecParams(conn, sql, 2, NULL, p, NULL, NULL, 0);
        }
        else if (scelta == 3) {
            char sd[11], ed[11], lim[6];
            printf("Intervallo date (YYYY-MM-DD YYYY-MM-DD): ");
            scanf("%10s %10s", sd, ed);
            printf("Limit: "); scanf("%5s", lim);
            const char *p[] = { sd, ed, lim };
            res = PQexecParams(conn, sql, 3, NULL, p, NULL, NULL, 0);
        }
        else if (scelta == 4) {
            char lim[6], piatto[101];
            printf("Limit: "); scanf("%5s", lim);
            printf("Nome piatto: ");
            scanf(" "); fgets(piatto, sizeof(piatto), stdin);
            piatto[strcspn(piatto,"\n")] = 0;
            const char *p[] = { lim, piatto };
            res = PQexecParams(conn, sql, 2, NULL, p, NULL, NULL, 0);
        }
        else if (scelta == 5) {
            char sd[11], ed[11], fil[6], lim[6];
            printf("Intervallo prenotazioni (YYYY-MM-DD YYYY-MM-DD): ");
            scanf("%10s %10s", sd, ed);
            printf("Filiale ID: "); scanf("%5s", fil);
            printf("Limit: "); scanf("%5s", lim);
            const char *p[] = { sd, ed, fil, lim };
            res = PQexecParams(conn, sql, 4, NULL, p, NULL, NULL, 0);
        }

        if (!res || PQresultStatus(res) != PGRES_TUPLES_OK) {
            fprintf(stderr, "Errore query %d: %s\n", scelta, PQerrorMessage(conn));
            PQclear(res);
            continue;
        }

        int nf = PQnfields(res), nr = PQntuples(res);

        // Calcola larghezza massima per ogni colonna
        int col_width[nf];
        for (int f = 0; f < nf; f++) {
            col_width[f] = strlen(PQfname(res, f));
        }
        for (int r = 0; r < nr; r++) {
            for (int f = 0; f < nf; f++) {
                int len = strlen(PQgetvalue(res, r, f));
                if (len > col_width[f]) col_width[f] = len;
            }
        }

        // Funzione inline per stampare una riga di separatori
        #define PRINT_SEPARATOR() do {               \
            putchar('+');                            \
            for (int f = 0; f < nf; f++) {           \
                for (int i = 0; i < col_width[f] + 2; i++) putchar('-'); \
                putchar('+');                        \
            }                                        \
            putchar('\n');                           \
        } while (0)

        // Stampa header
        PRINT_SEPARATOR();
        putchar('|');
        for (int f = 0; f < nf; f++) {
            printf(" %-*s |", col_width[f], PQfname(res, f));
        }
        putchar('\n');
        PRINT_SEPARATOR();

        // Stampa righe
        for (int r = 0; r < nr; r++) {
            putchar('|');
            for (int f = 0; f < nf; f++) {
                printf(" %-*s |", col_width[f], PQgetvalue(res, r, f));
            }
            putchar('\n');
        }
        PRINT_SEPARATOR();
        
        // Report numero di righe ricevute
        printf("Totale righe: %d\n", nr);

        PQclear(res);
    }

    PQfinish(conn);
    return EXIT_SUCCESS;
}
