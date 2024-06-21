// Calcolare media, mediana e moda dell'array 

#include <stdio.h>
#include<array/array.h> //attenzione ad includerlo giusto
#include<time.h>
#include<stdlib.h>

#define SIZE 99

void popola_array(int arr[]){
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++)
        arr[i] = rand()%(9) + 1;
    return;
}

void stampa_array_l(int a[]){
    for(int i = 0; i < SIZE; i++){
        printf("%d ", a[i]);
        if(i != 0 && !((i + 1) % 9))
            printf("\n");
    }
    printf("\n");
    return;
}

void mean(const int ans[]){
    printf("La media di tutte le risposte è: ");
    double sum = 0;
    for(int i = 0; i < SIZE; i++)
        sum += ans[i];
    printf("%.0f / %d = %f\n", sum, SIZE, sum / SIZE);
    return;
}

void median(int ans[]){
    printf("La mediana dell'array è ");
    //prendo l'elemento centrale dell'array ordinato (se dim è pari faccio la media tra i due elementi centrali)
    int e = 0;
    if(SIZE % 2){
        e = (int)SIZE / 2;
        printf("l'elemento %d dell'array risposte [%d]\n", e, ans[e]);
    }
    else{
        e = (int)(SIZE - 1) / 2;
        int e1 = e + 1;
        printf("la media degli elementi %d e %d dell'array risposte [%.3f]\n", e, e1, (double)(ans[e] + ans[e1]) / 2.0);
    }
        
    return;
}

void mode(int ans[]){
    int frequenza[9];
    for(int i = 0; i < 9; i++){
        frequenza[i] = 0;
    }

    for(int i = 0; i < SIZE; i++)
        frequenza[ans[i] - 1]++;
    
        
    printf("%-15s%-15s%-5s%-s\n", "Response", "Frequency", "", "Bar Chart");
    for(int i = 0; i < 9; i++){
        printf("%8d%9d%-5s", i+1, frequenza[i], "");
        for(int j = 0; j < frequenza[i]; j++)
            printf("*");
        printf("\n");
    }

    return;
}

int main(int argc, char **argv){
    //array response --> 99 risposte (risposta = n intero da uno a 9)
    int response[SIZE];
    popola_array(response);
    printf("Array non ordinato:\n");
    stampa_array_l(response);

    quicksort(response, 0, SIZE - 1);

    printf("Array ordinato:\n");
    stampa_array_l(response);

    mean(response);
    median(response);
    mode(response);
    return 0;
}
