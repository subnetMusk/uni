#include "./stdio.h"
#include "./stdlib.h"
#include "./time.h"

/*
    esiste un unico nodo detto radice che non ha predecessori --> detto radice

    tutti gli altri nodi hanno un predecessore

    i nodi che non hanno successori sono detti foglie

    l'albero è ripartito a livelli e i nodi che non sone ne radice ne foglia sono detti intermedi

    esempio                     x                           L0
    ------------------------------------------------------------
                        y              z                    L1
    ------------------------------------------------------------
                    c              t   b   u                L2
    ------------------------------------------------------------          
    3 livelli --> profondità = 2  ----  massimo grado di uscita = z (3 successori)


    Formalmente l'albero è definito come tree = (V, E)
    V = insieme di valori di qualche tipo
    E = 

    profondità di un albero = max valore della profondità dei nodi che lo compongono
    LIVELLO = insieme di nodi alla stessa profondità

    un albero è detto bilanciato quando su qualsiasi nodo la profondità dei sottoalberi differisce al massimo
    di 1 per ogni nodo (l'esempio di prima è perfettamente bilanciato)

    esempio                     x                           L0
    ------------------------------------------------------------
                        y              z                    L1
    ------------------------------------------------------------
                                   t   b   u                L2
    ------------------------------------------------------------ 
    bilanciato --> dal nodo y al nodo finale (t, b, u) c'è differenza di un solo livello

    l'albero non è bilanciato se per esempio cancello solo verso una direzione

    sull'albero si applicano le stesse operazioni che si applicano alle liste (con qualche differenza)
    
    l'inserimento in testa tende a far degenerare l'albero verso una forma sequenziale:

                                d                           L0
    ------------------------------------------------------------
                                a                           L1
    ------------------------------------------------------------
                                x                           L2
    ------------------------------------------------------------
                        y              z                    L3
    ------------------------------------------------------------
                                   g   b   u                L4
    ------------------------------------------------------------


    ALBERI BINARI DI RICERCA
    binario     -->     grado di uscita massimo di ogni nodo = 2 (0, 1 o 2 successori)
    di ricerca  -->     il valore codificato da ciascun nodo è >= del valore sul figlio
                        sinistro e < stretto del valore codificato sul figlio destro

    BST E ANALISI DI COMPLESSITÀ (vedi dalle slide)

    esempio 1:
                               2                            L0
    ------------------------------------------------------------
                    0                   6                   L1
    ------------------------------------------------------------
                    1               6       9               L2
    ------------------------------------------------------------
                    1               5                       L3
    

    esempio 2:
                            2                                L0
    ------------------------------------------------------------
                    0                   6                    L1
    ------------------------------------------------------------
                    1               6       9                L2
    ------------------------------------------------------------
                0       2           5                        L3

    

    SONO ENTRAMBI ALBERI BINARI DI RICERCA


    FUNZIONI:
    visita()
        3 modi:
        - simmetrica (ordinata):
                significa visitare i valori seguendo prima il cammino id sx --> quando trovo una foglia stampo a ritroso
                con l'esempio precedente --> 0, 1, 2, 2, 5, 6, 6, 9

                                 
        - anticipata (pre-ordine)
                2 1 0 0 2 6 6 5 9


        - posticipata (post-ordine) (il nodo corrente)
                stampa i valori di ogni sotto albero per livello (da sx verso dx)
    
*/

typedef struct bst{
    int value;
    struct bst *left;
    struct bst *right;
}bst;

typedef struct tree{
    int value;
    struct tree *next[10]; //definisco arbitrariamente un numero massimo di successori
}tree;

void init_bst(bst **pptr){
    *pptr = NULL;
    return;
}

int isempty_bst(bst *ptr){
    return ptr == NULL;
}

bst *new_node_bst(int val){
    bst *new;
    new = malloc(sizeof(bst));
    new -> value = val;
    new -> left = NULL;
    new -> right = NULL;

    return new;
}

// Funzione per inserire un valore nell'albero BST
bst* inserisci_bst(bst **pptr, int val) {
    if((*pptr) == NULL){
        (*pptr) = new_node_bst(val);
        return;
    }

    if((*pptr) -> value < val)
        inserisci_bst(&((*pptr) -> right), val);
    else
        inserisci_bst(&((*pptr) -> left), val);
}


void popola_bst(bst **pptr, int min, int max, int *count, int max_count) {
    srand(time(NULL));
    if (*pptr == NULL && *count < max_count){
        int val = rand() % (max - min + 1) + min;
        *pptr = new_node_bst(val);
        *count += 1;
        if (min < val) {
            popola_bst(&((*pptr)->left), min, val - 1, count, max_count);
        }
        if (val < max) {
            popola_bst(&((*pptr)->right), val + 1, max, count, max_count);
        }
    }
    return;
}

//funzione per avere una sorta di albero "standard" su cui provare le funzioni
void popola_ordinato(bst **pptr){
    inserisci_bst(pptr, 20);
    inserisci_bst(pptr, 10);
    inserisci_bst(pptr, 40);

    inserisci_bst(pptr, 5);
    inserisci_bst(pptr, 15);
    inserisci_bst(pptr, 30);
    inserisci_bst(pptr, 50);

    inserisci_bst(pptr, 3);
    inserisci_bst(pptr, 7);
    inserisci_bst(pptr, 12);
    inserisci_bst(pptr, 17);
    inserisci_bst(pptr, 25);
    inserisci_bst(pptr, 35);
    inserisci_bst(pptr, 45);
    inserisci_bst(pptr, 55);

}

// Funzione per stampare l'albero
void stampa_bst(bst* ptr) {
    if(ptr != NULL){
        //VISITA SIMMETRICA:
        stampa_bst(ptr -> left);
        printf("%d ", ptr -> value);
        stampa_bst(ptr -> right);
    }
}

