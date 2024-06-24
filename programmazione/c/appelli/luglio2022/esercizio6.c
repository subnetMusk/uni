#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
    int value;
    struct bst *left;
    struct bst *right;
}bst;

/*
   Dato un albero binario di ricerca (come quello dell’esercizio precedente), 
   si riporti la definizione di visitasimmetrica, anticipata e posticipata, aiutandosi con un esempio.

    Visita simmetrica   ->    l'albero è fatto scorrere per intero partendo dal ramo sx e stampando gli elementi a ritroso
                              in ordine dunque crescente (ramo sx -> root -> ramo dx)
                              
    Visita anticipata   ->    come nel caso precedente si fa scorrere per primo il ramo sx dell'albero ma si stampa ogni nodo visitato
                              direttamente senza attendere di raggiungere un nodo foglia (root -> ramo sx -> ramo dx)
                              
    Visita posticipata  ->    viene visitato per primo il ramo sx poi il ramo dx ed infine la radice (ramo sx -> ramo dx -> root)

    Esempi pratici sotto:
*/

void stampa_bst_simmetrica(bst *root){
    if(root == NULL)
        return;
    
    stampa_bst_simmetrica(root -> left);
    printf("%d ", root -> value);
    stampa_bst_simmetrica(root -> right);
}

void stampa_bst_anticipata(bst *root){
    if(root == NULL)
        return;
    
    printf("%d ", root -> value);
    stampa_bst_anticipata(root -> left);
    stampa_bst_anticipata(root -> right);
}

void stampa_bst_posticipata(bst *root){
    if(root == NULL)
        return;
    
    stampa_bst_posticipata(root -> left);
    stampa_bst_posticipata(root -> right);
    printf("%d ", root -> value);
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
    */

    bst *albero = NULL;

    ord_insert(&albero, 20);

    ord_insert(&albero, 10);
    ord_insert(&albero, 30);

    ord_insert(&albero, 5);
    ord_insert(&albero, 15);
    ord_insert(&albero, 25);
    ord_insert(&albero, 35);

    printf("Simmetrica:\n");
    stampa_bst_simmetrica(albero);

    printf("\nAnticipata:\n");
    stampa_bst_anticipata(albero);
    
    printf("\nPosticipata:\n");
    stampa_bst_posticipata(albero);

    return 0;
}
