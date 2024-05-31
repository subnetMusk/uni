#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

struct nodo{
    int info;
    struct nodo *next;
};

typedef struct nodo nodo;

nodo* new_nodo(int val);
// POST: return di un puntatore ad un nuovo nodo (allocato dentro la funzione) con campo info == val

/* Fatte in classe */
// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
int isempty(nodo* ptr);
// POST: return 1 se la lista è vuota, 0 altrimenti

// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
void print_list(nodo* ptr);
void print_list_r(nodo *ptr);
// POST: stampa il contenuto della lista (i campi info), "Vuota" se non ci sono elementi

// PRE: pptr è un puntatore ad una lista (possibilmente vuota) passato per riferimento
void pre_insert(nodo** pptr, int val);
// POST: la lista puntata da pptr è quella originale con un nodo aggiunto "in testa" (inizio lista) avente campo info == val

// PRE: pptr è un puntatore ad una lista (possibilmente vuota) passato per riferimento
void suf_insert(nodo* ptr, int val);
void suf_insert_r(nodo *ptr, int value);
// POST: la lista puntata da pptr è quella originale con un nodo aggiunto "in coda" (fine lista) avente campo info == val

/* Nuove funzioni */
// PRE:  ptr è un puntatore ad una lista (possibilmente vuota)
int lung(nodo* ptr);
int lung_r(nodo* ptr);
// POST: return il numero di nodi
// NOTA: è un one-liner se usate la ricorsione

// PRE: ptr è un puntatore ad una lista (possibilmente vuota), pos è una posizione valida (tra 0 e lung(ptr)-1)
int get(nodo* ptr, int pos);
// POST: return del campo info del nodo pos-esimo

// PRE: ptr è un puntatore ad una lista (possibilmente vuota) passata per riferimento, pos è una posizione valida (tra 0 e lung(ptr)-1)
void modifica(nodo* ptr, int pos, int val);
// POST: la lista puntata da ptr è uguale a quella originale ma il nodo in posizione pos ha campo info == val

// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
void raddoppia(nodo *ptr){
    for(; ptr != NULL; ptr = ptr -> next)
        ptr -> info *= 2;
    return;
}
// POST: ogni elemento della lista risultera' raddoppiato

// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
void delete(nodo **pptr, int pos);
// POST: l'elemento di posizione pos sara' eliminato dalla lista

int main(){

    /*
    //CONSEGNA DI MOODLE


    struct nodo *list = NULL;

    int len;
    scanf("%d", &len);

    int val;
    for(int i=0; i<len; i++){
        scanf("%d", &val);
        if(i%2==0){
            pre_insert(&list, val);
        }
        else suf_insert(list, val);
    }
    print_list(list);

    //raddoppio ogni elemento della lista (codice qui)
    raddoppia(list);
    print_list(list);

    */

    //TEST IN LOCALE

    nodo *lista;

    lista = NULL;
    printf("[test 'isempty()']\nexp: 1\nout: ");
    printf("%d", isempty(lista));
    
    printf("\n\n");

    printf("[test 'print_list()']\nexp: Vuota\nout: ");
    print_list(lista); //exp vuota
    printf("\n");


    pre_insert(&lista, 10);
    printf("[test 'pre_insert()']\nexp: 10\nout: ");
    print_list(lista); //exp 10

    printf("\n\n");

    pre_insert(&lista, 20);
    pre_insert(&lista, 30);
    printf("[test 'pre_insert()']\nexp: 30 20 10\nout: ");
    print_list(lista); //exp 30 20 10
    
    printf("\n\n");

    suf_insert(lista, 5);
    printf("[test 'suf_insert()']\nexp: 30 20 10 5\nout: ");
    print_list(lista); //exp 30 20 10 5

    printf("\n\n");

    suf_insert(lista, 15);
    suf_insert(lista, 25);
    printf("[test 'suf_insert()']\nexp: 30 20 10 5 15 25\nout: ");
    print_list(lista); //exp 30 20 10 5 15 25

    printf("\n\n");
    printf("[test 'lung()']\nexp: 6\nout: ");
    printf("%d", lung(lista));
    
    printf("\n\n");
    
    int getnode = get(lista, 2);
    printf("[test 'get()']\nexp: 10\nout: ");
    printf("%d", getnode);
    
    printf("\n\n");
    
    modifica(lista, 2, 90);
    printf("[test 'modifica()']\nexp: 30 20 90 5 15 25\nout: ");
    print_list(lista);
    
    printf("\n\n");
    
    raddoppia(lista);
    printf("[test 'raddoppia()']\nexp: 60 40 180 10 30 50\nout: ");
    print_list(lista);

    printf("\n\n");
    
    delete(&lista, 0);
    printf("[test 'delete()']\nexp: 40 180 10 30 50\nout: ");
    print_list(lista);

    printf("\n\n");
    
    return 0;
}

nodo *new_nodo(int val){
    nodo *new;
    new = malloc(sizeof(nodo));
    new -> info = val;
    new -> next = NULL;
    return new;
}

int isempty(nodo *ptr){
    return ptr == NULL;
}

void print_list(nodo *ptr){
    if(ptr == NULL){
        printf("Vuota\n");
        return;
    }
    for(;ptr != NULL; ptr = ptr -> next)
        printf("%d ", ptr -> info);
    return;
}

void print_list_r(nodo *ptr){
    if(ptr == NULL){
        printf("NULL");
        return;
    }
    printf("%d --> ", ptr -> info);
    print_list_r(ptr -> next);
}


void pre_insert(nodo **pptr, int value){
    nodo *tmp;
    tmp = *pptr;
    *pptr = new_nodo(value);
    (*pptr) -> next = tmp;
    return;
}

void suf_insert(nodo *ptr, int value){
    for(;(ptr -> next) != NULL; ptr = ptr -> next);
    ptr -> next = new_nodo(value);
    return;
}

void suf_insert_r(nodo *ptr, int value){
    if(ptr -> next == NULL){
        ptr -> next = new_nodo(value);
        return;
    }
    suf_insert_r(ptr -> next, value);
}

int lung(nodo *ptr){
    int c;
    for(c = 0; ptr != NULL; c++, ptr = ptr -> next);
    return c;
}

int lung_r(nodo *ptr){
    if(ptr == NULL)
        return 0;
    return 1 + lung(ptr -> next);
}

int get(nodo *ptr, int pos){
    for(int i = 0; i < pos; i++, ptr = ptr -> next);
    return ptr -> info;
}

void modifica(nodo* ptr, int pos, int val){
    for(int i = 0; i < pos; i++, ptr = ptr -> next);
    ptr -> info = val;
    return;
}

void delete(nodo **pptr, int pos){
    if(pos > lung(&(*pptr)))
        return;

    if(pos == 0)
        (*pptr) = (*pptr) -> next;
    else{
        for(int i = 1; i < pos; i++, (*pptr) = (*pptr) -> next);
        (*pptr) -> next = (*pptr) -> next -> next;
    }
    return;
}
