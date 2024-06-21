#include "array.c"
void leggi_array(int a[], int dim);
void stampa_array(int dim, int a[dim]);
void stampaMatrice(int *p, int righe, int colonne);
void swap(int a[], int i1, int i2);
int partition(int a[], int lo, int hi);
void quicksort(int a[], int lo, int hi); //lo = indice minore; hi = indice maggiore
int partition_d(int a[], int lo, int hi); //in ordine decrescente
void quicksort_d(int a[], int lo, int hi);
unsigned short iscrescente(int a[], unsigned int dim);
unsigned short isdecrescente(int a[], unsigned int dim);
void incrementa_array(int* A, int length, int x, int pos);
