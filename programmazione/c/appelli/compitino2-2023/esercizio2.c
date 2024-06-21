#include<stdio.h>
#include<stdlib.h>

struct bst{
    int value;
    struct bst *right;
    struct bst *left;
};

typedef struct bst bst;

void print_rec(bst *ptr){
    if(ptr != NULL){
        //VISITA SIMMETRICA:
        print_rec(ptr -> left);
        printf("%d", ptr -> value);
        print_rec(ptr -> right);
    }
}

bst *new_node_bst(int val){
    bst *new = malloc(sizeof(bst));
    new -> value = val;
    new -> left = NULL;
    new -> right = NULL;

    return new;
}

void ord_insert(bst **pptr, int val){
    if((*pptr) == NULL){
        (*pptr) = new_node_bst(val);
        return;
    }

    if((*pptr) -> value >= val)
        ord_insert(&((*pptr) -> right), val);
    else
        ord_insert(&((*pptr) -> left), val);
}

int main(int argc, char** argv){
    bst *bst_t = NULL;

    print_rec(bst_t);

    ord_insert(&bst_t, 5);
    ord_insert(&bst_t, 3);
    ord_insert(&bst_t, 7);
    ord_insert(&bst_t, 1);
    ord_insert(&bst_t, 4);
    ord_insert(&bst_t, 7);
    ord_insert(&bst_t, 8);
    ord_insert(&bst_t, 6);

    print_rec(bst_t);

    return 0;
}
