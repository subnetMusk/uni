# Esercizi Progettazione Concettuale

## Esercizio 1: Serra PianteBellissime

L’obiettivo di questo esercizio è modellare la gestione di una serra denominata **PianteBellissime** attraverso un **diagramma ER** che rappresenti entità e relazioni fondamentali. Le entità coinvolte includono la **PiantaAltoFusto** (identificata da codice, specie e nome botanico, con attributi quali età, clima ideale e tipo di terriccio), la **PiantaFiorita** (caratterizzata dal nome botanico, dal periodo e dalla durata di fioritura, nonché dalla quantità disponibile e dal costo unitario), il **Terriccio**, i **Clienti** (distinti in sottotipi Privato e Negozianti con attributi aggiuntivi quali nome, cognome e codice fiscale), la **Vendita** e le associazioni **DettaglioFiorite** e **DettaglioAltoFusto** per rappresentare quantità e prezzo di vendita.

### Procedura

1. Definire le entità e annotare i relativi **attributi chiave** per ciascuna, distinguendo i sottotipi di Cliente in Privato e Negozianti.  
2. Stabilire le relazioni associative: impostare la relazione **Trattamento** tra PiantaAltoFusto e Terriccio, nonché le relazioni **AcquistoFiorite** e **AcquistoAltoFusto** tra Vendita e le entità delle piante.  
3. Rappresentare la **generalizzazione** Cliente → {Privato, Negozianti} per modellare i sottotipi e le loro proprietà specifiche.  
4. Esplicitare i **vincoli non ER-esprimibili**, come il fatto che la quantità disponibile in PiantaFiorita non possa essere negativa, che il prezzo di vendita vari in funzione del contesto e che i dati relativi ai Negozianti siano obbligatori solo per tale sottotipo.

✦ **Nota esami**: la modellazione di sottotipi e la definizione di vincoli temporali o di contesto ricorrono frequentemente negli esercizi di progettazione concettuale (Appelli 24-06-2024, 17-07-2024).  

## Esercizio 2: Gestione Eventi Fiera

In questo scenario, si richiede di progettare un modello concettuale per la gestione degli **eventi** in una fiera, includendo entità quali Evento, Padiglione, Espositore, Sessione, Relazione e Partecipante, quest’ultimo suddiviso in Speaker e Pagante, con l’obbligo del biglietto per i partecipanti paganti.

### Procedura

1. Identificare le entità principali e definire per ciascuna gli **attributi essenziali** (ad esempio nome, durata e sito web per Evento; codice e dimensione per Padiglione; dati di contatto per Espositore; titolo e orario per Sessione; titolo e speaker per Relazione).  
2. Modellare le relazioni chiave: **Occupa** (Evento–Padiglione con attributo giorno), **Espone** (Espositore–Evento–Padiglione), **Organizza** (Sessione–Padiglione), **Presenta** (Speaker–Relazione–Sessione) e **Iscrive** (Partecipante–Evento).  
3. Distinguere i sottotipi di Partecipante in Speaker e Pagante, assicurando l’attributo **biglietto** per quest’ultimo con id e costo.  
4. Specificare i **vincoli non ER-esprimibili**, come l’obbligo di consentire due relazioni con lo stesso titolo solo se collocate in sessioni diverse, la necessità del pagamento per i Paganti e la molteplicità 1:N in Occupa per eventi che si svolgono in giorni multipli.

✦ **Nota esami**: gli schemi n-ary e la gestione di sottotipi sono argomenti chiave nelle prove di progettazione (Appello 17-07-2024).  

## Esercizio 3: Procedimenti Sanzionatori

Questo esercizio richiede di modellare l’intero processo dei **procedimenti sanzionatori** per esercizi commerciali, integrando informazioni su Indagine, Edizione, Soggetto (con sottotipi PersonaFisica, Impresa e UnitàLocale), Procedimento e Documento.

### Procedura

1. Rilevare le entità e definirne gli **attributi univoci**: Indagine (nome, frequenza), Edizione (codice edizione, data inizio e fine), Soggetto (CF o PIVA e indirizzo), Procedimento (ID, date di inizio, esito e archiviazione) e Documento (ID, nome, tipo e data di produzione).  
2. Modellare le relazioni: **Avvia** (tra Edizione e Procedimento), **Riferisce** (tra Procedimento e Documento) e **Parte** (tra Impresa e UnitàLocale).  
3. Introdurre la generalizzazione di Soggetto in PersonaFisica, Impresa e UnitàLocale, esplicitando le differenze di chiavi e attributi.  
4. Definire i **vincoli non ER-esprimibili**, tra cui il vincolo di sequenza temporale per cui una diffida deve precedere una sanzione, la distinzione tra CF e PIVA per le imprese, e il legame obbligatorio tra soggetto locale e impresa centrale.

✦ **Nota esami**: la modellazione di vincoli temporali e generalizzazioni complesse è centrale nelle prove più avanzate (Appello 26-08-2024).  
