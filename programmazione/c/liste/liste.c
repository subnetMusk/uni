#include "./stdlib.h"
#include "./stdio.h"
#include "./time.h"
#include "./basic/array.h"

typedef struct nodo{
    int info;
    struct nodo *next;
}nodo;

void init(nodo **start){
    *start = NULL;
    return;
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

    printf("\n");
    return;
}

void print_list_v(nodo *ptr){
    for(; ptr != NULL; ptr = ptr -> next)
        printf("%d --> ", ptr -> info);
    printf("NULL");
    printf("\n");
    return;
}

void print_list_r(nodo *ptr){
    if(ptr == NULL){
        printf("NULL\n");
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

void suf_insert(nodo **pptr, int value){
    if(*pptr == NULL){
        *pptr = new_nodo(value);
        return;
    }
    nodo *tmp = *pptr;
    for(; (*pptr) -> next != NULL; (*pptr) = (*pptr) -> next);
    (*pptr) -> next = new_nodo(value);
    (*pptr) = tmp;
    return;
}

void suf_insert_r(nodo **pptr, int value){
    if(*pptr == NULL){ //solo se la lista è vuota
        *pptr = new_nodo(value);
        return;
    }
    
    nodo *tmp = (*pptr);
    if((*pptr) -> next == NULL){
        (*pptr) -> next = new_nodo(value);
        return;
    }
    suf_insert_r(&((*pptr) -> next), value);
    (*pptr) = tmp;
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

void raddoppia(nodo *ptr){
    for(; ptr != NULL; ptr = ptr -> next)
        ptr -> info *= 2;
    return;
}

void raddoppia_r(nodo *ptr){
    if(ptr == NULL)
        return;
    ptr -> info *= 2;
    raddoppia_r(ptr -> next);
}

void delete_node(nodo **pptr, int pos){
    if(pos > lung((*pptr)))
        return;

    if(pos == 0)
        (*pptr) = (*pptr) -> next;
    else{
        nodo *tmp;
        tmp = (*pptr);
        for(int i = 1; i < pos; i++, (*pptr) = (*pptr) -> next);
        (*pptr) -> next = (*pptr) -> next -> next;
        (*pptr) = tmp;
    }
    return;
}

void popola(nodo **pptr, int n_elem, int min, int max){
    srand(time(NULL));
    for(int i = 0; i < n_elem; i++)
        suf_insert(pptr, rand() % (max - min + 1) + min);
    
    return;
}

nodo* filter(nodo *ptr, int threshold){
    nodo *new = NULL;
    nodo *tmp = NULL;
    for(; ptr != NULL; ptr = ptr -> next){
        if(ptr -> info > threshold){
            if(new == NULL){
                new = new_nodo(ptr -> info);
                tmp = new;
            }
            else{
                tmp -> next = new_nodo(ptr -> info);
                tmp = tmp -> next;
            }
        }
    }
    return new;
}

void ins_ordinato(nodo **pptr, int val){
    if(*pptr == NULL){
        suf_insert(pptr, val);
        return;
    }
    nodo *tmp = (*pptr);

    if(tmp -> info >= val){
        pre_insert(pptr, val);
        return;
    }
    for(; tmp -> next != NULL && tmp -> next -> info < val; tmp = tmp -> next);
    nodo *new = new_nodo(val);
    new -> next = tmp -> next;
    tmp -> next = new;
    return;
}

void scambia_nodi(nodo **pptr, int pos1, int pos2){
    int dim = lung((*pptr));
    if(pos1 > dim - 1 || pos2 > dim - 1 || pos1 < 0 || pos2 < 0)
        return;
    nodo *tmp = (*pptr);
    int val1, val2, app, max = pos1;
    if(pos1 < pos2)
        max = pos2;
    for(int i = 0; i <= max; i++, tmp = tmp -> next){
        if(i == pos1)
            val1 = tmp -> info;
        if(i == pos2)
            val2 = tmp -> info;
    }
    tmp = (*pptr);
    for(int i = 0; i <= max; i++, tmp = tmp -> next){
        if(i == pos1)
            tmp -> info = val2;
        if(i == pos2)
            tmp -> info = val1;
    }
    return;
}

void ordina_lista(nodo **pptr, int met){
    if((*pptr) == NULL)
        return;

    int dim = lung((*pptr));
    nodo *tmp;
    tmp = (*pptr);
    int valori[dim];
    for(int i = 0; i < dim; i++, tmp = tmp -> next)
        valori[i] = tmp -> info;
    
    if(met == 0)
        quicksort(valori, 0, dim - 1);
    else
        quicksort_d(valori, 0, dim - 1);

    tmp = (*pptr);
    for(int i = 0; i < dim; i++, tmp = tmp -> next)
        tmp -> info = valori[i];
    
    return;
}

void popola_ord(nodo **pptr, int met, int n_elem, int min, int max){
    popola(pptr, n_elem, min, max);
    if(met)
        ordina_lista(pptr, 0);
    else
        ordina_lista(pptr, 1);
    return;
}

void reverse_list(struct nodo **ptr){
    struct nodo *tmp = (*ptr);
    struct nodo *reversed = NULL;
    int dim = lung((*ptr));

    for(int i = dim - 1; i >= 0; i--){
        for(int j = 0; j < i; j++, tmp = tmp -> next);
        suf_insert(&reversed, tmp -> info);
        tmp = (*ptr);
    }

    (*ptr) = reversed;
    return;
}



/* LISTE BIDIREZIONALI */
typedef struct nodoD{
    int info;
    struct nodoD *next;
    struct nodoD *prev;
}nodoD;

void insert_dlist(struct nodoD **first, struct nodoD **last, int pos, int info){
    if(pos == 0){
        struct nodoD* tmp = malloc(sizeof(struct nodoD));
        tmp->info = info;
        tmp->prev = NULL;
        tmp->next = *first;
        if(*first != NULL){
            (*first)->prev = tmp;
        }
        else *last = tmp;
        *first = tmp;
    }
    else{
        insert_dlist(&((*first)->next), last, pos-1, info);
        (*first)->next->prev = (*first);
    }
}

int lungd(struct nodoD *ptr){
    int d;
    for(d = 0; ptr != NULL; d++, ptr = ptr -> next);
    return d;
}

void print_forwardD_r(struct nodoD* first){
    if(first == NULL)
        return;
    printf("%d ", first -> info);
    print_forwardD_r(first -> next);
    return;
}

void print_forwardD(struct nodoD *first){
    if(first == NULL){
        printf("Vuota\n");
        return;
    }
    for(; first != NULL; first = first -> next)
        printf("%d ", first -> info);
    printf("\n");
    return;
}

void print_backwardD_r_(struct nodoD* last){
    if(last == NULL)
        return;
    printf("%d ", last -> info);
    print_backwardD_r(last -> prev);
    return;
}

void print_backwardD(struct nodoD* last){
    if(last == NULL){
        printf("Vuota\n");
        return;
    }
    for(; last != NULL; last = last -> prev)
        printf("%d ", last -> info);
    printf("\n");
    return;
}

void reverse_dlist(struct nodoD **first, struct nodoD **last){
    if((*first) == NULL)
        return;
    
    struct nodoD *tmp_inizio = (*first);
    struct nodoD *tmp_fine = (*last);
    int app;

    for(int i = 0; i < (lungd((*first)) / 2); i++, tmp_inizio = tmp_inizio -> next, tmp_fine = tmp_fine -> prev){
        app = tmp_inizio -> info;
        tmp_inizio -> info = tmp_fine -> info;
        tmp_fine -> info = app;
    }
    return;
}
