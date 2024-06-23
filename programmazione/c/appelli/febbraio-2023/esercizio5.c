#include<stdio.h>
#include<stdlib.h>
/*
    Scrivere in modo chiaro ed esaustivo la definizione di albero binario di ricerca:
        Per albero binario di ricerca si intende un tipo di albero binario (ogni nodo ha un solo predecessore,
        eccezione fatta per la radice che non ha predecessori, e al massimo due nodi successori) che soddisfi 
        la condizione 'valore nodo successore sx' < 'valore nodo padre' <= 'valore nodo successore destro'
    
    Esemprio concreto:
*/

typedef struct bst{
    int value;
    struct bst *left;
    struct bst *right;
}bst;

void stampa_bst(bst *root){
    if(root == NULL)
        return;
    
    stampa_bst(root -> left);
    printf("%d ", root -> value);
    stampa_bst(root -> right);
}

bst *new_node_bst(int val){
    bst *node = malloc(sizeof(bst));
    node -> value = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void ord_insert(bst **root, int val){
    if(*root == NULL){
        *root = new_node_bst(val);
        return;
    }
    
    if(val < (*root) -> value)
        ord_insert(&((*root) -> left), val);
    else
        ord_insert(&((*root) -> right), val);
}

int main(int argc, char **argv){
    /*
        Creiamo il seguente bst:
                    20
            10              30
        5       15      25      35

        Tale albero rispetta la definizione di bst: ogni sottoalbero ha nodo sx minore della propria radice e
        nodo dx maggiore o uguale alla stessa
    */

    bst *albero = NULL;
    stampa_bst(albero);

    ord_insert(&albero, 20);

    ord_insert(&albero, 10);
    ord_insert(&albero, 30);

    ord_insert(&albero, 5);
    ord_insert(&albero, 15);
    ord_insert(&albero, 25);
    ord_insert(&albero, 35);

    stampa_bst(albero);

    return 0;
}