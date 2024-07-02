#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

/*

    Si tratta di cercare le occorrenze di un carattere y in una lista concatenata i cui nodi hanno tipo:
        struct nodo{char info; nodo* next;};. 

    Vogliamo che la funzione che esegue questa ricerca sia ricorsiva e soddisfi alle seguenti proprietà: 
    
    1) F deve comportarsi nel modo seguente:  deve controllare che la lista contenga almeno k nodi con campo informativo 
    uguale a y e solo in questo caso deve stampare le posizioni di questi nodi dall’ultimo al primo (in ordine decrescente), 
    ma attenzione, non deve stampare tutte le posizioni, ma solo 1 si e 1 no, come illustrato dal seguente esempio.

    Esempio. Supponiamo che y appaia nella seconda, terza, quarta, ottava,  dodicesima e tredicesima 
    posizione della lista. Se k=7, F  non dovrebbe stampare nulla.  Se invece  k=3,  allora F dovrà stampare 12, 4 
    e 2.

    Attenzione: La  selezione dei nodi da stampare deve sempre contenere il nodo contenente y,  in 
    posizione minima (quello in posizione 2 nell’esempio). Ovviamente questo determina  la selezione di tutti 
    gli altri nodi (nell’esempio, dopo 2 si deve saltare una posizione, cioè 3, e il nodo successivo, cioè  4, è da 
    stampare, poi si salta l’8 e il 12 è da stampare e il 13 non va stampato).  L’ordine di stampa dei nodi 
    selezionati è decrescente: 12, 4 e 2. 
    

    2) Il prototipo di F deve soddisfare questa specifica:    ??? F(nodo*x, int pos, char y, int k, ???),  dove x punta 
    al nodo corrente della  lista, pos è la posizione del nodo x nella lista (0 se è il primo nodo, 1 se è il secondo e 
    così via), y è il carattere da cercare, k è il numero minimo di occorrenze di y che devono essere presenti 
    nella lista per effettuare la stampa delle posizioni  dei nodi che contengono y.  I punti interrogativi servono 
    ad indicare che  tipo del valore restituito da F è lasciato libero e che altri parametri formali possono venire 
    aggiunti a F.  
    Attenzione: introdurre parametri  passati per riferimento solo se si è certi che sia essenziale farlo. 
    Si chiede di scrivere con precisione la pre- e soprattutto la post-condizione di F e di scrivere la 
    dimostrazione di correttezza di F secondo il consueto schema induttivo. 

*/

typedef struct nodo{
    char value;
    struct nodo *next;
}nodo;

void stampa_lista(nodo *ptr){
    if(ptr == NULL){
        printf("NULL\n");
        return;
    }
    printf("%c -> ", ptr -> value);
    stampa_lista(ptr -> next);
}

nodo *new_node(char val){
    nodo *new = (nodo*)malloc(sizeof(nodo));
    new -> value = val;
    new -> next = NULL;
    return new;
}

void suf_insert(nodo **pptr, char val){
    if(*pptr == NULL){
        (*pptr) = new_node(val);
        return;
    }
    suf_insert(&((*pptr) -> next), val);
}

int conta_occorrenze(nodo *ptr, char c){
    if(ptr == NULL)
        return 0;

    if(ptr -> value == c)
        return 1 + conta_occorrenze(ptr -> next, c);
    
    return conta_occorrenze(ptr -> next, c);
}

//ho aggiunto il parametro formale 'stampa' per sapere se devo stampare la prossima occorrenza oppure no
void F(nodo *x, int pos, char y, int k, bool stampa){
    if(x == NULL)
        return;
    
    if(pos == 0 && conta_occorrenze(x, y) < k)
        return;

    if(x -> value == y){
        if(stampa){
            F(x -> next, ++pos, y, k, false);
            printf("%d ", pos);
        }
        else
            F(x -> next, ++pos, y, k, true);
    }
    else{
        F(x -> next, ++pos, y, k, stampa);
    }
    return;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");
    srand(time(NULL));
    //esempio fornito dalla consegna
    char carattere = 'x';
    nodo *lista = NULL;
    for(int i = 0; i < 13; i++){
        if(i == 1 || i == 2 || i == 3 || i == 7 || i == 11 || i == 12)
            suf_insert(&lista, carattere);
        else{
            char random = 'a';
            do{
                random = "abcdefghijklmnopqrstuvwxyz"[rand() % 26];
            }while(random == carattere);
            suf_insert(&lista, random);
        }
    }
    printf("Lista: ");
    stampa_lista(lista);

    int k1 = 7;
    int k2 = 3;

    printf("F con k=7 (exp: nulla): ");
    F(lista, 0, carattere, k1, true);
    
    printf("\n");

    printf("F con k=3 (exp: 12 4 2): ");
    F(lista, 0, carattere, k2, true);

    printf("\n-------------------\n");

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

    printf("\n");

    char c;
    printf("Inserire il carattere da cercare: ");
    scanf(" %c", &c);

    int k = -1;
    do{
        printf("Inserire il valore di k (>= 1): ");
        scanf("%d", &k);
    }while(k < 1);

    printf("F con c='%c' e k=%d: ", c, k);
    F(list, 0, c, k, true);
    printf("\n");

    return 0;
}
