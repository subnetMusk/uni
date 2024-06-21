//Soligo Leonardo

#include <stdio.h>
#include <stdlib.h>

//scrivere una funzione che data una lista ne crei una copia

//pre: parametri:
//      1 puntatore a nodo (lista originale)
//      1 puntatore a puntatore a nodo (lista copia)

//post: la lista originale rimarrà invariata mentre quella copia sarà la sua esatta copia

typedef struct nodo{
    int value;
    struct nodo *next;
}nodo;

nodo *new_node(int val){
    nodo *new = malloc(sizeof(nodo));
    new -> value = val;
    new -> next = NULL;
    return new;
}

void print_list(nodo *ptr){
    if(ptr == NULL){
        printf("NULL\n");
        return;
    }

    printf("%d --> ", ptr -> value);
    print_list(ptr -> next);
}

void suf_insert_r(nodo **pptr, int val){
    if((*pptr) == NULL){
        (*pptr) = new_node(val);
        return;
    }

    suf_insert_r(&((*pptr) -> next), val);
}

void clone_list_r(nodo *srcPtr, nodo **destPtr){
    if(srcPtr == NULL)
        return;
    
    suf_insert_r(destPtr, srcPtr -> value);
    clone_list_r(srcPtr -> next, destPtr);
}

void clone_list_i(nodo *srcPtr, nodo **destPtr){
    for(; srcPtr != NULL; srcPtr = srcPtr -> next)
        suf_insert_r(destPtr, srcPtr -> value);
    return;
}



int main(int argc, char **argv){
    nodo *lista = NULL;

    for(int i = 0; i < 10; i++)
        suf_insert_r(&lista, i);
    
    printf("Lista originale:\n");
    print_list(lista);

    nodo *clone_r = NULL;
    nodo *clone_i = NULL;

    clone_list_r(lista, &clone_r);
    printf("CLONE RICORSIVO:\n");
    print_list(clone_r);

    clone_list_i(lista, &clone_i);
    printf("CLONE ITERATIVO:\n");
    print_list(clone_i);

    return 0;
}
