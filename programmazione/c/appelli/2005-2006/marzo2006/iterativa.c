//risolverò tutti gli esercizi in c e non in c++ come indicato dalla consegna
#include<stdio.h>
#include<math.h>
/*
Si scriva un programma che legge da cout i seguenti valori interi: 
1)3 interi d1, d2, d3; 
2) e successivamente una sequenza n0,..,nm di interi che si conclude con un doppio 0; 
Il programma deve allocare un array int A[d1*d2*d3]  interi  e leggere in A i valori n0...nm finchè 
stanno in A o si incontrano i due 0 uno dopo l’altro. 
 
Successivamente il programma deve trattare A come fosse una matrice int [d1][d2][d3] e stabilire 
quanti dei d1 strati  (di dimensioni [d2][d3]) della matrice hanno tutte le righe composte da valori 
tutti diversi. 
*/

void inizializza_array(int *a, int dim) {
    for (int i = 0; i < dim; i++)
        *(a + i) = 0;
    return;
}

void print_array(int *a, int dim) {
    for (int i = 0; i < dim; i++)
        printf("%d ", *(a + i));
    printf("\n");
    return;
}

void print_matrice(int d1, int d2, int d3, int a[d1][d2][d3]) {
    for (int i = 0; i < d1; i++) {
        printf("S%d:\n", i);
        for (int j = 0; j < d2; j++) {
            for (int k = 0; k < d3; k++) {
                printf("%d ", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return;
}

//conta quante volte l'elemento val è presente nella matrice
int is_multi(int d2, int d3, int m[d2][d3], int val) {
    int times = 0;
    for (int i = 0; i < d2; i++) {
        for (int j = 0; j < d3; j++) {
            if (m[i][j] == val)
                times++;
        }
    }
    return times;
}

// controlla che tutti gli elementi della matrice non siano multipli
int confronta_matrice(int d2, int d3, int m[d2][d3]) {
    for (int i = 0; i < d2; i++) {
        for (int j = 0; j < d3; j++) {
            if (is_multi(d2, d3, m, m[i][j]) > 1)
                return 0;
        }
    }
    return 1;
}

// conta gli strati con valori tutti diversi
int conta_strati(int d1, int d2, int d3, int a[d1][d2][d3]) {
    int strati = 0;
    for (int i = 0; i < d1; i++) {
        if (confronta_matrice(d2, d3, a[i]))
            strati++;
    }
    return strati;
}

void leggi_valore(int *d, int n) {
    int valore_inserito;
    *d = -1;
    do {
        printf("Inserire il valore di d%d: ", n);
        scanf("%d", &valore_inserito);
        if (valore_inserito > 0)
            *d = valore_inserito;
        else
            printf("\nIl valore deve essere > 0\n");
    } while (*d < 1);
    return;
}

int riempi_array(int *arr, int dim) {
    int valore_letto = -1, precedente = -1;
    int count;
    printf("La sequenza termina con due 0 inseriti consecutivamente:\n");
    for (count = 0; count < dim; count++) {
        precedente = valore_letto;
        printf("Inserire il valore da inserire nell'array (> 0): ");
        scanf("%d", &valore_letto);
        *(arr + count) = valore_letto;
        if (count > 0 && (*(arr + (count - 1)) == 0 && valore_letto == 0))
            return count - 1;
    }
    return count;
}

int main(int argc, char **argv) {
    int d[3];

    for (int c = 1; c <= 3; c++)
        leggi_valore(&d[c - 1], c);

    int d1 = d[0], d2 = d[1], d3 = d[2];

    int dimensione = d1 * d2 * d3;
    int A[dimensione];
    inizializza_array(A, dimensione);
    int dimensione2 = riempi_array(A, dimensione);
    if (dimensione2 < d1 * d2 * d3) {
        dimensione2 -= 2; // i 2 zero finali
        // pagine effettive
        d1 = ceil(((float)dimensione2) / ((float)(d2 * d3)));
    }

    int (*mat)[d2][d3] = (int (*)[d2][d3])A;
    print_matrice(d1, d2, d3, mat);
    printf("Strati con valori tutti diversi: %d\n", conta_strati(d1, d2, d3, mat));

    return 0;
}
