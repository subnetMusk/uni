#include <stdio.h>
#include <assert.h>

/*
    Dato un array di interi ed un intero n>=0, ruotare verso sinistra l'array di n posizioni. 
*/


void ruota_array(int A[], int dim, int n);
void test_ruota_array();
int confronta_array(int *X, int *Y, int dim);
void consegna_moodle();


int main(void) {

    test_ruota_array();
    //consegna_moodle();

}


//pre: un array di interi, dim > 0, n intero positivo (numero di salti da effettuare verso sx)
//post: array modificato con n salti verso sx
void ruota_array(int A[], int dim, int n) {
    if(dim < 2)
        return;

    //tuttora non ho capito come il prof voleva venisse risolto ""senza creare la copia dell'array""
    for(int j = 0; j < n%dim; j++){
        int appoggio1 = 0;
        int appoggio2 = A[0];
        for(int i = dim - 1; i >= 0; i--){
            appoggio1 = A[i];
            A[i] = appoggio2;
            appoggio2 = appoggio1;
        }
    }
    return;
}


void consegna_moodle() {

    int n, dim;
    scanf("%d", &n);
    scanf("%d", &dim);
    int A[dim];

    // Lettura Array
    for(int i=0; i<dim; i+=1) {
        scanf("%d", A+i);
    }

    ruota_array(A, dim, n);

    // Stampa Array
    for(int i=0; i<dim; i+=1) {
        printf("array[%d]: %d\n", i, A[i]);
    }

}


void test_ruota_array() {

    int dim=6;
    int A[]={1,2,3,4,5,6};
    int B[]={3,4,5,6,1,2};
    ruota_array(A, dim, 2);
    assert(confronta_array(A,B,6)==1);

    printf("Tutti i test superati con successo!\n");
}


/*
    PRE: X, Y sono array di dim elementi
    POST: Restituisce 
        1 se per ogni i. 0<=i<dim X[i]=Y[i]
        0 altrimenti
*/
int confronta_array(int *X, int *Y, int dim) {

   for(int i=0; i<dim; i+=1) {
       if (X[i]!=Y[i])
        return 0; 
   }
   return 1; 
}
