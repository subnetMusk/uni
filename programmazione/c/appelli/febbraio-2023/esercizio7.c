#include<stdio.h>
#include<stdlib.h>

/*
    Scrivere una funzione 'search()' ricorsiva che dato un bst e un numero intero ritorni:
        1 -- se tale valore è presente nel bst
        0 -- altrimenti

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

int search(bst *ptr, int val){
    if(ptr == NULL)
        return 0;

    if(ptr -> value == val)
        return 1;
    
    if(val < ptr -> value)
        return search(ptr -> left, val);
    else
        return search(ptr -> right, val);
}

int main(int argc, char **argv){
    /*
                    20
            10              30
        5       15      25      35
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

    printf("\nIl valore 10 è presente nell'albero? %d\n", search(albero, 10));
    printf("Il valore 30 è presente nell'albero? %d\n", search(albero, 30));
    printf("Il valore 5 è presente nell'albero? %d\n", search(albero, 5));
    printf("Il valore 50 è presente nell'albero? %d\n", search(albero, 50));
    printf("Il valore 80 è presente nell'albero? %d\n", search(albero, 80));


    return 0;
}