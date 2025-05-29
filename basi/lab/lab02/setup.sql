DROP TABLE IF EXISTS persone;
CREATE TABLE persone(
	ID VARCHAR(2) PRIMARY KEY,
	nome VARCHAR(20) NOT NULL,
	reddito INT DEFAULT 0,
	eta INT CHECK(eta<200),
	sesso CHAR(1) CHECK(sesso = 'M' OR sesso = 'F')
);

DROP TABLE IF EXISTS genitori;
CREATE TABLE genitori(
	figlio VARCHAR(2),
	genitore VARCHAR(2),
	
	PRIMARY KEY(figlio, genitore),
	FOREIGN KEY (figlio) REFERENCES persone(ID),
	FOREIGN KEY (genitore) REFERENCES persone(ID)
);

