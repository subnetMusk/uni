#include <stdio.h>
#include <stdlib.h>

/*
    Si chiede di definire una funzione ricorsiva patt_match col seguente prototipo: 
    nodo* patt_match(nodo*&L, int*A, int nA) 
    che cerca di matchare il pattern A sulla lista L, restituendo nel parametro L i nodi che fanno parte del match 
    e col return i nodi di che non fanno parte del match. 
    Esempio: sia L= 4->2->0->3->11->-2->10 e A=[4,0,11,0]. E’ possibile matchare solo i primi 3 elementi di A 
    con il primo, il terzo e il quinto nodo di L.  Quindi patt_match deve restituire 4->0->11 nel parametro L e    
    2->3>-2->10 col return. Ovviamente si deve cercare di matchare  elementi successivi di A su nodi successivi 
    di L e di matchare più elementi di A possibile. Non è richiesto di matchare tutto A. 
    La PRE e POST di patt_match sono le seguenti: 
    PRE=(Lista(L) bel formata, A ha nA elementi, vL=L) 
    POST=(L è la lista che consiste dei nodi di vL che matchano con A e col return restituisce la lista degli altri 
    nodi di vL) 
*/

typedef struct nodo{
    int value;
    struct nodo *next;
}nodo;

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

void pre_insert_n(nodo **pptr, nodo *n){
    if(*pptr == NULL){
        *pptr = n;
        (*pptr) -> next = NULL;
        return;
    }
    n -> next = *pptr;
    *pptr = n;
    return;
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

nodo *patt_match(nodo **L, int *A, int nA){
    nodo *no_match = *L;
    if(*L == NULL || nA < 1)
        return no_match;
    
    if((*L) -> value == *A){
        no_match = patt_match(&((*L) -> next), A + 1, nA - 1);
    }
    else{
        no_match = patt_match(&((*L) -> next), A, nA);
        nodo *tmp = (*L) -> next;
        pre_insert_n(&no_match, *L);
        *L = tmp;
    }
    return no_match;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");

    nodo *lista = NULL;
    suf_insert(&lista, 4);
    suf_insert(&lista, 2);
    suf_insert(&lista, 0);
    suf_insert(&lista, 3);
    suf_insert(&lista, 11);
    suf_insert(&lista, 2);
    suf_insert(&lista, 10);

    int A[4] = {4, 0, 11, 0};
    int dimA = 4;

    printf("Originale: ");
    stampa_lista(lista);
    printf("A[%d]: ", dimA);
    stampa_array(A, dimA);
    printf("\n");

    nodo *non_match = patt_match(&lista, A, dimA);
    printf("nodi match: ");
    stampa_lista(lista);
    printf("nodi non match: ");
    stampa_lista(non_match);

    printf("-------------------\n");
    return;
}


int main(int argc, char **argv){
    test();

    return 0;
}
