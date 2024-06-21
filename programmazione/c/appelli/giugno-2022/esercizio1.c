#include <stdio.h>
#include <stdlib.h>

/*
     La funzione rimuovitriple(), dato un array di interi A, elimina tutti gli elementi di A uguali al precedente e 
     al successivo (il primo e l’ultimo elemento non verranno mai eliminati).
     
     Il tipo restituito dalla funzione `e void.  
     
     I parametri formali della funzione sono 
        l’array A contenente gli interi 
        la sua dimensione dim (un intero).
        
    Dopo l’invocazione della funzione, i parametri attuali corrispondenti ad A e dim (uso gli stessi nomi per semplicit`a) 
    devono rispettare le seguenti condizioni:
        dim equivale al numero di elementi superstiti (non cancellati) dell’array A.
        A deve contenere nelle prime dim posizioni i valori superstiti.
    
    La funzione non deve operare su altri array oltre ad A. 
      
      Esempi di input/output:•
      A=1,1,1,2,6,5 diventa A=1,1,2,6,5
      A=2,1,1,1,1,2,6,5 diventa A=2,1,1,2,6,5
      
      L’esercizio consiste nel
        1.  scrivere la PRE della funzione  \\ 1 punto
        2.  Implementare la funzione rimuovitriple() secondo la consegna.   \\ 8 punti(integrazione≥6 crediti)
*/

void stampa_array(int *array, int dim){
    printf("DIMENSIONE: %d\n", dim);
    for(int i = 0; i < dim; i++)
        printf("[i = %d] %d\n", i, *(array + i));
    printf("\n");
    return;
}

void rimuovi_elemento(int *array, int *dim, int pos){
    if(pos > *dim - 1 || *dim < 1 || pos < 0)
        return;
    
    for(int i = pos; i < *dim; i++){
        if(i != *dim - 1)
            *(array + i) = *(array + i + 1);
        else
            *(array + i) = '\0';
    }
    
    *dim = *dim - 1;

    return; 
}

void rimuovi_triple(int *array, int *dim){
    if(*dim < 3)
        return;
    int i = 0;
    while(i + 2 < *dim){
        if(*(array + i) == *(array + (i + 1)) && *(array + i) == *(array + (i + 2)))
            rimuovi_elemento(array, dim, i + 2);
        else
            i++;
    }
    return;
}

void test(char n, int *arr, int d){
    int dimensione = d;
    printf("ARRAY %c:\n", n);
    printf("Prima:\n");
    stampa_array(&(*arr), dimensione);
    rimuovi_triple(arr, &dimensione);
    printf("Dopo:\n");
    stampa_array(&(*arr), dimensione);
    return;
}

int main(int argc, char** argv){
    int dimA = 6;
    int A[6] = {1, 1, 1, 2, 6, 5};

    int dimB = 7;
    int B[7] = {2, 1, 2, 2, 2, 2, 5};

    int dimC = 0;
    int C[0] = {};

    int dimD = 4;
    int D[4] = {1, 0, 1, 1};

    int dimE = 3;
    int E[3] = {5, 5, 5};

    int dimF = 4;
    int F[4] = {1, 1, 1, 1};

    int dimG = 7;
    int G[7] = {1, 1, 1, 1, 1, 1, 0};

    test('A', A, 6);
    test('B', B, 7);
    test('C', C, 0);
    test('D', D, 4);
    test('E', E, 3);
    test('F', F, 4);
    test('G', G, 7);
}
