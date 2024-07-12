#include <stdio.h>
#include <stdlib.h>

/*

    Si tratta di scrivere una funzione iterativa preleva con il seguente prototipo:

    coda preleva(nodo*&L, int*A, int nA) 

    che usa A come una sequenza di indici crescenti dei nodi della lista L e deve prelevare da L i nodi 
    corrispondenti agli indici in A e restituirli in una coda, mentre i nodi rimasti devono venire restituiti nel 
    parametro L (appunto passato per riferimento). 
    Esempio: sia L = 2 -> 0 -> 3 -> -2 ->10 e A=[1, 2, 4], la lista da prelevare  è quella formata dai nodi di indice 1 
    (il secondo nodo), 2 (il terzo nodo) e 4 (il quinto nodo) e cioè 0 -> 3 -> 10. Mentre la lista dei nodi che restano 
    è 2 -> -2.  Se A contenesse anche altri valori, per esempio se fosse A=[1, 2, 4, 6, 12], ovviamente i valori 
    aggiunti non avrebbero effetto perché la lista L sarebbe finita dopo i primi 3 valori.  
    E’ importante osservare che A contiene sempre elementi strettamente crescenti, visto che rappresentano 
    indici di nodi successivi di L. 
    Vediamo un altro esempio. La lista L resta come prima, ma A=[0,1,3], allora si devono prelevare i primi 2 
    nodi e poi il quarto, quindi 2->0->-2, mentre i nodi rimasti formano la lista 3->10.  
    Il caso appena presentato, cioè in cui si deve prelevare un prefisso di L (più, eventualmente, altri nodi), è 
    quello più complicato. E’ invece più semplice quando A non parte da 0, perché in questo caso in L resta un 
    nodo che precede i nodi da prelevare.  
    Per questo motivo,  in 3 test su 4 l’array A non inizia con 0. In questo modo un programma potrà passare 3 
    test anche senza trattare il caso che A parta con 0.

*/

typedef struct nodo{
    int value;
    struct nodo *next;
}nodo;

typedef nodo* coda;

nodo *new_node(int val){
    nodo *new = (nodo *)malloc(sizeof(nodo));
    new -> value = val;
    new -> next = NULL;
    return new;
}

void suf_insert(nodo **pptr, int val){
    if(*pptr == NULL){
        *pptr = new_node(val);
        return;
    }
    suf_insert(&((*pptr) -> next), val);
}

void suf_insert_n(nodo **pptr, nodo *node){
    if(*pptr == NULL){
        node -> next = NULL;
        *pptr = node;
        return;
    }
    suf_insert_n(&((*pptr) -> next), node);
}

void stampa_lista(nodo *ptr){
    if(ptr == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", ptr -> value);
    stampa_lista(ptr -> next);
}

void stampa_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        printf("%d ", *(A + i));
    printf("\n");
    return;
}

void decrementa_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        *(A + i) -= 1;
    return;
}

coda preleva(nodo **L, int *A, int nA){
    coda c = NULL;
    int index = 0;

    while(*L != NULL && *A == 0 && nA > 0){
        nodo *app = (*L) -> next;
        suf_insert_n(&c, *L);
        *L = app;
        A++;
        nA--;
        decrementa_array(A, nA);
    }

    nodo *tmp = (*L);
    while(tmp != NULL && nA > 0){
        if(*A - 1 == index){
            nodo *app = tmp -> next -> next;
            suf_insert_n(&c, tmp -> next);
            tmp -> next = app;
            A++;
            nA--;
            decrementa_array(A, nA);
        }
        else{
            tmp = tmp -> next;
            index++;
        }
    }
    return c;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");

    printf("Esempio 1:\n");
    nodo *lista = NULL;
    suf_insert(&lista, 2);
    suf_insert(&lista, 0);
    suf_insert(&lista, 3);
    suf_insert(&lista, -2);
    suf_insert(&lista, 10);

    int dimA = 3;
    int A[3] = {1, 2, 4};

    printf("Lista: ");
    stampa_lista(lista);
    printf("A[%d] = ", dimA);
    stampa_array(A, dimA);
    printf("\n");

    coda res = preleva(&lista, A, 3);
    printf("Originale: ");
    stampa_lista(lista);
    printf("Risultato: ");
    stampa_lista(res);

    printf("\n\nEsempio 2:\n");
    nodo *lista1 = NULL;
    suf_insert(&lista1, 2);
    suf_insert(&lista1, 0);
    suf_insert(&lista1, 3);
    suf_insert(&lista1, -2);
    suf_insert(&lista1, 10);

    int dimB = 3;
    int B[3] = {0, 1, 3};

    printf("Lista1: ");
    stampa_lista(lista1);
    printf("B[%d] = ", dimB);
    stampa_array(B, dimB);
    printf("\n");

    coda res1 = preleva(&lista1, B, 3);
    printf("Originale: ");
    stampa_lista(lista1);
    printf("Risultato: ");
    stampa_lista(res1);

    printf("-------------------\n");
    return;
}


int main(int argc, char **argv){
    test();

    return 0;
}
