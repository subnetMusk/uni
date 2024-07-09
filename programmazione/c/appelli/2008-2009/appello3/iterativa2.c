#include <stdio.h>
#include <stdlib.h>

/*

    Data una lista concatenata L, i cui nodi hanno tipo struct nodo{int info; nodo* next;}; , e dato un 
    array int P[dimP],  si chiede di fare match degli elementi di P  (in ordine) con i campi info dei nodi di L, 
    scomponendo L in  2 liste: quella dei nodi in cui si è trovato il match e quella degli altri nodi di L.  Il 
    seguente esempio dovrebbe chiarire l’enunciato. 
    Esempio: sia L=6->3->1->5->2 e P=[3,1,7]. La funzione richiesta deve produrre la coppia di liste :                                 
    (6->5->2, 3->1). Quindi non si richiede che il match di P sia completo. 
    Visto che la funzione deve restituire una coppia di liste, è conveniente usare il seguente tipo struttura: 
    struct coppiaL{nodo* a,*b;}; La funzione richiesta deve avere il seguente prototipo: 
    coppiaL F(nodo*L, int*P,  int dimP) 
    F deve essere iterativa e non deve in nessun caso creare nuovi nodi, ma deve distribuire i nodi della 
    lista data L sulle 2 liste da costruire e da restituire con il return. La struttura L2E e la funzione addF 
    dell’esercizio (1) dovrebbero venire usate per semplificare la realizzazione di F. Specificare la pre e la 
    post condizione di F e l’invariante del ciclo che essa contiene.

*/

typedef struct nodo{
    int value;
    struct nodo *next;
}nodo;

typedef struct coppiaL{
    nodo *a;
    nodo *b;
}coppiaL;

nodo *new_node(int val){
    nodo *new = (nodo *)malloc(sizeof(nodo));
    new -> value = val;
    new -> next = NULL;
    return new;
}

void suf_insert_v(nodo **pptr, int val){
    if(*pptr == NULL){
        *pptr = new_node(val);
        return;
    }
    suf_insert_v(&((*pptr) -> next), val);
}

void suf_insert(nodo **pptr, nodo *n){
    if(*pptr == NULL){
        n -> next = NULL;
        *pptr = n;
        return;
    }
    suf_insert(&((*pptr) -> next), n);
}

int dim_list(nodo *ptr){
    if(ptr == NULL)
        return 0;
    return 1 + dim_list(ptr -> next);
}

void stampa_lista(nodo *ptr){
    if(ptr == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", ptr -> value);
    stampa_lista(ptr -> next);
}

coppiaL F(nodo *l, int *P, int dimP){
    coppiaL res;
    res.a = NULL;
    res.b = NULL;
    int counter = 0;

    switch(dim_list(l)){
        case 0:
            res.a = NULL;
            res.b = NULL;
            break;

        case 1:
            if(l -> value == *P){
                res.a = NULL;
                res.b = l;
            }else{
                res.a = l;
                res.b = NULL;
            }
            break;

        default:
            while(l != NULL){
                nodo *next = l -> next;
                if(counter < dimP && l -> value == *(P + counter)){
                    suf_insert(&res.b, l);
                    counter++;
                }
                else{
                    suf_insert(&res.a, l);
                }
                l = next;
            }
    }
    return res;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n\n");
    nodo *lista = NULL;
    suf_insert(&lista, new_node(6));
    suf_insert(&lista, new_node(3));
    suf_insert(&lista, new_node(1));
    suf_insert(&lista, new_node(5));
    suf_insert(&lista, new_node(2));
    printf("Lista originale:\n");
    stampa_lista(lista);

    int dimP = 3;
    int P[3] = {3, 1, 7};

    coppiaL risultato = F(lista, P, dimP);

    printf("\nExpected:\nLista A:\n6 -> 5 -> 2 -> NULL\nLista B:\n3 -> 1 -> NULL\n");

    
    printf("\nActual:\nLista A:\n");
    stampa_lista(risultato.a);
    printf("Lista B:\n");
    stampa_lista(risultato.b);

    printf("-------------------\n");
    return;
}

nodo *leggi_lista(){
    nodo *list = NULL;
    printf("Inserire i valori della lista (-1 per terminare)\n");
    for(int val = 0, i = 0; val != -1; i++){
        printf("[%d] = ", i);
        scanf(" %d", &val);
        if(val != -1){
            suf_insert_v(&list, val);
        }
    }
    return list;
}

void leggi_array(int *A, int dim){
    for(int i = 0; i < dim; i++){
        printf("[%d]: ", i);
        scanf(" %d", A + i);
    }
    return;
}

void stampa_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        printf("%d ", *(A + i));
    printf("\n");
    return;
}

int main(int argc, char** argv){
    test();

    nodo *lista = leggi_lista();
    stampa_lista(lista);

    int dimP = 0;
    do{
        printf("Inserire la dimensione di P (>= 0): ");
        scanf(" %d", &dimP);
        if(dimP <= 0){
            printf("La dimensione deve essere >= 0\n");
        }
    }while(dimP <= 0);
    
    int P[dimP];
    leggi_array(P, dimP);

    printf("P: ");
    stampa_array(P, dimP);

    coppiaL risultato = F(lista, P, dimP);

    printf("Lista A: ");
    stampa_lista(risultato.a);
    printf("Lista B: ");
    stampa_lista(risultato.b);

    return 0;
}

/*
    output:
    -------------------
    TEST:

    Lista originale:
    6 -> 3 -> 1 -> 5 -> 2 -> NULL

    Expected:
    Lista A:
    6 -> 5 -> 2 -> NULL
    Lista B:
    3 -> 1 -> NULL

    Actual:
    Lista A:
    6 -> 5 -> 2 -> NULL
    Lista B:
    3 -> 1 -> NULL
    -------------------
    Inserire i valori della lista (-1 per terminare)
    [0] = 1
    [1] = 2
    [2] = 3
    [3] = 4
    [4] = 5
    [5] = 6
    [6] = 7
    [7] = 8
    [8] = 9
    [9] = -1
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL
    Inserire la dimensione di P (>= 0): 5
    [0]: 1
    [1]: 2
    [2]: 5
    [3]: 7
    [4]: 5
    P: 1 2 5 7 5 
    Lista A: 3 -> 4 -> 6 -> 8 -> 9 -> NULL
    Lista B: 1 -> 2 -> 5 -> 7 -> NULL
*/
