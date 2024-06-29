#include<stdio.h>
#include<stdlib.h>
/*
Si scriva una funzione ricorsiva che riceve un albero binario e determina il nodo a profondità 
minima che abbia al più 1 figlio. La funzione deve restituire la profondità di questo nodo.

In quanto segue, per brevità, chiameremo nodo+1 un nodo di un albero che possieda al più un 
figlio. Modificare la funzione della parte ricorsiva (2) in modo che costruisca una lista L di nodi che 
puntano ai nodi+1 dell’albero e tale che il primo nodo di L punti al nodo+1 a profondità minima, il 
secondo nodo di L punti al nodo+1 alla seconda profondità e così via. Il tipo dei nodi della lista L 
deve essere: struct nodoL{int prof; nodo* info; nodoL* next;};  
il campo prof conterrà la profondità nell’albero del nodo puntato dal campo info.
*/

typedef struct bst{
    int value;
    struct bst *left;
    struct bst *right;
}bst;

typedef struct nodoL{
    int prof;
    bst *info;
    struct nodoL *next;
}nodoL;

bst *new_node_bst(int val){
    bst *new = malloc(sizeof(bst));
    new -> value = val;
    new -> left = NULL;
    new -> right = NULL;
    return new;
}

nodoL *new_nodoL(bst **nodo, int depth){
    nodoL *new = malloc(sizeof(nodoL));
    new -> prof = depth;
    new -> info = (*nodo);
    new -> next = NULL;
    return new;
}

void ord_insert(bst **pptr, int val){
    if(*pptr == NULL){
        (*pptr) = new_node_bst(val);
        return;
    }

    if((*pptr) -> value > val)
        ord_insert(&((*pptr) -> left), val);
    else
        ord_insert(&((*pptr) -> right), val);
}

int minore(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int calcola_profondita(bst *ptr){
    if(ptr == NULL)
        return 0;
    
    if(ptr -> left == NULL || ptr -> right == NULL)
        return 1;
    
    return 1 + minore(calcola_profondita(ptr -> left), calcola_profondita(ptr -> right));
}

void suf_insert_lista(nodoL **lista, int depth, bst **pptr){
    if(*lista == NULL){
        *lista = new_nodoL(&(*pptr), depth);
        return;
    }
    suf_insert_lista(&((*lista) -> next), depth, pptr);
}

void stampa_nodoL(bst *ptr){
    if(ptr == NULL)
        return;
    
    printf("\t%d\n", ptr -> value);
    if(ptr -> left != NULL)
        printf("%d", ptr -> left -> value);
    else
        printf("NULL");
    if(ptr -> right != NULL)
        printf("\t\t%d\n", ptr -> right -> value);
    else
        printf("\t\tNULL\n");
    printf("----------------------");
    return; 
}

void stampa_listaL(nodoL *ptr){
    if(ptr == NULL){
        printf("NULL\n");
        return;
    }
    printf("Profondità: %d || info:\n", ptr -> prof);
    stampa_nodoL(ptr -> info);
    printf("\n\t↓\n\n");
    stampa_listaL(ptr -> next);
}

void crea_listaL(bst **pptr, nodoL **list, int prof){
    if(*pptr == NULL)
        return;
    if((*pptr) -> left == NULL || (*pptr) -> right == NULL)
        suf_insert_lista(list, prof, &(*pptr));

    crea_listaL(&(*pptr) -> right, list, prof+1);
    crea_listaL(&(*pptr) -> left, list, prof+1);
    
}

int main(int argc, char **argv){
    bst *albero = NULL;


   /*
   ho trasformato l'albero dato in un bst ma la sostanza è la stessa
                                34
                    10                      40
                2       null           null     null
           null    5
              null  null

    */
   
    ord_insert(&albero, 34);
    ord_insert(&albero, 10);
    ord_insert(&albero, 40);
    ord_insert(&albero, 2);
    ord_insert(&albero, 5);


    
    nodoL *lista = NULL;

    crea_listaL(&albero, &lista, 0);

    stampa_listaL(lista);

    return 0;
}
