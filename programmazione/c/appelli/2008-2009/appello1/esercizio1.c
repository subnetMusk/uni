#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*

    Si richiede di trattare un array T a 1 dimensione di dim elementi  come un array a due dimensioni con colon 
    colonne. Quindi questo array avrà R= dim/colon righe piene ed eventualmente un’ultima riga con solo 
    E=dim%colon elementi. Sulle righe di questa matrice (anche l’ultima con E elementi, se E>0) va fatto un 
    pattern match di un array P. E’ richiesto di contare i match di P su ciascuna riga, ma considerando solo 
    match non sovrapposti  tra di loro. La tecnica per affrontare il problema è quella di dividerlo in sotto 
    problemi ognuno dei quali verrà risolto con una funzione.  

*/

void stampa_matrice(int *M, int dim, int col){
    int (*matrice) [col] = (int (*) [col])M;
    for(int i = 0; i < ceil(dim/col); i++){
        for(int j = 0; j < col; j++){
            if((i * col) + j < dim)
               printf("[%d][%d]%d\n", i, j, matrice[i][j]); 
            else
                printf("[%d][%d]undefined\n", i, j);
        } 
        printf("\n");
    }
    return;
}

int match_riga(int *sT, int *P, int dimP, int col){
    int count = 0;
    for(int i = 0; i < col; i++){
        if(sT[i] == P[0]){
            int match = 1;
            for(int j = 1; (j + i) < col && j < dimP; j++){
                if(sT[i+j] == P[j]){
                    match++;
                }
            }
            if(match == dimP){
                count++;
                i+=(dimP-1);
            }
        }
    }
    return count;
}

int conta_match(int *T, int *P, int dimT, int dimP, int col){
    if(dimP > col){
        printf("Non è possibile trovare alcun match (dimP > elementi per colonna)\n");
        return 0;
    }
    int (*matrice) [col] = (int (*) [col])T;
    int match_totali = 0;
    int index_max_match = 0;
    int max_match = 0;
    for(int i = 0; i < (dimT/col) + 1; i++){
        int m = match_riga(matrice[i], P, dimP, col);
        printf("[Riga %d] %d match trovati\n", i, m);
        match_totali += m;
        if(m > max_match){
            index_max_match = i;
            max_match = m;
        }
            
    }
    return index_max_match;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");
    int dimT = 22;
    int colonne = 5;
    int T[22] = {
        1, 2, 3, 4, 5,
        1, 2, 1, 2, 3,
        5, 6, 1, 1, 2,
        1, 2, 2, 1, 2,
        1, 2
    };
    int dimP = 2;
    int P[2] = {1, 2};
    printf("Matrice:\n");
    stampa_matrice(T, dimT, colonne);

    int max_match = conta_match(T, P, dimT, dimP, colonne);
    printf("\nRiga con più match: %d\n", max_match);
    printf("-------------------\n\n");
    return;
}

void stampa_array(int *A, int dim){
    if(dim < 1)
        return;
    for(int i = 0; i < dim; i++){
        printf("%d ", *(A + i));
    }
    printf("\n");
    return;
}

void leggi_array(int *A, int dim){
    if(dim < 1)
        return;
    for(int i = 0; i < dim; i++){
        printf("[%d]: ", i);
        scanf("%d", A + i);
    }
    printf("\n");
    return;
}

int main(int argc, char** argv){
    test();
    
    int dimT = 0;
    do{
        printf("Inserire la dimensione dell'array T (>= 1): ");
        scanf("%d", &dimT);
        if(dimT < 1)
            printf("Inserire un valore >= 1\n");
    }while(dimT < 1);

    int T[dimT];
    leggi_array(T, dimT);

    int dimP = 0;
    do{
        printf("Inserire la dimensione dell'array P (>= 1): ");
        scanf("%d", &dimP);
        if(dimP < 1)
            printf("Inserire un valore >= 1\n");
    }while(dimP < 1);

    int P[dimP];
    leggi_array(P, dimP);

    int colonne = 0;
    do{
        printf("Inserire il numero di colonne (>= 1): ");
        scanf("%d", &colonne);
        if(colonne < 1)
            printf("Inserire un valore >= 1\n");
    }while(colonne < 1);

    printf("T: ");
    stampa_array(T, dimT);
    printf("P: ");
    stampa_array(T, dimP);

    printf("Matrice T[dimT/colonne][colonne]:\n");
    stampa_matrice(T, dimT, colonne);

    int max_match_index = conta_match(T, P, dimT, dimP, colonne);
    printf("Riga con più match: %d\n", max_match_index);

    return 0;
}
