#ifndef QUERIES_H
#define QUERIES_H

#define N_QUERIES 5

static const char *queries[N_QUERIES] = {
    /*Top N clienti per spesa totale (delivery + asporto) tra un intervallo di tempo*/
    "SELECT o.cliente AS cliente_email, "
    "SUM(c.quantita * p.prezzo) AS spesa_totale_euro "
    "FROM Ordine o "
    "JOIN Composizione c ON c.ordine = o.id "
    "JOIN Piatto p ON p.nome = c.piatto "
    "WHERE o.data_ordinazione BETWEEN $1 AND $2 "
    "GROUP BY o.cliente "
    "ORDER BY spesa_totale_euro DESC "
    "LIMIT $3;",

    /*Fornitori per numero di ingredienti distinti forniti ad una singola filiale con parametro su filiale*/
    "SELECT f.partita_iva AS fornitore_piva, "
    "f.email AS fornitore_email, "
    "MAX(sub.ingredienti_forniti) AS max_ingredienti_forniti "
    "FROM ( "
      "SELECT fo.fornitore, d.filiale, "
      "COUNT(DISTINCT c.ingrediente) AS ingredienti_forniti "
      "FROM Fornitura fo "
      "JOIN Dipendente d ON d.cf = fo.manager "
      "JOIN Contenuto c ON c.fornitura = fo.id "
      "WHERE d.filiale = $1 "
      "GROUP BY fo.fornitore, d.filiale "
    ") AS sub "
    "JOIN Fornitore f ON f.partita_iva = sub.fornitore "
    "GROUP BY f.partita_iva, f.email "
    "ORDER BY max_ingredienti_forniti DESC "
    "LIMIT $2;",

    /*Lista degli N ingredienti più consumati in assoluto tra un intervallo di tempo*/
    "SELECT r.ingrediente AS nome_ingrediente, "
    "SUM(c.quantita * r.quantita) AS totale_consumato "
    "FROM Ordine o "
    "JOIN Composizione c ON c.ordine = o.id "
    "JOIN Ricetta r ON r.piatto = c.piatto "
    "WHERE o.data_ordinazione BETWEEN $1 AND $2 "
    "GROUP BY r.ingrediente "
    "ORDER BY totale_consumato DESC "
    "LIMIT $3;",

    /*N filiali ordinate per quantità di "porzioni" disponibili per un piatto specifico*/
    "SELECT f.citta AS filiale_citta, "
    "f.indirizzo AS filiale_indirizzo, "
    "COUNT(DISTINCT c.piatto) AS piatti_disponibili "
    "FROM Filiale f "
    "JOIN Ordine o ON o.filiale = f.id "
    "JOIN Composizione c ON c.ordine = o.id "
    "WHERE c.piatto = $2 "
    "  AND NOT EXISTS ( "
    "    SELECT 1 FROM Ricetta r "
    "    LEFT JOIN Inventario inv "
    "      ON inv.ingrediente = r.ingrediente AND inv.filiale = f.id "
    "    WHERE r.piatto = c.piatto "
    "      AND (inv.quantita IS NULL OR inv.quantita < r.quantita) "
    "  ) "
    "GROUP BY f.citta, f.indirizzo "
    "ORDER BY piatti_disponibili DESC "
    "LIMIT $1;",

    /*Top N clienti con più prenotazioni tra un intervallo di tempo in una filiale specifica*/
    "SELECT pr.cliente AS cliente_email, "
    "d.filiale AS filiale_id, "
    "COUNT(*) AS numero_prenotazioni "
    "FROM Prenotazione pr "
    "JOIN Dipendente d ON pr.caposala = d.cf "
    "WHERE pr.data_prenotazione BETWEEN $1 AND $2 "
    "  AND d.filiale = $3 "
    "GROUP BY pr.cliente, d.filiale "
    "ORDER BY numero_prenotazioni DESC "
    "LIMIT $4;"
};

#endif
