#include <stdio.h>

/*
    Funzione che riduce una frazione ai minimi termini
*/

//pre: puntatore a due interi, rispettivamente numeratore e denominatore della frazione
//post: i parametri passati alla funzione rappresentati numeratore e denominatore 
//      modificati per rappresentare la frazione ai minimi termini
void minimi_termini(int *num, int *den){
    if(*num == 1 || *num == 0 || *den == 1 || *den == 0)
        return;

    int flag = 0;
    if((*num < 0 && *den > 0) || (*num > 0 && *den < 0)){
        flag = 1; //se solamente uno dei due e' negativo vuol dire che il risultato dovra essere negativo
    }


    // per ssemplicita lavoro con numeri positivi
    if(*num < 0)
        *num *= -1;
    if(*den < 0)
        *den *= -1;

    //trovo il minimo tra num e den
    int min = *num;
    if(*num > *den)
        min = *den;

    //cerco di dividere num e den per uno stesso numero i partendo da min{num, den} fino ad arrivare a 2 (decrementando i)
    for(int i = min; i >= 2; i--){
        while(!(*num % i) && !(*den % i)){
            *num /= i;
            *den /= i;
        }
    }

    //se la frazione era negativa reimposto uno dei due numeri (num o den indifferentemente) a negativo
    if(flag)
        *num *= -1;

    return;
}


int main() {
          
    int num, den;
    scanf("%d", &num);
    scanf("%d", &den);
    printf("%d/%d=", num, den);

    // INVOCARE QUA MINIMI_TERMINI()
    minimi_termini(&num, &den);
    //

    printf("%d/%d\n", num, den);

    return 0;
}
