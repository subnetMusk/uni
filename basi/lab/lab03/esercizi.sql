-- esercizio 1
-- Riflettendo sulla distanza percorsa: quant’è la media di distanza percorsa in metri? 
-- Qual è la distanza percorsa massima?
SELECT AVG(meters) AS distanza_media, MAX(meters) AS distanza_massima
FROM trips;

-- esercizio 2
-- Quanti hub sono presenti in Italia?
SELECT COUNT(hub) AS hub_italia
FROM hubs
WHERE hubs.country = 'IT';

-- esercizio 3
-- Ordinare i paesi in base al numero di hub in ordine decrescente
SELECT h.country AS paese, COUNT(h.hub) AS numero_hub
FROM hubs AS h
GROUP BY paese
ORDER BY numero_hub DESC;

-- esercizio 4
-- Quale è la tratta più utilizzata?
SELECT DISTINCT l.origin AS origine, l.destination AS destinazione, COUNT(l.*) AS usi
FROM legs AS l
GROUP BY origine, destinazione
ORDER BY usi DESC LIMIT 1;

-- esercizio 5
-- Ordinare i paesi in base al numero di tratte che hanno in ordine decrescente.
SELECT h1.country, COUNT(*) AS tratte
FROM legs AS l
JOIN hubs AS h1 ON h1.hub = l.origin
JOIN hubs AS h2 ON h2.hub = l.destination
WHERE (h1.country = h2.country)
GROUP BY h1.country
ORDER BY tratte DESC;

-- esercizio 6
-- Ordinare le tratte in ordine decrescente per frequenza
SELECT DISTINCT l.origin AS origine, l.destination AS destinazione, COUNT(l.*) AS usi
FROM legs AS l
GROUP BY origine, destinazione
ORDER BY usi DESC;

-- esercizio 7
-- Riflettendo sulla distanza percorsa: qual è la distanza percorsa media per paese di origine?
SELECT h1.country, AVG(t.meters) AS distanza_media
FROM legs AS l
JOIN hubs AS h1 ON h1.hub = l.origin
JOIN trips AS t ON l.trip_number = t.number
GROUP BY h1.country
ORDER BY distanza_media DESC;

-- esercizio 8
-- Prendendo in considerazione gli hub di partenza più comuni (i primi 10), quando sono stati
-- utilizzati la prima e l’ultima volta in uscita?
WITH top_hubs AS (
    SELECT l.origin
    FROM legs l
    GROUP BY l.origin
    ORDER BY COUNT(*) DESC
    LIMIT 10
)
SELECT 
	l.origin AS hub, 
	MIN(l.departure_time) AS prima_partenza, 
	MAX(l.departure_time) AS ultima_partenza
FROM legs l
JOIN top_hubs th ON l.origin = th.origin
GROUP BY l.origin;

-- esercizio 9
-- Prendendo in considerazione gli hub di partenza più comuni (almeno 3000 partenze), quando
-- sono stati utilizzati la prima e l’ultima volta in uscita?
WITH top_hubs AS (
    SELECT l.origin
    FROM legs l
    GROUP BY l.origin
    HAVING COUNT(*) > 3000
)
SELECT 
	l.origin AS hub, 
	MIN(l.departure_time) AS prima_partenza, 
	MAX(l.departure_time) AS ultima_partenza
FROM legs l
JOIN top_hubs th ON l.origin = th.origin
GROUP BY l.origin;

-- esercizio 10
-- Quali sono gli hub di partenza e destinazione più comuni in tutto il mondo (almeno 5000 voli
-- tra partenze e arrivi)?
SELECT hub AS hub, COUNT(*) AS totale_voli
FROM (
	SELECT origin AS hub FROM legs
	UNION ALL
	SELECT destination AS hub FROM legs
) AS voli
GROUP BY hub
HAVING COUNT(*) > 5000
ORDER BY COUNT(*) DESC;

-- esercizio 11
-- Quali sono gli hub italiani che sono partenze un numero di volte superiore alla media italiana?
SELECT hub AS hub, COUNT(*) AS totale_partenze
FROM (
	SELECT origin AS hub FROM legs
	JOIN hubs AS h ON h.hub = origin
	WHERE h.country = 'IT'
) AS partenze
GROUP BY hub
HAVING COUNT(*) > (
	SELECT AVG(num_partenze) AS media_partenze 
	FROM (
		SELECT l.origin, COUNT(*) AS num_partenze
		FROM legs AS l
		JOIN hubs AS h ON l.origin = h.hub
		WHERE h.country = 'IT'
		GROUP BY l.origin
	)
)
ORDER BY totale_partenze DESC;

-- esercizio 12
-- Quali sono gli hub più comuni come prime partenze e ultimi arrivi per i trip? Nota: uno
-- stesso trip (trip number) può essere associato a più legs)!
SELECT l.origin AS 