//stampo l'albero in maniera più leggibile
void stampa_bst_2(bst *ptr){
    if(ptr == NULL)
        return;

    if(ptr -> left == NULL && ptr -> right == NULL)
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
    
    printf("-------------------\n");

    stampa_bst_2(ptr -> left);
    stampa_bst_2(ptr -> right);
}



//cancellazione di un nodo bst

//ritorna il minimo tra 3 valori != -1
int minimo_tre_valori(int a, int b, int c){
    int minimo;
    if(a != -1){
        minimo = a;
        if(b != -1 && b < minimo)
            minimo = b;

        if(c == -1 || minimo < c)
            return minimo;
        else
            return c;
    }
    else if(b != -1 && (c == -1 || b < c))
        return b;
    else
        return c;
}

//cerca il valore minore dell'albero
int minimo(bst *ptr){
    if(ptr == NULL)
        return -1;

    int min_destra = minimo(ptr -> right);
    int min_sinistra = minimo(ptr -> left);

    return minimo_tre_valori(min_destra, min_sinistra, ptr -> value);
}


//pre: puntatore a puntatore ad albero bst,
    //int val = valore da rimuovere dall'albero (se ci sono più valori uguali ne cancello solo 1)
//post: se val ∈ bst sarà rimosso

//ATTENZIONE --> decommentare i printf per il debug


    /*
        3 casi:
            1 - nodo foglia --> cancello direttamente il nodo
            2 - nodo con 1 figlio   -->     nodo = nodo figlio
            3 - nodo con 2 figli    -->     cerco il minore tra il ramo destro e lo sostituisco con
                                            quello da cancellare
    */
void delete_node(bst **pptr, int val){
    if((*pptr) == NULL)
        return;
    
    //printf("\nIO -> %d\n", (*pptr) -> value);

    if((*pptr) -> left != NULL && (*pptr) -> left -> value == val){
        //caso 1
        if((*pptr) -> left -> left == NULL && (*pptr) -> left -> right == NULL){
            //printf("[CASO 1 sx] (io -> %d) child -> %d\n", (*pptr) -> value, (*pptr) -> left -> value);
            free((*pptr) -> left);
            (*pptr) -> left = NULL;
            return;
        }
        else{
            //caso 2
            if(((*pptr) -> left -> left != NULL) && ((*pptr) -> left -> right == NULL)){
                //printf("[CASO 2 sx] (io -> %d) child -> %d (l -> %d / r -> NULL)\n", (*pptr) -> value, (*pptr) -> left -> value, (*pptr) -> left -> left -> value);
                (*pptr) -> left = (*pptr) -> left -> left;
                return;
            }
            else if(((*pptr) -> left -> left == NULL) && ((*pptr) ->  left -> right != NULL)){
                //printf("[CASO 2 sx] (io -> %d) child -> %d (l -> NULL / r -> %d)\n", (*pptr) -> value, (*pptr) -> left -> value, (*pptr) -> left -> right -> value);
                (*pptr) -> left = (*pptr) -> left -> right;
                return;
            }
            else{
                //caso 3
                //printf("[CASO 3 sx] (io -> %d) child -> %d (l -> %d / r -> %d)\n", (*pptr) -> value, (*pptr) -> left -> value, (*pptr) -> left -> left -> value, (*pptr) -> left -> right -> value);
                int min = minimo(*(&((*pptr) -> left) -> right));
                delete_node(&((*pptr) -> left), min);
                (*pptr) -> left -> value = min;
                return;
            }
        }   
    }

    if((*pptr) -> right != NULL && (*pptr) -> right -> value == val){
        if((*pptr) -> right -> left == NULL && (*pptr) -> right -> right == NULL){
            //printf("[CASO 1 dx] (io -> %d) child -> %d\n", (*pptr) -> value, (*pptr) -> right -> value);
            free((*pptr) -> right);
            (*pptr) -> right = NULL;
            return;
        }
        else{
            if(((*pptr) -> right -> left != NULL) && ((*pptr) ->  right -> right == NULL)){
                //printf("[CASO 2 dx] (io -> %d) child -> %d (l -> %d / r -> NULL)\n", (*pptr) -> value, (*pptr) -> right -> value, (*pptr) -> right -> left -> value);
                (*pptr) -> right = (*pptr) -> right -> left;
                return;
            }
            else if(((*pptr) -> right -> left == NULL) && ((*pptr) ->  right -> right != NULL)){
                //printf("[CASO 2 dx] (io -> %d) child -> %d (l -> NULL / r -> %d)\n", (*pptr) -> value, (*pptr) -> right -> value, (*pptr) -> right -> right -> value);
                (*pptr) -> right = (*pptr) -> right -> right;
                return;
            }
            else{
                //caso 3
                //printf("[CASO 3 dx] (io -> %d) child -> %d (l -> %d / r -> %d)\n", (*pptr) -> value, (*pptr) -> right -> value, (*pptr) -> right -> left -> value, (*pptr) -> right -> right -> value);
                int min = minimo(*(&((*pptr) -> right) -> right));
                delete_node(&((*pptr) -> right), min);
                (*pptr) -> right -> value = min;
                return;
            }
        }
    }

    //printf("\n%d < %d --> %d\n", (*pptr) -> value, val, (*pptr) -> value < val);
    if((*pptr) -> value < val){
        if((*pptr) -> right != NULL)
            delete_node(&((*pptr) -> right), val);
        else{
            return;
        }  
    }
    else{
        if((*pptr) -> left != NULL)
            delete_node(&((*pptr) -> left), val);
        else
            return;
    }
}
