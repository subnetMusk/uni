-- ! ATTENZIONE: alcune query sono errate tuttavia ho caricato cmq perché mi serviva

-- Riflettendo sulla distanza percorsa: quant’`e la media di distanza percorsa in metri? Qual `e
-- la distanza percorsa massima?
SELECT 	AVG(meters) AS media_distanza,
		MAX(meters) AS max_distanza
FROM trips
JOIN legs ON trips.number=legs.trip_number;

-- Quanti hub sono presenti in Italia?
SELECT COUNT(hub) AS numero_hub_it
FROM hubs
WHERE country='IT';

-- Ordinare i paesi in base al numero di hub in ordine decrescente.
SELECT COUNT(hub) AS numero_hub, country AS paese
FROM hubs
GROUP BY country
ORDER BY COUNT(hub) DESC;

-- Ordinare i paesi in base al numero di tratte che hanno in ordine decrescente.
SELECT COUNT(l.origin) AS numero_tratte, h.country AS paese
FROM legs AS l
JOIN hubs AS h ON l.origin=h.hub
GROUP BY h.country
ORDER BY COUNT(l.origin) DESC;

-- Ordinare le tratte in ordine decrescente per frequenza.
SELECT COUNT(trip_number) AS freq, trip_number
FROM legs
GROUP BY trip_number
ORDER BY COUNT(trip_number) DESC;

-- Riflettendo sulla distanza percorsa: qual `e la distanza percorsa media per paese di origine?
SELECT AVG(t.meters) AS distanza_media, h.country AS paese_origine
FROM trips AS t
JOIN legs AS l ON t.number=l.trip_number
JOIN hubs AS h ON l.origin=h.hub
GROUP BY h.country;

-- Prendendo in considerazione gli hub di partenza più comuni (almeno 3000 partenze), quando
-- sono stati utilizzati la prima e l’ultima volta in uscita?
SELECT 	origin AS hub,
		COUNT(origin) AS partenze, 
		MIN(departure_time) AS prima_uscita,
		MAX(departure_time) AS ultima_uscita
FROM legs
GROUP BY origin
HAVING COUNT(origin) >= 3000;

-- Prendendo in considerazione gli hub di partenza pi`u comuni (almeno 3000 partenze), quando
-- sono stati utilizzati la prima e l’ultima volta?
DROP VIEW IF EXISTS utilizzo_hub;
CREATE VIEW utilizzo_hub AS
(SELECT origin AS hub,
		departure_time AS utilizzo
FROM legs)
UNION ALL
(SELECT destination AS hub,
		arrival_time AS utilizzo
FROM legs);

DROP VIEW IF EXISTS hub_part_comuni;
CREATE VIEW hub_part_comuni AS
SELECT origin AS origine, COUNT(trip_number)
FROM legs
GROUP BY origin
HAVING COUNT(trip_number) >= 3000;

SELECT 	hpc.origine,
		MIN(uh.utilizzo),
		MAX(uh.utilizzo)
FROM hub_part_comuni AS hpc
JOIN utilizzo_hub AS uh ON uh.hub=hpc.origine
GROUP BY hpc.origine;

-- Quali sono gli hub di partenza e destinazione più comuni in tutto il mondo (almeno 5000 voli
-- tra partenze e arrivi)?
DROP VIEW IF EXISTS part_dest;
CREATE VIEW part_dest AS
SELECT origin AS hub
FROM legs
UNION ALL
SELECT destination AS hub
FROM legs;

SELECT hub, COUNT(hub) AS num_voli
FROM part_dest
GROUP BY hub
HAVING COUNT(hub) >= 5000;

-- Quali sono gli hub italiani che sono partenze un numero di volte superiore alla media italiana?
DROP VIEW IF EXISTS media_italiana;
CREATE VIEW media_italiana AS
SELECT AVG(totale) AS media
FROM (
SELECT legs.origin, COUNT(legs.origin) AS totale
FROM legs
JOIN hubs ON legs.origin=hubs.hub
WHERE hubs.country='IT'
GROUP BY legs.origin
);

SELECT legs.origin AS hub, COUNT(legs.origin) AS tot
FROM legs
JOIN hubs ON legs.origin=hubs.hub
WHERE hubs.country='IT'
GROUP BY legs.origin
HAVING COUNT(legs.origin) > (SELECT media FROM media_italiana);

-- Quali sono gli hub più comuni come prime partenze e ultimi arrivi per i trip?
DROP VIEW IF EXISTS prime_partenze CASCADE;
CREATE VIEW prime_partenze AS
SELECT trip_number, MIN(departure_time) AS pp
FROM legs
GROUP BY trip_number
ORDER BY trip_number;

DROP VIEW IF EXISTS num_prime_part_hub CASCADE;
CREATE VIEW num_prime_part_hub AS
SELECT legs.origin, COUNT(legs.origin) AS noh
FROM legs
JOIN prime_partenze 
ON legs.trip_number=prime_partenze.trip_number AND legs.departure_time=prime_partenze.pp
GROUP BY legs.origin;

DROP VIEW IF EXISTS ultimi_arrivi CASCADE;
CREATE VIEW ultimi_arrivi AS
SELECT trip_number, MAX(arrival_time) AS ua
FROM legs
GROUP BY trip_number
ORDER BY trip_number;

DROP VIEW IF EXISTS num_dest_hub CASCADE;
CREATE VIEW num_dest_hub AS
SELECT legs.destination, COUNT(legs.destination) AS nuh
FROM legs
JOIN ultimi_arrivi 
ON legs.trip_number=ultimi_arrivi.trip_number AND legs.departure_time=ultimi_arrivi.ua
GROUP BY legs.destination;

SELECT hubs.hub, (SUM(npph.noh)+SUM(ndh.nuh)) AS tot
FROM hubs
JOIN num_prime_part_hub AS npph ON hubs.hub=npph.origin
JOIN num_dest_hub AS ndh ON hubs.hub=ndh.destination
GROUP BY hubs.hub
ORDER BY tot DESC;

-- Quali sono i paesi con le più comuni prime partenze e gli ultimi arrivi? Consiglio: una delle
-- viste costruite alla query precedente pu`o essere utile!
DROP VIEW IF EXISTS sum_per_hub CASCADE;
CREATE VIEW sum_per_hub AS
SELECT hubs.hub, (SUM(npph.noh)+SUM(ndh.nuh)) AS tot
FROM hubs
JOIN num_prime_part_hub AS npph ON hubs.hub=npph.origin
JOIN num_dest_hub AS ndh ON hubs.hub=ndh.destination
GROUP BY hubs.hub
ORDER BY tot DESC;

SELECT hubs.country, SUM(sph.tot)
FROM hubs
JOIN sum_per_hub AS sph ON hubs.hub=sph.hub
GROUP BY hubs.country
ORDER BY SUM(sph.tot) DESC;
