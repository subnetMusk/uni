#include <stdio.h>
#include <stdlib.h>

/*

    Dato un valore limite >0, si tratta di leggere dei valori tra 0 e limite  e di calcolarne la somma in una 
    variabile somma contando le letture fatte. Inoltre ogni volta che somma raggiunge o supera limite è 
    richiesto di fare un opportuno output (vedi Esempio successivo), di incrementare un contatore che conta 
    quante volte è stato passato il limite e somma deve ripartire dalla differenza tra somma e limite. 
    Chiameremo avanzo questa quantità. Questo processo deve continuare fino a che vengono fatte  maxLet 
    letture oppure finché il numero di volte che il limite è stato raggiunto o superato  è uguale a maxOver. 
    Limite, maxLet e maxOver sono quantità positive lette dal main dato.

*/

void function(int lim, int maxLet, int maxOver, int *lett, int dimLett){
    int somma = 0, nOver = 0;
    for(int i = 0; i < maxLet && i < dimLett; i++){
        somma += lett[i];
        if(somma >= lim){
            nOver++;
            somma -= lim;
             printf("superamento=%d avanzo=%d\n", nOver, somma);
            if(nOver >= maxOver){
               break;
            }      
        }
    }
    printf("%d superamenti e avanzo=%d\n", nOver, somma);
    return;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");

    int limite = 5;
    int maxLet = 10;
    int maxOver = 3;
    int letture[5] = {2, 2, 2, 5, 4};
    
    function(limite, maxLet, maxOver, letture, 5);

    printf("\n");

    int letture2[10] =  {1, 1, 1, 1, 3, 1, 1, 2, 1, 1};
    function(limite, maxLet, maxOver, letture2, 10);

    printf("-------------------\n");
    return;
}


int main(int argc, char **argv){
    test();

    int limite = -1;
    do{
        printf("Inserire il valore di 'limite' (> 0): ");
        scanf(" %d", &limite);
        if(limite < 1)
            printf("Il valore deve essere > 0\n");
    }while(limite < 1);

    printf("\n");

    int maxLet = -1;
    do{
        printf("Inserire il valore di 'maxLet' (> 0): ");
        scanf(" %d", &maxLet);
        if(maxLet < 1)
            printf("Il valore deve essere > 0\n");
    }while(maxLet < 1);

    printf("\n");

    int maxOver = -1;
    do{
        printf("Inserire il valore di 'maxOver' (> 0): ");
        scanf(" %d", &maxOver);
        if(maxOver < 1)
            printf("Il valore deve essere > 0\n");
    }while(maxOver < 1);

    printf("\n");

    int somma = 0, nOver = 0, valore_letto = 0;
    for(int c = 0; c < maxLet; c++){
        printf("Inserire il valore (somma = %d): ", somma);
        scanf(" %d", &valore_letto);
        somma +=valore_letto;
        if(somma >= limite){
            nOver++;
            somma -= limite;
             printf("superamento=%d avanzo=%d\n\n", nOver, somma);
            if(nOver >= maxOver){
               break;
            }      
        }
    }
    printf("%d superamenti e avanzo=%d\n", nOver, somma);

    return 0;
}
