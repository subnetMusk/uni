#include<stdio.h>
#include<stdlib.h>
/*
Si scriva una funzione ricorsiva che riceve un albero binario e determina il nodo a profondità 
minima che abbia al più 1 figlio. La funzione deve restituire la profondità di questo nodo.
*/

typedef struct bst{
    int value;
    struct bst *left;
    struct bst *right;
}bst;

bst *new_node_bst(int val){
    bst *new = malloc(sizeof(bst));
    new -> value = val;
    new -> left = NULL;
    new -> right = NULL;
    return new;
}

void ord_insert(bst **pptr, int val){
    if(*pptr == NULL){
        (*pptr) = new_node_bst(val);
        return;
    }

    if((*pptr) -> value > val)
        ord_insert(&((*pptr) -> left), val);
    else
        ord_insert(&((*pptr) -> right), val);
}

int minore(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int calcola_profondita(bst *ptr){
    if(ptr == NULL)
        return 0;
    
    if((ptr -> left == NULL && ptr -> right != NULL) || (ptr -> left != NULL && ptr -> right == NULL))
        return 0;
    
    return 1 + minore(calcola_profondita(ptr -> left), calcola_profondita(ptr -> right));
}

int main(int argc, char **argv){
    bst *albero = NULL;

    /* non è l'albero dell'esempio ma credo vada bene uguale
    
                            20
                    10             null
    */

    ord_insert(&albero, 20);
    ord_insert(&albero, 10);
    printf("Profondità --> %d\n", calcola_profondita(albero)); //exp: 0


   /*
                        20
            10                      40
        5       15             35       null

    */

    ord_insert(&albero, 40);
    ord_insert(&albero, 5);
    ord_insert(&albero, 15);
    ord_insert(&albero, 35);

    printf("Profondità --> %d\n", calcola_profondita(albero)); //exp: 1

    ord_insert(&albero, 2);
    ord_insert(&albero, 7);
    ord_insert(&albero, 12);
    ord_insert(&albero, 17);
    ord_insert(&albero, 33);
    ord_insert(&albero, 37);
    ord_insert(&albero, 45);

    printf("Profondità --> %d\n", calcola_profondita(albero)); //exp: 3

    ord_insert(&albero, 44);
    ord_insert(&albero, 46);

    printf("Profondità --> %d\n", calcola_profondita(albero)); //exp: 4

    return 0;
}
