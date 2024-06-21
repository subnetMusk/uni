#include <stdio.h>
#include <stdlib.h>

/*Tenendo conto delle dichiarazioni e del frammento di codice riportato di seguito, scrivere la funzione informa
ricorsiva printlist che dovr`a stampare gli elementi della lista in ordine inverso.  

Vi `e richiesto discrivere soltanto la funzione. 6 punti(integrazione≥3 crediti)1
*/

struct nodo{
    int value;
    struct nodo* next;
};

typedef struct nodo nodo;

nodo *new_node(int val){
    nodo *new = malloc(sizeof(nodo));
    new -> value = val;
    new -> next = NULL;

    return new;
}

void insert_ord(nodo **pptr, int val){
    nodo *new = new_node(val);

    if((*pptr) == NULL){
        (*pptr) = new;
        return;
    }


    nodo *tmp = (*pptr);
    if((*pptr) -> value > val){
        (*pptr) = new;
        (*pptr) -> next = tmp;
        return;
    }
    
    for(; tmp -> next != NULL && tmp -> next -> value < val; tmp = tmp -> next);
    new -> next = tmp -> next;
    tmp -> next = new;

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

void printlist(nodo *ptr){
    if(ptr == NULL){
        printf("NULL\n");
        return;
    }
       
    printf("%d --> ", ptr -> value);
    printlist(ptr -> next);
}

void printlist_reverse(nodo *ptr){
    if(ptr == NULL){
        printf("NULL");
        return;
    }
    
    printlist_reverse(ptr -> next);
    printf(" --> %d", ptr -> value);
}

int main(int argc, char **argv){
    nodo *lista;
    lista = NULL;

    for(int i = 0; i < 10; i++)
        suf_insert(&lista, i);

    
    printf("Lista 'dritta':\n");
    printlist(lista);

    printf("Lista 'rovescia':\n");
    printlist_reverse(lista);
    printf("\n");

    //esercizio 3
    printf("PROVA INSERIMENTO ORDINATO:\n");
    nodo *lista2 = NULL;
    for(int i = 0; i < 5; i++)
        insert_ord(&lista2, (i + 1) * 10);

    insert_ord(&lista2, -1); //testa
    insert_ord(&lista2, 111); //coda

    insert_ord(&lista2, 5);
    insert_ord(&lista2, 15);
    insert_ord(&lista2, 25);
    insert_ord(&lista2, 35);
    insert_ord(&lista2, 45);
    insert_ord(&lista2, 55);

    printlist(lista2);


    return 0;
}
