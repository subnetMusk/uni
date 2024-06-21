//Esempio di esercizio con le struct

#include<stdio.h>

struct car{
    double time;
    double charge;
};

typedef struct car car;

struct park{
    int tot_cars;
    car cars[100]; //massimo 100 auto
    double tot_time;
    double tot_charges;
};

typedef struct park park;

double calculate_charge(double time){
    if(time >= 24.0)
        return 10.0;
    else if(time < 3.0){
        if(time <= 0.0)
            return 0.0;
        return 2;
    }
    return 2.0 + ((time - 3.0) * 0.5);
}

int main(int argc, char** argv){
    int parcheggi = 0;
    
    do{
        if(parcheggi < 0)
            printf("Il numero di parcheggi non può essere negativo!\n");
        printf("Inserire il numero di parcheggi (>=0): ");
        scanf(" %d", &parcheggi);
    }while(parcheggi < 0);
    
    park parking_lots[parcheggi];

    for(int i = 0; i < parcheggi; i++){
        int counter = 0;
        double time = 10.0;
        parking_lots[i].tot_time = 0;
        parking_lots[i].tot_charges = 0;
        printf("Inserire i tempi di sosta per il parchegggio %d (termina con 0.0, max 100 auto):\n", i+1);
        do{
            if(time < 0.0)
                printf("Il tempo di sosta non può essere negativo!\n");
            printf("Auto %d: ", counter+1);
            scanf(" %lf", &time);
            if(time > 0.0){
                parking_lots[i].cars[counter].time = time;
                parking_lots[i].cars[counter].charge = calculate_charge(time);
                parking_lots[i].tot_time += time;
                parking_lots[i].tot_charges += parking_lots[i].cars[counter].charge;
                counter++;
            }
        }while(time != 0.0 && counter <= 100);
        parking_lots[i].tot_cars = counter;
        printf("\n");
    }

    for(int i = 0; i < parcheggi; i++){
        printf("DATI PER PARCHEGGIO %d:\n", i+1);
        printf("%-10s%10s%10s\n", "Car", "Hours", "Charge");
        for(int j = 0; j < parking_lots[i].tot_cars; j++){
            printf("%-10d%10.1lf%10.2lf\n", j+1, parking_lots[i].cars[j].time, parking_lots[i].cars[j].charge);
        }
        printf("%-10s%10.1lf%10.2lf\n", "TOTAL", parking_lots[i].tot_time, parking_lots[i].tot_charges);
        printf("\n");
    }

    return 0;
}
