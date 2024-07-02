#include<stdio.h>
#include<stdlib.h>

/*

Data una lista concatenata  x,  i cui nodi contengono caratteri, e dato un pattern P, 
vogliamo effettuare un pattern matching di P sulla lista  x, staccando dalla lista originale i nodi che 
partecipano al match di P. Quindi la funzione ricorsiva richiesta deve restituire due liste: quella dei nodi che 
partecipano al match e quella dei nodi che non partecipano al match.  


Esempio: sia x= d->v->a->r->w->t->h->e->q->z e P=[vhqwz], allora la funzione deve restituire due liste: 
L1: d->a->r->w->t->e->z  dei nodi che non partecipano al match e la lista L2: v->h->q  dei nodi che invece 
partecipano al match. 

Importante: il match può essere anche parziale (come nell’esempio).  Osservare il fatto che le 2 liste da 
restituire sono composte dai nodi della lista originale. Nessun nuovo nodo va allocato! 

La funzione ricorsiva deve avere il seguente prototipo:  doppio PM(nodo*x, char*P, int dimP);  in cui x, P, e 
dimP hanno il significato consueto ed  il valore restituito è di un tipo strutturato, chiamato doppio, che deve 
contenere 2 liste concatenate  (cioè due puntatori a nodo) che naturalmente dovranno essere le 2 liste 
richieste come risultato (L1 ed L2 nell’esempio).  La definizione del tipo doppio va specificata e vanno anche 
specificati i costruttori del tipo doppio che avrete usato nel codice di PM. 
Attenzione: abbiate cura di specificare chiaramente qual’è il campo di doppio destinato a contenere la lista 
del match e quindi qual’è il campo destinato a contenere l’altra lista.

*/

typedef struct nodo{
    char value;
    struct nodo *next;
}nodo;

typedef struct doppio{
    nodo *originale;
    nodo *match;
}doppio;

nodo *new_node(char car){
    nodo *new = (nodo*)malloc(sizeof(nodo));
    new -> value = car;
    new -> next = NULL;
    return new;
}

void init_doppio(doppio *pptr){
    (pptr) -> originale = NULL;
    (pptr) -> match = NULL;
    return;
}

void suf_insert(nodo **pptr, int val){
    if(*pptr == NULL){
        *pptr = new_node(val);
        return;
    }
    suf_insert(&((*pptr) -> next), val);
}

void stampa_lista(nodo *ptr){
    if(ptr == NULL){
        printf("NULL\n");
        return;
    }
    printf("%c -> ", ptr -> value);
    stampa_lista(ptr -> next);
}

nodo *pre_insert_node(nodo **pptr, nodo *n){
    if(*pptr == NULL){
        n -> next = NULL;
        return n;
    }
    n -> next = (*pptr);
    return n;
}

doppio PM(nodo *x, char *P, int dimP){
    doppio res; 
    init_doppio(&res);
    
    if(x == NULL || dimP < 1){
        res.originale = x;
        return res;
    }

    if(x -> value == *P){
        res = PM(x -> next, ++P, --dimP);
        res.match = pre_insert_node(&res.match, x);
        x = x -> next;
    }else{
        res = PM(x -> next, P, dimP);
        res.originale = pre_insert_node(&res.originale, x);
    }
    return res;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");
    nodo *x = NULL;
    suf_insert(&x, 'd');
    suf_insert(&x, 'v');
    suf_insert(&x, 'a');
    suf_insert(&x, 'r');
    suf_insert(&x, 'w');
    suf_insert(&x, 't');
    suf_insert(&x, 'h');
    suf_insert(&x, 'e');
    suf_insert(&x, 'q');
    suf_insert(&x, 'z');

    char P[5] = "vhqwz";
    int dimP = 5;

    printf("x = ");
    stampa_lista(x);
    printf("P[%d] = %s\n\n", dimP, P);

    doppio ris = PM(x, P, dimP);
    printf("Lista o (puntatore di doppio) = ");
    stampa_lista(ris.originale);
    printf("Lista m (puntatore di doppio) = ");
    stampa_lista(ris.match);
    printf("-------------------\n");
    return;
}

int lung_s(char *s){
    if(*s == '\0')
        return 0;
    return 1 + lung_s(s+1);
}

nodo *leggi_lista(){
    nodo *lista = NULL;
    char stringa[100];
    printf("Inserisci gli elementi della lista (senza spazi, max 100): ");
    scanf("%s", stringa);

    for(int i = 0; stringa[i] != '\0'; i++)
        suf_insert(&lista, stringa[i]);
    printf("\n");
    return lista;
}


int main(int argc, char** argv){
    test();

    nodo *list = leggi_lista();
    printf("Lista: ");

    stampa_lista(list);

    
    char *P;
    printf("\nInserire P: ");
    scanf("%s", P);

    int dimP = lung_s(P);

    doppio risultato = PM(list, P, dimP);

    printf("Lista o (puntatore di doppio) = ");
    stampa_lista(risultato.originale);

    printf("Lista m (puntatore di doppio) = ");
    stampa_lista(risultato.match);
    printf("\n");
    
    return 0;
}
