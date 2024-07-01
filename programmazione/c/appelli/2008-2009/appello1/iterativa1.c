#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*

    si tratta di scrivere una funzione void  F(int * T, int dim,int rig, int col, int k, int &strato, int & riga) 
    che riceve in T un array contenente dim interi e deve trattarlo come un array int[][rig][col] 
    e deve calcolare lo  strato di T tale che contiene la  riga che presenta  il massimo numero di valori distinti 
    che appaiono esattamente k volte nella riga stessa e deve restituire al chiamante l’indice dello strato 
    trovato e anche l’indice della riga, all’interno dello strato,  che ha la proprietà appena descritta.  I due  indici 
    vanno restituiti attraverso i 2 parametri di F passati per riferimento strato e riga.  Qualoro ci fossero più 
    strati a pari merito, F deve restituire quello con indice minimo (e la sua riga). 


    Esempio: sia T=[1,2,3,1, _ 1,1,1,1, // 0,2,1,2, _ 1,0,1,3, // 3,3,1,1, _ 1,2,3,1, // 2,2,1,3, _ 3,3] con rig=2, col=4 e k=2.    
    T va quindi visto come un array di 4 strati, di cui i primi 3 sono pieni (cioè con 2 righe di 4 elementi) mentre 
    l’ultimo strato ha una riga piena e la seconda riga con solo 2 elementi. Per facilitare la comprensione gli 
    strati sono separati da spazi

    Lo strato 0:  
    nella prima riga solo 1 occorre esattamente due volte. 
    Nella seconda riga nessun elemento occorre esattamente due volte.

    Lo strato 1: 
    nella prima riga solo 2 occorre esattamente due volte. 
    Nella seconda riga 1 occorre esattamente due volte. 

    Lo strato 2: 
    nella prima riga sia 3 che 1 occorrono esattamente due volte. 
    Nella seconda riga 1 appare esattamente due  volte.  

    Lo strato 3: 
    nella prima riga 2 appare esattamente due volte. 
    Nella seconda riga (parziale) 3 appare esattamente 2 volte.


    Quindi,  in questo caso,  F dovrebbe ritornare al chiamante con strato = 2  e riga = 0.  

    Attenzione:  l’ultimo strato potrebbe essere incompleto.  

    Consiglio: conviene introdurre funzioni che si occupano di sottoproblemi.

*/

void stampa_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        printf("%d ", *(A + i));
    printf("\n");
    return;
}

void inizializza_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        *(A + i) = -1;
    return;
}

//conta quante volte un elemento appare in A
int conta_rif(int *A, int dim, int e){
    int count = 0;
    for(int i = 0; i < dim; i++){
        if(*(A + i) == e)
            count++;
    }
    return count;
}

//ritorna 1 se e è presente nell'array
int is_presente(int *riga, int col, int e){
    for(int i = 0; i < col; i++){
        if(riga[i] == e)
            return 1;
    }
    return 0;
}

//ritorna quanti elementi differenti appaiono k volte nella riga
int elementi_distinti_k(int *riga, int col, int k){
    int visti[col];
    int count = 0;
    int elem_k = 0;
    inizializza_array(visti, col);
    for(int i = 0; i < col; i++){
        if(!is_presente(visti, col, riga[i])){
            visti[count] = riga[i];
            count++;
            if(conta_rif(riga, col, riga[i]) == k)
                elem_k++;
        }
    }
    return elem_k;
}

//ritorna modificando il valore dei riferimenti 'strato' e 'riga' la posizione della riga che contiene piu' valori
//distinti che appaiono esattamente k volte
void F(int *T, int dim,int rig, int col, int k, int *strato, int *riga){
    int strati = ceil((double)dim / (double)(rig * col));
    int max_rif = 0;
    for(int i = 0; i < strati; i++){
        for(int j = 0; j < rig && ((i * (rig * col)) + (j * col)) < dim; j++){
            int colonne = col;
            if(((i * (rig * col)) + (j * col)) + col > dim){
                colonne = dim - ((i * (rig * col)) + (j * col));
            }
            int rif = elementi_distinti_k(((T + (i * (col * rig))) + (j * col)), colonne, k);
            if(rif > max_rif){
                *strato = i;
                *riga = j;
                max_rif = rif;
            }
        }
    }
    return;
}

void leggi_array(int *A, int dim){
    for(int i = 0; i < dim; i++){
        printf("[%d]: ", i);
        scanf("%d", (A + i));
    }
    printf("\n");
    return;
}

void print_matrice(int *A, int dim, int rig, int col) {
    int strati = ceil((double)dim / (double)(rig * col));
    int max_rif = 0;
    for(int i = 0; i < strati; i++){
        printf("Strato %d\n", i);
        for(int j = 0; j < rig; j++){
            int colonne = col;
            if(((i * (rig * col)) + (j * col)) + col > dim){
                colonne = dim - ((i * (rig * col)) + (j * col));
            }
            for(int k = 0; k < colonne; k++)
                printf("%d ", *(((A + (i * (col * rig))) + (j * col)) + k));
            printf("\n");
        }
        printf("\n\n");
    }
    return;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");
    int dim = 30;
    int T[30] = {
        1,2,3,1,  
        1,1,1,1, 

        0,2,1,2,  
        1,0,1,3, 

        3,3,1,1,  
        1,2,3,1,

        2,2,1,3,  
        3,3
    };
    int righe = 2;
    int colonne = 4;

    printf("Matrice:\n");
    print_matrice(T, dim, righe, colonne);

    int riga = 0;
    int strato = 0;
    int k = 2;
    F(T, dim, righe, colonne, k, &strato, &riga);
    printf("Riga con più valori distinti ripetuti %d volte: [s%d][r%d]\n", k, strato, riga);
    printf("-------------------\n");
    return;
}

int main(int argc, char** argv){
    test();

    int dim = -1;
    do{
        printf("Inserire la dimensione dell'array (>= 0): ");
        scanf("%d", &dim);
        if(dim < 0)
            printf("La dimensione dell'array deve essere >= 0\n");
    }while(dim < 0);

    int arr[dim];
    leggi_array(arr, dim);

    int righe = -1;
    do{
        printf("Inserire il numero delle righe (>= 1): ");
        scanf("%d", &righe);
        if(righe < 1)
            printf("Il numero di righe deve essere >= 1\n");
    }while(righe < 1);

    int colonne = -1;
    do{
        printf("Inserire il numero delle colonne (>= 1): ");
        scanf("%d", &colonne);
        if(colonne < 1)
            printf("Il numero di colonne deve essere >= 1\n");
    }while(colonne < 1);

    printf("Matrice:\n");
    print_matrice(arr, dim, righe, colonne);

    int k = -1;
    do{
        printf("Inserire il valore di k (>= 1): ");
        scanf("%d", &k);
        if(k < 1)
            printf("Il valore di k deve essere >= 1\n");
    }while(k < 1);


    int s = 0;
    int r = 0;
    F(arr, dim, righe, colonne, k, &s, &r);
    printf("Riga con più valori distinti ripetuti %d volte: [s%d][r%d]\n", k, s, r);

    return 0;
}
