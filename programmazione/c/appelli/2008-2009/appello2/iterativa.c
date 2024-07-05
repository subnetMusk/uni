#include<stdio.h>
#include<stdlib.h>

/*
    testo del problema in 2008-2009/II Appello (30-03-2009)

    ho svolto l'esercizio sia in maniera iterativa (come richiesto, r52-82) che ricorsiva (che era molto più semplice
    in questo caso, r37-50)
*/

void stampa_matrice(int *A, int righe, int colonne){
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) 
            printf("%d ", A[i * colonne + j]);
        printf("\n");
    }
    return;
}

int max_3(int a, int b, int c){
    if(a > b){
        if(a > c)
            return a;
        return c;
    }
    if(b > c)
        return b;
    return c;
}

int max_2(int a, int b){
    if(a > b)   
        return a;
    return b;
}

int cammino_massimo_r(int *P, int rig, int col, int posR, int posC){
    if(posC < 0 || posR < 0 || posC >= col || posR >= rig){
        return 0;
    }
    return *((P + (posR * rig)) + (posC)) + max_3(cammino_massimo_r(P, rig, col, posR-1, posC+1), cammino_massimo_r(P, rig, col, posR, posC+1), cammino_massimo_r(P, rig, col, posR+1, posC+1));
}

void F_r(int *P, int *M, int rig, int col){
    for(int i = 0; i < rig; i++){
        for(int j = 0; j < col; j++){
            *((M + (i * rig)) + j) = cammino_massimo_r(P, rig, col, i, j);
        }
    }
}

void F_i(int *P, int *M, int rig, int col){
    if(rig <= 0 || col <= 0)    
        return;
    
    if(col == 1){
        for(int i = 0; i < rig; i++)
            *(M + i) = *(P + i);
        return;
    }

    for(int i = 0; i < rig; i++){
        *((M + rig * i) + (col - 1)) = *((P + rig * i) + (col - 1));
    }

    for(int c = col - 2; c >= 0; c--){
        for(int r = 0; r < rig; r++){
            int max_val = 0;
            if(r == 0){
                *((M) + c) = *((P) + (c)) + max_2(*((M) + (c + 1)), *((M + rig) + (c + 1)));
            }
            else if(r == rig - 1){
                *((M + (r * rig)) + c) = *((P + (r * rig)) + (c)) + max_2(*((M + (r * rig)) + (c + 1)), *((M + ((r - 1) * rig)) + (c + 1)));
            }
            else{
                *((M + (r * rig)) + c) = *((P + (r * rig)) + (c)) + max_3( *((M + ((r - 1) * rig)) + (c + 1)) , *((M + (r * rig)) + (c + 1)) , *((M + ((r + 1) * rig)) + (c + 1)) );
            }
        }

    }
    return;
}

void inizializza_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        *(A + i) = 0;
    return;
}


void test(){
    printf("-------------------\n");
    printf("TEST:\n");
    //esempio 2
    int righe = 4;
    int colonne = 4;
    int P[4 * 4] = {
        6, 5, 5, 1,
        7, 5, 3, 3,
        6, 5, 4, 2,
        7, 6, 3, 1
    }; 

    printf("P:\n");
    stampa_matrice(P, righe, colonne);

    printf("\nExcepted:\n");
    printf("19 13 8 1\n20 13 6 3\n19 12 7 2\n20 13 5 1\n");

    //M deve contenere il valore del cammino massimo ottenibile partendo da P[i][j]
    printf("\nRicorsivamente:\n");
    int Mr[4 * 4];
    inizializza_array(Mr, 4*4);

    F_r(P, Mr, righe, colonne);
    stampa_matrice(Mr, righe, colonne);


    printf("\nIterativamente:\n");
    int Mi[4 * 4];
    inizializza_array(Mi, 4*4);

    F_i(P, Mi, righe, colonne);
    stampa_matrice(Mi, righe, colonne);
    
    printf("-------------------\n");
    return;
}

void leggi_array(int *A, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("[%d][%d]: ", i, j);
            scanf(" %d", &A[(i * r) + j]);
        }
    }
    return;
}

int main(int argc, char** argv){
    test();

    int righe = 0;
    do{
        printf("Inserire il numero di righe (>= 1): ");
        scanf("%d", &righe);
        if(righe <= 0)
            printf("Il valore deve essere >= 1\n");
    }while(righe <= 0);

    int colonne = 0;
    do{
        printf("Inserire il numero di colonne (>= 1): ");
        scanf(" %d", &colonne);
        if(colonne <= 0)
            printf("Il valore deve essere >= 1\n");
    }while(colonne <= 0);

    int P[righe * colonne];
    inizializza_array(P, righe * colonne);
    leggi_array(P, righe, colonne);

    printf("P:\n");
    stampa_matrice(P, righe, colonne);
    

    int Mr[righe * colonne];
    inizializza_array(Mr, righe * colonne);
    int Mi[righe * colonne];
    inizializza_array(Mi, righe * colonne);

    F_r(P, Mr, righe, colonne);
    F_i(P, Mi, righe, colonne);

    printf("\nRicorsivamente:\n");
    stampa_matrice(Mr, righe, colonne);

    printf("\nIterativamente:\n");
    stampa_matrice(Mi, righe, colonne);

    return 0;
}
