#include<stdio.h>
#include<stdlib.h>
/*
    1) Il problema riguarda l’ordinamento di un array di interi effettuando scambi tra elementi 
    contigui. Consideriamo un esempio. Sia A=[3, -1, 0, 8, 5] l’array da ordinare, la  tabella 
    d’inversione di A è l’array B=[2,0,0,1,0] dove B[i] è il numero di elementi minori di A[i] 
    che si trovano alla sua destra, cioè in A[i+1..4]. La somma degli elementi di B è il numero 
    minimo di scambi tra elementi contigui necessario per ordinare l’array.  
    Si chiede di scrivere una funzione int * TAB(int *A, int dimA) che costruisca la tabella 
    d’inversione relativa all’array A (con dimA elementi) e la restituisca col return. La tabella 
    deve essere costruita dinamicamente. E’ ammessa anche una soluzione ricorsiva. 
*/

void leggi_array(int *A, int dim){
    for(int i = 0; i < dim; i++){
        printf("[%d]: ", i);
        scanf("%d", A + i);
    }
    return;
}

void stampa_array(char *s, int *A, int dim){
    printf("%s\n", s);
    for(int i = 0; i < dim; i++)
        printf("[%d] %d\n", i, *(A + i));
    printf("\n");
    return;
}

int conta_minori(int *A, int dim, int index){
    if(dim <= index)
        return -1;
    int count = 0;
    int elem = *(A + index);
    for(int i = index + 1; i < dim; i++){
        if(*(A + i) < elem)
            count++;
    }
    return count;
}

int *tab(int *A, int dimA){
    int *tab = (int*)calloc(dimA, sizeof(int));
    for(int i = 0; i < dimA; i++)
        tab[i] += conta_minori(A, dimA, i);
    
    return tab;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");
    int dim = 5;
    int array[5] = {3, -1, 0, 8, 5};
    stampa_array("Array test():", array, dim);
    int *tabella_inversione = tab(array, dim);
    stampa_array("Tabella inversione (exp: 2 0 0 1 0):", tabella_inversione, dim);
    printf("-------------------\n");
    return;
}

int main(int argc, char** argv){
    test();
    
    int dim;
    printf("Inserire la dimensione dell'array: ");
    scanf("%d", &dim);
    int array[dim];

    printf("Inserire gli elementi dell'array:\n");
    leggi_array(array, dim);
    stampa_array("Array:", array, dim);

    int *tabella;
    tabella = tab(array, dim);

    stampa_array("Tabella di inversione:", tabella, dim);

    return 0;
}
