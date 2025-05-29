-- QUERY 1
-- Capire se esiste un dipendente con il ruolo di dirigente “Sale Manager (EMEA)” a “Paris”;
SELECT e.* AS paris_salesmanager_emea
FROM employees AS e
JOIN offices AS o ON o.officecode = e.officecode
WHERE e.jobtitle = 'Sale Manager (EMEA)' 
AND o.city = 'Paris';

--QUERY 2
-- Trovare il nome dei clienti che hanno ordinato prodotti della linea “Planes”;
SELECT DISTINCT c.customername AS clienti_planes
FROM customers AS c
JOIN orders AS os ON os.customernumber = c.customernumber
JOIN orderdetails AS od ON od.ordernumber = os.ordernumber
JOIN products AS p ON od.productcode = p.productcode
WHERE p.productline='Planes';

-- QUERY 3
-- Trovare il nome di tutti i clienti della sede di “Tokyo”
SELECT DISTINCT c.customername AS clienti_tokyo
FROM customers AS c
JOIN employees AS e ON e.employeenumber = c.salesrepemployeenumber
JOIN offices AS o ON o.officecode = e.officecode
WHERE o.city = 'Tokyo';

-- QUERY 4
-- Trovare il codice cliente di tutti i clienti che non hanno eseguito ordini nell’anno 2005.
-- (Il formato standard di un valore di tipo timestamp `e “yyyy-mm-dd”);

SELECT DISTINCT c.customernumber AS no_orders_2005
FROM customers AS c
WHERE c.customernumber NOT IN(
SELECT c.customernumber AS order_2005
FROM customers AS c
JOIN orders AS od ON od.customernumber = c.customernumber
WHERE od.orderdate BETWEEN '2005-01-01' AND '2005-12-31'
);

-- QUERY 5
-- Restituire il nome delle città con almeno 2 dipendenti
SELECT o.city AS citta_min_due_dipendenti
FROM offices AS o
JOIN employees AS e ON e.officecode = o.officecode
GROUP BY o.city
HAVING COUNT(e.employeenumber) > '2';

-- QUERY 6
-- Restituire tutte le linee di prodotti con il numero di prodotti a loro associati
SELECT p.productline AS linea, COUNT(p.productname) AS numero_prodotti
FROM products AS p
GROUP BY p.productline;

UPDATE orderdetails
SET priceeach = '136'
WHERE ordernumber = '10100' AND productcode = 'S18_1749';

-- QUERY 7
-- Restituire le linee di prodotto in ordine decrescente di guadagno considerando un solo prodotto venduto per ogni ordine.
SELECT od.orderlinenumber AS linea, SUM(od.priceeach) AS single_product
FROM orderdetails AS od
GROUP BY linea
ORDER BY single_product DESC;

-- QUERY 8
-- Come la query precedente considerando anche la quantità di prodotti dell’ordine (quantityordered).
SELECT od.orderlinenumber AS linea, SUM(od.priceeach * od.quantityordered) AS totale
FROM orderdetails AS od
GROUP BY linea
ORDER BY totale DESC;



