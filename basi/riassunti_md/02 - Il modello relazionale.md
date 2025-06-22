# Il modello relazionale

## Relazione matematica e modello relazionale

Il concetto di **relazione matematica** costituisce le fondamenta teoriche del modello relazionale: si tratta di un sottoinsieme del prodotto cartesiano dei domini D₁, D₂, …, Dₙ, dove ogni **n‑upla** è definita da valori ordinati e distinti. A partire da questa rappresentazione astratta, il **modello relazionale**, formalizzato da Edgar F. Codd nel 1970, introduce l’idea di organizzare i dati in **tabelle**, in cui ogni colonna corrisponde a un attributo e ogni riga a una tupla, garantendo una struttura uniforme e rigorosa.

## Istanza di relazione e istanza di base di dati

Quando si parla di **istanza di relazione**, si intende l’insieme di tutte le tuple attualmente presenti secondo uno schema R(A₁, A₂, …, Aₙ). Estendendo questo concetto, un **database relazionale** è composto da un insieme di relazioni R₁, R₂, …, Rₖ, ognuna definita sul proprio schema. Due proprietà cruciali delle istanze relazionali sono l’assenza di un ordine prefissato tra righe e colonne e l’unicità delle tuple, che evita duplicazioni e garantisce coerenza.

## Vincoli di integrità intrarelazionali

I **vincoli di integrità intrarelazionali** assicurano che i dati all’interno di una singola relazione rispettino regole semantiche di validità. I vincoli di **dominio** impongono che ogni valore appartenga al dominio previsto dall’attributo; i vincoli di **tupla** richiedono che una determinata condizione booleana sia soddisfatta da ciascuna riga, come nel caso di una formula che verifichi la correttezza di un calcolo tra attributi. Infine, i **vincoli di chiave** stabiliscono che esistano insiemi di attributi – le **superchiavi** – in grado di identificare univocamente ogni tupla, tra cui la **chiave primaria**, priva di valori nulli, rappresenta la scelta minima e non ridondante.

**Nota esami:** la verifica di superchiave e chiave è un tema ricorrente, ad esempio nel quiz dell’appello del 17 luglio 2024 (Q1).

## Vincoli di integrità interrelazionali

Per mantenere la coerenza tra più tabelle, si introducono i **vincoli di integrazione referenziale**: un valore presente in un attributo di relazione R₁ deve comparire come chiave primaria in una relazione R₂, assicurando che non vi siano riferimenti “orfani”. Le politiche di gestione di questi vincoli possono includere il rifiuto dell’operazione, la cancellazione a cascata delle tuple dipendenti o l’impostazione di valori nulli, a seconda delle esigenze applicative.

**Nota esami:** l’interazione tra vincoli di integrità e meccanismi di recovery costituisce un argomento avanzato spesso associato a esercizi complessi.

## Valori nulli

I **valori nulli** rappresentano l’assenza di una informazione valida e non appartengono al dominio di alcun attributo. È importante distinguere tra le diverse interpretazioni di null, che possono indicare uno stato sconosciuto, l’inesistenza di un dato o semplicemente l’indisponibilità dell’informazione. Alcuni vincoli, come la chiave primaria, proibiscono l’uso di null per garantire l’identificabilità completa delle tuple.

## Strutture nidificate e normalizzazione

Quando una relazione include dati ripetuti o strutture complesse, la **normalizzazione** suggerisce di scomporre tali elementi in relazioni separate per evitare ridondanza e garantire l’integrità. Ad esempio, dettagli di una ricevuta possono essere estratti in una relazione distinta, collegata tramite chiavi esterne. In alternativa, si può aggiungere un attributo artificiale, come un numero di riga, per preservare l’unicità delle tuple senza duplicare informazioni.

