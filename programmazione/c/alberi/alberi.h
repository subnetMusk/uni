#include "alberi/alberi.c"

void init_bst(bst **pptr);

int isempty_bst(bst *ptr);

bst *new_node_bst(int val);

void popola_bst(bst **pptr, int min, int max, int *count, int max_count);
void popola_ordinato(bst **pptr);

bst *inserisci_bst(bst **pptr, int val);

void stampa_bst(bst *ptr);
void stampa_bst_2(bst *ptr);

int minimo_tre_valori(int a, int b, int c);

int minimo(bst *ptr);

void cancella(bst **pptr, int l);

void delete_node(bst **pptr, int val);
