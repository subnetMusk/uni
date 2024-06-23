#include<stdio.h>
#include<stdlib.h>
/*
    dato un array A e la sua dimensione scrivere una funzione che rimuova
    tutti gli elementi non ordinati (in modo crescente) presenti nell'array
*/

void stampa_array(int *A, int dim){
    if(dim == 0){
        printf("\n");
        return;
    }
    printf("%d ", *A);
    stampa_array(A+1, dim - 1);
}

void rimuovi_elemento(int A[], int *dim, int pos){
    for(int i = pos; i < *dim - 1; i++)
        A[i] = A[i + 1];
    A[*dim - 1] = '\0';
    *dim -= 1;
    return;
}

void rimuovi_non_ordinati(int A[], int *dim){
    for(int i = 0; i < *dim;){
        if(i != 0 && A[i] < A[i - 1])
            rimuovi_elemento(A, dim, i);
        else
            i++;
    }
    return;
}

int main(int argc, char **argv){
    int array[6] = {1, 4, 2, 6, 7, 3};
    int dim = 6; 

    printf("Dimensione = %d\n", dim);
    stampa_array(array, 6);

    rimuovi_non_ordinati(array, &dim);

    printf("Dimensione = %d\n", dim);
    stampa_array(array, dim);

    return 0;
}
