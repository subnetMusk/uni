#include<stdio.h>
#include<alberi.h> //attenzione

int main(int argc, char **argv){
    bst *albero = NULL;
    int c = 0;
    popola_ordinato(&albero);

    stampa_bst_2(albero);
    stampa_bst(albero);
    printf("\n");
    
    delete_node(&albero, 40);
    printf("\n\ncancellato 40\n");
    stampa_bst_2(albero);
    stampa_bst(albero);

    delete_node(&albero, 55);
    printf("\n\ncancellato 55\n");
    stampa_bst_2(albero);
    stampa_bst(albero);

    delete_node(&albero, 50);
    printf("\n\ncancellato 50\n");
    stampa_bst_2(albero);
    stampa_bst(albero);

    printf("\n");

    return 0;
}
