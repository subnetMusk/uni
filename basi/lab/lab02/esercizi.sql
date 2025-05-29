-- Esercizio 1
-- Trovare il reddito minimo, medio e massimo di donne e uomini
SELECT MIN(reddito) AS minimo, MAX(reddito) AS massimo, AVG(reddito) as media
FROM persone
GROUP BY sesso;

-- Esercizio 2
-- Trovare il reddito medio dei genitori di sesso maschile per eta
SELECT AVG(reddito) AS media
FROM persone AS p
WHERE p.sesso = 'M';

-- Esercizio 3
-- Fornire le coppie di fratelli (due persone sono fratelli se hanno un genitore in comune)
-- indicandone i nomi. Ordinare poi i nomi in ordine alfabetico
SELECT DISTINCT
    LEAST(p1.nome, p2.nome) AS fratello1,
    GREATEST(p1.nome, p2.nome) AS fratello2
FROM genitori g1
JOIN genitori g2
    ON g1.genitore = g2.genitore AND g1.figlio <> g2.figlio
JOIN persone p1
    ON g1.figlio = p1.id
JOIN persone p2
    ON g2.figlio = p2.id
WHERE p1.id < p2.id
ORDER BY fratello1, fratello2; -- ChatGPT

-- Esercizio 4
-- Nomi di tutti i fratelli delle persone di nome Aldo
SELECT DISTINCT p.nome
FROM persone AS p
JOIN genitori AS g
ON g.figlio = p.id
WHERE g.genitore IN (
	SELECT DISTINCT p1.id
	FROM persone AS p1
	JOIN genitori AS g1
	ON p1.id = g1.genitore
	JOIN persone AS p2
	ON p2.id = g1.figlio
	WHERE p2.nome = 'Aldo'
) AND p.nome <> 'Aldo';

-- Esercizio 5
-- Nomi delle persone che sono genitori di almeno 2 figli
SELECT p.nome AS nome_genitore
FROM persone AS p
JOIN genitori AS g
ON p.id = g.genitore
GROUP BY p.id, p.nome
HAVING COUNT(g.figlio) >= 2;

-- Esercizio 6
-- Mostrare per ciascun figlio entrambi i genitori, indicando, per ciascuno, il nome
SELECT f.nome AS figlio, g1.nome AS genitore1, g2.nome AS genitore2
FROM genitori AS p1
JOIN genitori AS p2
ON p1.figlio = p2.figlio AND p1.genitore < p2.genitore
JOIN persone AS f
ON f.id = p1.figlio
JOIN persone AS g1
ON g1.id = p1.genitore
JOIN persone AS g2
ON g2.id = p2.genitore;

-- Esercizio 7
-- Modificare la query precedente in modo da riportare tutte le persone, con campo 
-- NULL per padre e/o madre quando questi siano assenti
SELECT 
    p.nome AS figlio,
    g1.nome AS genitore1,
    g2.nome AS genitore2
FROM persone p
LEFT JOIN (
    SELECT figlio,
           MIN(genitore) AS gen1,
           MAX(genitore) AS gen2
    FROM genitori
    GROUP BY figlio
) AS g ON p.id = g.figlio
LEFT JOIN persone g1 ON g.gen1 = g1.id
LEFT JOIN persone g2 ON 
    CASE 
        WHEN g.gen1 <> g.gen2 THEN g.gen2
        ELSE NULL
    END = g2.id;






