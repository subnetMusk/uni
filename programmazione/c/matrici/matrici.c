#include <stdio.h>
void stampa_matrice(int *M, int r, int c){
    for (int i = 0; i < r; i += 1){ 
        for (int j = 0; j < c; j += 1){ 
            printf("%d ", *(M + j + i*c));
        } 
        printf("\n"); 
    } 
}

void stampa_matrice_double(double *Matrice, int righe, int colonne){
    for (int i = 0; i < righe; i += 1){
        for (int j = 0; j < colonne; j += 1){
            printf("%lf ", *(Matrice + j + i*colonne));
        }
        printf("\n");
    }
}
void trasposta_matrice(int* A, int* B, int righe, int colonne){
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            B[righe*j+i] = A[colonne*i+j];
        }
    }
}

void trasposta_matrice_double(double *Matrice, double* Trasposta, int righe, int colonne){
    for(int i=0; i<righe; i+=1){
        for(int j=0; j<colonne; j+=1){
            *(Trasposta + i+ j*righe) = *(Matrice +j +i*colonne);
        }
    }
}

void matrice_identita_double(double *Matrice, int dim){

    for(int i=0; i<dim; i+=1){
        for (int j=0; j<dim; j+=1){
            *(Matrice + j+ i*dim) = (i==j)? 1.0 : 0.0;
        }
    }
}
