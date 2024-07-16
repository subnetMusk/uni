#include <stdio.h>
#include <stdlib.h>

/*
    Vogliamo una funzione ricorsiva che, dato un albero r ed un intero n > 0, restituisca 
    il nodo n-esimo dell’albero (secondo l’ordine dell’attraversamento infisso), se c’è, e 
    altrimenti, restituisca 0. Il campo num dei nodi dell’albero può essere molto utile 
    per sapere se il nodo cercato è presente nell’albero e, in caso ci sia, per guidare la 
    ricerca verso questo nodo senza mai visitare sottoalberi inutilmente.
*/

typedef struct bst{
    int value;
    int num;
    struct bst *left;
    struct bst *right;
}bst;

bst *new_node_bst(int val){
    bst *new = (bst *)malloc(sizeof(bst));
    new -> value = val;
    new -> num = 1;
    new -> left = NULL;
    new -> right = NULL;
    return new;
}

void build_bst(bst **r, int x){
    if(*r == NULL){
        *r = new_node_bst(x);
        return;
    }
    bst *tmp = *r;
    int left = 0;
    while(tmp != NULL){
        (tmp -> num)++;
        if(x < tmp -> value){
            if(tmp -> left != NULL)
                tmp = tmp -> left;
            else{
                left = 1;
                break;
            }
        }
        else{
            if(tmp -> right != NULL)
                tmp = tmp -> right;
            else
                break;
        }
    }
    if(left)
        tmp -> left = new_node_bst(x);
    else
        tmp -> right = new_node_bst(x);
    return;
}

//stampo l'albero in maniera più leggibile
void stampa_bst_2(bst *ptr, int rad){
    if(ptr == NULL)
        return;

    if(rad != 1 && ptr -> left == NULL && ptr -> right == NULL)
        return;
    
    printf("\t[%d, %d]\n", ptr -> value, ptr -> num);
    
    if(ptr -> left != NULL)
        printf("[%d, %d]", ptr -> left -> value, ptr -> left -> num);
    else
        printf("NULL");
    if(ptr -> right != NULL)
        printf("\t\t[%d, %d]\n", ptr -> right -> value, ptr -> right -> num);
    else
        printf("\t\tNULL\n");
    
    printf("-------------------\n");

    stampa_bst_2(ptr -> left, 0);
    stampa_bst_2(ptr -> right, 0);
}

bst *trova(bst *ptr, int n){
    if(ptr == NULL || n <= 0 || ptr -> num < n)
        return NULL;

    int sx_num = (ptr -> left != NULL) ? ptr -> left -> num : 0;
    if(n <= sx_num)
        return trova(ptr -> left, n);
    else if(n == sx_num + 1)
        return ptr;
    else
        return trova(ptr -> right, n - (sx_num) - 1);
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");
    //riproduco l'esempio della consegna
    bst *albero = NULL;
    build_bst(&albero, 9);
    build_bst(&albero, 3);
    build_bst(&albero, 4);
    build_bst(&albero, 10);

    printf("Albero originale:\n");
    stampa_bst_2(albero, 1);
    printf("\n\n");

    bst *node = trova(albero , 2);
    printf("Risultato: ");
    (node == NULL) ? printf("Null") : printf("[%d, %d]\n", node -> value, node -> num);

    printf("-------------------\n");
    return;
}


int main(int argc, char **argv){
    test();

    return 0;
}
