/*
Per ciascuna delle seguenti funzioni:
- Scrivere PRE e POST condizioni
- Scrivere la misura di complessita' del problema (il parametro che decresce con le chiamate ricorsive)
- Non e' necessario scrivere ipotesi induttiva etc...ma e' richiesto commentare adeguatamente il codice, spiegando caso base e chiamate ricorsive (in particolare perche' la misura di complessita' decresce in una chiamata ricorsive).

Parte 1
Implementare una funzione RICORSIVA con firma
void swap_eq(int* arr, int dim, int i, int j, int n)
che, dati:
• un array arr di interi di dimensione dim
• interi non-negativi i, j, n tali che n>0 e 0 ≤ i+n ≤ j ed j+n ≤ dim
modifica l'array arr scambiando la porzione arr[i] .. arr[i+n-1] con arr[j] .. arr[j+n-1].
Notare che le clausole 0 ≤ i+n ≤ j ed j+n ≤ dim assicurano che le porzioni esistano e siano disgiunte

Parte 2
UTILIZZARE la funzione swap_eq per implementare una funzione RICORSIVA con firma void swap(int* arr, int dim, int m, int n, int p)
che, dati:
• un array arr di interi di dimensione dim •interinon-negativim,n,ptaliche0≤m<n<p≤ dim
modifica l'array arr scambiando la porzione arr[m] .. arr[n-1] con arr[n] .. arr[p-1].
Notare che:
1) essendo m<n<p<dim, le porzioni in questione esistono e sono necessariamente disgiunte
2) le porzioni possono avere dimensioni differenti (il cuore dell'esercizio e' capire come decomporre il caso "complesso" di porzioni di dimensioni differente nel caso piu' semplice di porzioni di dimensione uguale (suggerimento: la funzione swap e' una combinazione di condizionali, swap_eq, e chiamate ricorsive soltanto).

N.B. Soluzioni iterative che richiamano la funzione stessa al termine senza calcolare niente ricorsivamente non saranno accettate. Punti:
• 2 punti per corretta implementazione swap_eq
• 3 punti per corretta implementazione swap
• 2 punti PRE/POST e commenti
• 2 punti misura complessita' swap
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *a, int d){
    for (int i = 0; i < d; i++) 
        printf("%d ", a[i]);
    printf("\n");
}

// 
//PRE:  a puntatore al primo elemento dell'array di interi
//      dim numero di elementi presenti nell'array (dim > 0)
//      i, j, n numeri interi t.c. i + (n - 1) < j < j + (n - 1) < dim

//POST: se l'intervallo esiste allora i due sottoarray a[i] ... a[i + (n - 1)] e a[j] ... a[j + (n - 1)] saranno scambiati (a[i] = a[j], a[i + 1] = a[j + 1] ...)
//complessita' = O(n)
void swap_eq(int* a, int dim, int i, int j, int n) {
    int index_i = i + (n - 1);
    int index_j = j + (n - 1);

    if( n == 0 || i < 0 || j < 0 || index_i >= j || index_j >= dim) //se l'intervallo j + n <= i + n la funzione termina perche' esso e' sovrapposto
        return;
    int tmp = *(a + index_i);
    *(a + index_i) = *(a + index_j);
    *(a + index_j) = tmp;
    swap_eq(a, dim, i, j, n - 1);
}


//PRE:
//POST: 
void swap(int* a, int dim, int m, int n, int p) {
    if(!((m >= 0) && (m < n) && (n < p) && (p < dim)))
        return;
    int int1 = n - m;
    int int2 = p - n;

    if(int1 < int2){
        swap_eq(a, dim, m, n, int1);
        swap(a, dim, m + int1, n + int1, p);
    }
    else if(int2 < int1){
        swap_eq(a, dim, m, n, int2);
        //ora dobbiamo richiamare swap sugli elementi non intaccati dallo scambio e quelli intaccati
        swap(a, dim, m+int2, n, p);
        
    }else{
        swap_eq(a, dim, m, n, int1);
        return;
    }
}



void consegna_moodle();

void test();

int main(void) {
    //consegna_moodle();
    test();

    return 0;
}

void test(){
    int array1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int dim1 = 8;

    int array2[6] = {0, 1, 2, 3, 4, 5};
    int dim2 = 6;

    int array3[0] = {};
    int dim3 = 0;

    int array4[5] = {0, 1, 2, 3, 4};
    int dim4 = 5;

    printf("int1 < int2 ([1, 2] - [3, 4, 5]):\n");
    print_array(array1, dim1);
    swap(array1, dim1, 1, 3, 6);
    printf("[swap m=1 n=3 p=6]\n");
    printf("exp: 1 4 5 6 2 3 7 8\nact: ");
    print_array(array1, dim1);
    printf("\n\n");

    printf("int2 < int1 ([0, 1, 2] - [3, 4]):\n");
    print_array(array2, dim2);
    swap(array2, dim2, 0, 3, 5);
    printf("[swap m=0 n=4 p=5]\n");
    printf("exp: 3 4 0 1 2 5\nact: ");
    print_array(array2, dim2);
    printf("\n\n");

    printf("array vuoto:");
    print_array(array3, dim3);
    swap(array3, dim3, 0, 2, 5);
    printf("exp: \nact: ");
    print_array(array3, dim3);
    printf("\n\n");

    printf("p = dim - 1 ([0, 1] - [2, 3]):\n");
    print_array(array4, dim4);
    swap(array4, dim4, 0, 2, 4);
    printf("[swap m=0 n=2 p=4]\n");
    printf("exp: 2 3 0 1 4\nact: ");
    print_array(array4, dim4);
    printf("\n\n");


    srand(time(NULL));
    int array5[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int dim5 = 15;
    int m = rand()%((dim5 - 3) + 1);
    int n = rand()%((dim5 - 2) - (m + 1) + 1) + (m + 1);
    int p = rand()%((dim5 - 1) - (n + 1) + 1) + (n + 1);
    printf("random ():\n");
    print_array(array5, dim5);
    swap(array5, dim5, m, n, p);
    printf("[swap m=%d n=%d p=%d]\n", m, n, p);
    printf("exp: idk\nact: ");
    print_array(array5, dim5);

    return;
}

void consegna_moodle(){
    int dim;
    int m;
    int n;
    int p;
    
    scanf("%d", &dim);
    int arr[dim];
    for(int i = 0; i < dim; i++){
        scanf("%d", arr+i);
    }

    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &p);

    swap(arr, dim, m, n, p); 
    print_array(arr, dim);

    return;
}
