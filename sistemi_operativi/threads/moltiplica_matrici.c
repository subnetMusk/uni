#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

//variabili globali
int const dimensione = 5;
int matrice1[dimensione][dimensione];
int matrice2[dimensione][dimensione];
int res[dimensione][dimensione];
pthread_mutex_t lock;
int riga;

//funzioni
void leggi_matrice(int matrice[dimensione][dimensione]);

void leggi_matrici();

void inizializza_matrice(int matrice[dimensione][dimensione], int met);

void inizializza_matrici();

void stampa_matrice(int matrice[dimensione][dimensione]);

void moltiplica_riga(int matrice1[dimensione][dimensione], int matrice2[dimensione][dimensione], int *matrice_r, int riga);

void *moltiplica_matrice(void* r);


int main(int argc, char ** argv){
    
    inizializza_matrici();
    //leggi_matrici();

    inizializza_matrice(res, 0);

    printf("Matrice A{\n\n");
    stampa_matrice(matrice1);
    printf("\n}\n\n");
    printf("Matrice B{\n\n");
    stampa_matrice(matrice2);
    printf("\n}\n");
    printf("\n\n");


    pthread_t id[dimensione];
    int err;

    //creazione threads
    for(int i = 0; i < dimensione; i++){
        err = 0;
        err = pthread_create(&id[i], NULL, moltiplica_matrice, NULL);
        if(err)
            printf("Errore -> %s\n", strerror(err));
    }

    //distruzione threads
    for(int i = 0; i < dimensione; i++){
        pthread_join(id[i], NULL);
    }
    pthread_mutex_destroy(&lock);


    printf("Matrice Risultato (A x B){\n\n");
    stampa_matrice(res);
    printf("\n}\n");

    return 0;
}

void leggi_matrice(int matrice[dimensione][dimensione]){
    int val;
    for(int i = 0; i < dimensione * dimensione; i++){
        printf("[%d][%d]: ", i/dimensione, i%dimensione);
        scanf("%d", &val);
        matrice[i/dimensione][i%dimensione] = val;
    }
    return;
}

void leggi_matrici(){
    printf("Inserisci i valore di A:\n");
    leggi_matrice(matrice1);
    printf("Inserisci i valore di B:\n");
    leggi_matrice(matrice2);
    return;
}

void inizializza_matrice(int matrice[dimensione][dimensione], int met){
    int max = 10, min = -10;
    for(int i = 0; i < dimensione * dimensione; i++){
        matrice[i/dimensione][i%dimensione] = (min + rand() % (max - min + 1)) * met;
    }
    return;
}

void inizializza_matrici(){
    srand(time(NULL));
    inizializza_matrice(matrice1, 1);
    inizializza_matrice(matrice2, 1);
    return;
}

void stampa_matrice(int matrice[dimensione][dimensione]){
    for(int i = 0; i < dimensione; i++){
        printf("\t");
        for(int j = 0; j < dimensione; j++){
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
    return;
}

void moltiplica_riga(int matrice1[dimensione][dimensione], int matrice2[dimensione][dimensione], int *matrice_r, int riga){
    for(int i = 0; i < dimensione; i++){
        for(int j = 0; j < dimensione; j++)
            *(matrice_r + riga * dimensione + i) += matrice1[riga][j] * matrice2[j][i];
    }
}

void *moltiplica_matrice(void* arg){
    pthread_mutex_lock(&lock);

    moltiplica_riga(matrice1, matrice2, res, riga);
    riga++;

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);

    return NULL;
}
