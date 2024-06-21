#include <stdio.h>
#include <assert.h>
#include <string.h>

void stampaStringa(char* s){
    while(*s != '\0'){
        printf("%c", *s);
        s++;
    }
    printf("\n");
    return;
}

int dimensioneStringa(char* s){
    int caratteri = 0;
    while(*s != '\0'){
        caratteri++;
        s++;
    }
    return caratteri;
}

void concatenaStringhe(char* S1, char* S2) {
    for(int i = dimensioneStringa(S1), j = 0; i < dimensioneStringa(S1) + dimensioneStringa(S2); i++, j++){
        *(S1 + i) = *(S2 + j);
    }
    return;
}

void test_concatenaStringhe() {

    char S1[50] = "laboratorio", S2[20] = " programmazione";
    concatenaStringhe(S1, S2);
    assert(strcmp(S1, "laboratorio programmazione")==0); //strcmp confronta due stringhe, restituisce 0 se sono uguali, è definita in string.h

    char S3[20] = "t", S4[20]="est";
    concatenaStringhe(S3, S4);
    assert(strcmp(S3, "test")==0);

    char S5[20] = "passat", S6[20]="o";
    concatenaStringhe(S5, S6);
    assert(strcmp(S5, "passato")==0);

    printf("Tutti i test superati con successo!\n");
}
