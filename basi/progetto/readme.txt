Generazione e compilazione (dalla cartella src):
cd progetto/src
cmake -S . -B build
cmake --build build

Eseguire l’applicazione:
cmake --build build --target run
oppure, direttamente:
./build/connessione_db
È possibile passare una connection string completa come argomento:
./build/connessione_db "host=<host> dbname=<nome_db> user=<user> password=<psw>"

Se non si è passata la connection string come argomento all'esecuzione verrano richiesti:
Host (es. localhost)
Database (es. ristorante_db)
Utente (es. postgres)
Password