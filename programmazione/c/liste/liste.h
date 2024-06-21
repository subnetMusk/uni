#include "liste.c"

/*
    STRUTTURA NODO:

    typedef struct nodo{
        int info;
        struct nodo *next;
    }nodo;

*/


//pre: puntatore a nodo -- post: puntatore settato a NULL
void init(nodo **start);

//pre: puntatore a nodo, val valore intero da assegnare al campo info del nodo -- post: il puntatore punta ad un nuovo nodo con info=val
nodo *new_nodo(int val);

//pre: puntatore ad un nodo -- post: 1 se puntatore==NULL (lista vuota), 0 se puntatore!=NULL (lista non vuota)
int isempty(nodo *ptr);

//pre: puntatore a nodo -- post: stampa una lista con formato 1 2 3 4 5 6 7[\n]
void print_list(nodo *ptr);

//pre: puntatore a nodo -- post: stampa una lista con formato 1 --> 2 --> 3 --> 4 --> NULL (o NULL se la lista è vuota)
void print_list_v(nodo *ptr);

//pre: puntatore a nodo -- post: stampa (ricorsivamente) una lista con formato 1 --> 2 --> 3 --> 4 --> NULL (o NULL se la lista è vuota)
void print_list_r(nodo *ptr);

//pre: puntatore a puntatore a nodo -- post: aggiunge un nodo alla lista nella posizione precedente a quella puntata da pptr
void pre_insert(nodo **pptr, int value);

//pre: puntatore a puntatore a nodo -- post: aggiunge un nodo alla lista nella posizione successiva a quella puntata da pptr
void suf_insert(nodo **pptr, int value);

//pre: puntatore a puntatore a nodo -- post: aggiunge un nodo (ricorsivamente) alla lista nella posizione successiva a quella puntata da pptr
void suf_insert_r(nodo **pptr, int value);

//pre: puntatore a nodo -- post: ritorna la dimensione (numero di nodi) della lista
int lung(nodo *ptr);

//pre: puntatore a nodo -- post: ritorna la dimensione (numero di nodi) della lista ricorsivamente
int lung_r(nodo *ptr);

//pre: puntatore a nodo e posizione del nodo -- post: ritorna il valore del nodo 'di indice' pos
int get(nodo *ptr, int pos);

//pre: puntatore a nodo, posizione del nodo e valore da modificare -- post: modifica il campo info del nodo 'di indice' pos in val
void modifica(nodo* ptr, int pos, int val);

//pre: puntatore a nodo -- post: raddoppia tutti il campo info di tutti i nodi della lista
void raddoppia(nodo *ptr);

//pre: puntatore a nodo -- post: raddoppia tutti il campo info di tutti i nodi della lista ricorsivamente
void raddoppia_r(nodo *ptr);

//pre: puntatore a nodo -- post: elimina il nodo 'di indice' pos dalla lista
void delete_node(nodo **pptr, int pos);

//pre: puntatore a puntatore a nodo, numero intero > 0 di elementi, min intero, max intero -- post: lista popolata di n elementi random tra range min - max
void popola(nodo **pptr, int n_elem, int min, int max);

//pre: puntatore a puntatore a nodo, numero intero > 0 di elementi, min intero, max intero -- post: lista popolata di n elementi random tra range min - max ordinati in modo crescente (se met == 0) o decrescente
void popola_ord(nodo **pptr, int met, int e_elem, int min, int max);

//pre: puntatore a nodo -- post: restituisce un puntatore a nodo che rappresenta la testa della nuova lista
//                              composta dagli elementi della lista originale > threshold
nodo* filter(nodo *ptr, int threshold);

//pre: puntatore a puntatore a nodo -- post: un nodo con campo info = val sarà aggiunto alla lista nella giusta posizione
void ins_ordinato(nodo **pptr, int val);

//pre: puntatore a puntatore a nodo -- post: il nodo di posizione pos1 ed il nodo di posizione pos2 risulteranno scambiati
//NB scambia solo i campi 'info' dei nodi e non l'intera struttura
void scambia_nodi(nodo **pptr, int pos1, int pos2);

//pre: puntatore a puntatore a nodo, intero (0 ord crescente, 1 ord decrescente) -- post: la lista sarà ordinata
void ordina_lista(nodo **pptr, int met);

void popola_ord(nodo **pptr, int met, int n_elem, int min, int max);

void reverse_list(struct nodo **ptr);

void insert_dlist(struct nodoD **first, struct nodoD **last, int pos, int info);

int lungd(struct nodoD *ptr);

void print_forwardD_r(struct nodoD* first);

void print_forwardD(struct nodoD *first);

void print_backwardD_r_(struct nodoD* last);

void print_backwardD(struct nodoD* last);

void reverse_dlist(struct nodoD **first, struct nodoD **last);
