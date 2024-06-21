#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int value;
    struct nodo *next;
};

typedef struct nodo nodo;

nodo *new_node(int val){
    nodo *new = malloc(sizeof(nodo));
    new -> value = val;
    new -> next = NULL;

    return new;
}

void print_list(nodo *ptr){
    for(; ptr != NULL; ptr = ptr -> next)
        printf("%d --> ", ptr -> value);
    printf("NULL\n");
    return;
}

void suf_insert(nodo **pptr, int val){
    if((*pptr) == NULL){
        (*pptr) = new_node(val);
        return;
    }

    nodo *tmp = (*pptr);
    for(; tmp -> next != NULL; tmp = tmp -> next);
    tmp -> next = new_node(val);
    return;
}

void clone_invlist(nodo *originale, nodo **inversa){
    if(originale == NULL)
        return;

    clone_invlist(originale -> next, inversa);
    suf_insert(inversa, originale -> value);
    return;
}

int main(int argc, char**argv){
    nodo *lista1 = NULL;
    
    printf("Lista 1 (vuota): ");
    print_list(lista1);

    for(int i = 0; i < 10; i++){
        suf_insert(&lista1, i);
    }

    printf("Lista 1 (popolata): ");
    print_list(lista1);

    nodo *inv = NULL;

    printf("Lista inv (vuota): ");
    print_list(inv);
    clone_invlist(lista1, &inv);
    printf("Lista inv (inversa di lista 1): ");
    print_list(inv);


    return 0;
}
