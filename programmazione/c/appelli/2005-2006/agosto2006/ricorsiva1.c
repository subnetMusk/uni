#include<stdio.h>
#include<stdlib.h>

/*
    Concerne le liste concatenate i cui nodi hanno il solito tipo: struct nodo{int info; 
    nodo* next;}; 

    Si chiede di scrivere una funzione ricorsiva con il seguente prototipo: nodo * F(nodo *& L, int l1, 
    int l2) che deve togliere i nodi di L che hanno campo info compreso nell’intervallo l1,l2 (compresi 
    gli estremi) e restituisce sia la lista L rimanente, sia (col return) la lista degli elementi estratti 
    nell’ordine che essi possedevano nella lista originale. 
    
    Esempio: L= 7->3->8->2->5->0->4 , sia  l1=2 e l2= 4, allora le liste che la funzione deve restituire 
    devono essere come segue: 
    L deve diventare, 7->8->5->0 
    mentre quella restituita col return è, 3->2->4 
*/

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

void stampa_lista(nodo *ptr){
    if(ptr == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", ptr -> value);
    stampa_lista(ptr -> next);
    return;
}

void suf_insert(nodo **pptr, int val){
    if((*pptr) == NULL){
        (*pptr) = new_node(val);
        return;
    }
    suf_insert(&((*pptr) -> next), val);
}

void suf_insert_node(nodo **pptr, nodo *node){
    if((*pptr) == NULL){
        (*pptr) = node;
        (*pptr) -> next = NULL;
        return;
    }
    suf_insert_node(&((*pptr) -> next), node);
}

nodo* pre_insert(nodo **pptr, int val){
    if((*pptr) == NULL){
        (*pptr) = new_node(val);
        return (*pptr);
    }
    
    nodo *new = new_node(val);
    new -> next = (*pptr);
    return new;
}

nodo *leggi_lista(int elem){
    if(elem < 1)
        return NULL;
    
    nodo *lista = NULL;
    int val = 0;
    for(int i = 0; i < elem; i++){
        printf("[%d]: ", i);
        scanf("%d", &val);
        suf_insert(&lista, val);
    }
    return lista;
}

//la funzione è già presente come 'nodo *extract()' nel file liste.c ma la rifaccio per esercizio
//per quanto riguarda la dichiarazione 'nodo * F(nodo *& L, int l1, int l2)' essa è tipica del c++
//e non del c quindi la traduco in 'nodo * F(nodo **L, int l1, int l2)'
nodo *F(nodo **L, int l1, int l2){
    if((*L) == NULL)
        return NULL;

    nodo *ext = F(&((*L) -> next), l1, l2);
    if((*L) -> value >= l1 && (*L) -> value <= l2){
        int tmp = (*L) -> value;
        (*L) = (*L) -> next;
        ext = pre_insert(&ext, tmp);
    }
    return ext;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");
    /*TEST suf_insert_node()
    nodo *lista_test = NULL;
    nodo *uno = new_node(1);
    nodo *due = new_node(2);
    nodo *tre = new_node(3);
    nodo *quatt = new_node(4);
    suf_insert_node(&lista_test, uno);
    suf_insert_node(&lista_test, due);
    suf_insert_node(&lista_test, tre);
    suf_insert_node(&lista_test, quatt);
    stampa_lista(lista_test);

    printf("\n\n");
    */

    nodo *originale = NULL;
    suf_insert(&originale, 7);
    suf_insert(&originale, 3);
    suf_insert(&originale, 8);
    suf_insert(&originale, 2);
    suf_insert(&originale, 5);
    suf_insert(&originale, 0);
    suf_insert(&originale, 4);

    printf("Originale:\n");
    stampa_lista(originale);
    printf("\n");

    int l1 = 2, l2 = 4;
    nodo *extracted = F(&originale, l1, l2);

    printf("Originale (exp: 7 -> 8 -> 5 -> 0 -> NULL):\n");
    stampa_lista(originale);

    printf("\nExtracted (exp: 3 -> 2 -> 4 -> NULL):\n");
    stampa_lista(extracted);
    printf("-------------------\n");
    return;
}

int main(int argc, char** argv){
    test();

    int n = -1;
    do{
        printf("Inserire il numero di elementi della lista: ");
        scanf("%d", &n);
        if(n < 0)
            printf("Il numero di elementi deve essere >= 0\n");
    }while(n < 0);

    nodo *list = leggi_lista(n);

    printf("Lista letta:\n");
    stampa_lista(list);

    int lim1, lim2;
    printf("Inserire lim1: ");
    scanf("%d", &lim1);
    printf("Inserire lim2: ");
    scanf("%d", &lim2);

    nodo *ext = F(&list, lim1, lim2);

    printf("\nLista originale post operazione:\n");
    stampa_lista(list);
    printf("\n");
    printf("Lista estratta:\n");
    stampa_lista(ext);
    printf("\n");

    return 0;
}
