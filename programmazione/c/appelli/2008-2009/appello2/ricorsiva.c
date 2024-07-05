#include<stdio.h>
#include<stdlib.h>

/*
    testo del problema in II Appello (30-03-2009)
*/

void stampa_matrice(int *A, int righe, int colonne){
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) 
            printf("%d ", A[i * colonne + j]);
        printf("\n");
    }
    return;
}

/* ------------------------------------------------------------------------------------------------------------------------------------ */
// PARTE ITERATIVA

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
/* ------------------------------------------------------------------------------------------------------------------------------------ */

// forse è 'troppo iterativa' quindi ho fatto R2 sotto
void R1(int *M, int *C, int rig, int col){
    if(col <= 0)
        return;
    int max, i_max;
    for(int i = 0; i < rig; i++){
        if(i == 0){
            i_max = 0;
            max = *((M + (rig * i)) + (col - 1));
        }
        else{
            if(*((M + (rig * i)) + (col - 1)) > max){
                i_max = i;
                max = *((M + (rig * i)) + (col - 1));
            }
        }
    }
    *(C + (col - 1)) = i_max;
    R1(M, C, rig, col-1);
    return;
}



int ind_max_r(int *M, int rig, int col, int i, int *max){
    if(i <= 0){
        *max = *((M) + (col));
        return 0;
    }

    int m = ind_max_r(M, rig, col, i-1, max);
    if(*((M + (i * rig)) + col) > *max){
        *max = *((M + (i * rig)) + col);
        return i;
    }
    return m;
}

void R2(int *M, int *C, int rig, int col){
    if(col <= 0)
        return;

    int max;
    *(C + (col - 1)) = ind_max_r(M, rig, col - 1, rig, &max);
    R2(M, C, rig, col-1);
    return;
}


void inizializza_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        *(A + i) = 0;
    return;
}

void stampa_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        printf("%d ", *(A + i));
    printf("\n");
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
    
    printf("\nFunzione R1:\n");
    int C1[colonne];
    R1(Mr, C1, righe, colonne);
    stampa_array(C1, colonne);

    printf("\nFunzione R2:\n");
    int C2[colonne];
    R2(Mr, C2, righe, colonne);
    stampa_array(C2, colonne);

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

    printf("\nP:\n");
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

    printf("\nFunzione R1:\n");
    int C[colonne];
    R1(Mr, C, righe, colonne);
    stampa_array(C, colonne);
    
    printf("\nFunzione R2:\n");
    int C2[colonne];
    R2(Mr, C2, righe, colonne);
    stampa_array(C2, colonne);
    return 0;
}

/*
    output:
    -------------------
    TEST:
    P:
    6 5 5 1 
    7 5 3 3 
    6 5 4 2 
    7 6 3 1 

    Excepted:
    19 13 8 1
    20 13 6 3
    19 12 7 2
    20 13 5 1

    Ricorsivamente:
    19 13 8 1 
    20 13 6 3 
    19 12 7 2 
    20 13 5 1 

    Iterativamente:
    19 13 8 1 
    20 13 6 3 
    19 12 7 2 
    20 13 5 1 

    Funzione R1:
    1 0 0 1 

    Funzione R2:
    1 0 0 1 
    -------------------
    Inserire il numero di righe (>= 1): 4
    Inserire il numero di colonne (>= 1): 4
    [0][0]: 1
    [0][1]: 0
    [0][2]: 0
    [0][3]: 0
    [1][0]: 0
    [1][1]: 1
    [1][2]: 0
    [1][3]: 0
    [2][0]: 0
    [2][1]: 0
    [2][2]: 1
    [2][3]: 0
    [3][0]: 0
    [3][1]: 0
    [3][2]: 0
    [3][3]: 1

    P:
    1 0 0 0 
    0 1 0 0 
    0 0 1 0 
    0 0 0 1 

    Ricorsivamente:
    4 0 0 0 
    3 3 0 0 
    3 2 2 0 
    2 2 1 1 

    Iterativamente:
    4 0 0 0 
    3 3 0 0 
    3 2 2 0 
    2 2 1 1 

    Funzione R1:
    0 1 2 3 

    Funzione R2:
    0 1 2 3 
*/
