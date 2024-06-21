#include<stdio.h>

int percorso(int dim_x, int dim_y, int pos_y, int pos_x, int campo[dim_x][dim_y]);

int test();

int main(){
    int test_function = test();
    if(test_function == 4)
        printf("TUTTI I TEST SONO STATI PASSATI CON SUCCESSO!");
    else{
        printf("%d test passati: %d%%", test_function, (test_function * 100) / 4);
    }
    
    return 0; 
} 

int test(){
    int test_passati = 0;
    //TEST 1 --> campo vuoto (solo fiori --> no percorso)
    int test1[5][5] = {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };
    int via = percorso(5, 5, 4, 4, test1);
    if(via == 0)
        test_passati++;
    
    //TEST 2 --> campo pieno (nessun fiore --> percorso)
    int test2[5][5] = {
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1
    };
    via = percorso(5, 5, 4, 4, test2);
    if(via > 0)
        test_passati++;
    
    //TEST 3 --> random (con percorso)
    int test3[10][10] = {           
        0, 0, 0, 1, 1, 1, 0, 0, 1, 0,
        1, 0, 1, 0, 1, 0, 0, 1, 0, 1,
        0, 1, 1, 0, 1, 0, 1, 0, 1, 1,
        0, 0, 1, 1, 1, 1, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
        0, 0, 1, 1, 1, 1, 0, 0, 1, 0,
        1, 0, 1, 0, 1, 0, 0, 1, 0, 1,
        0, 1, 1, 0, 1, 0, 1, 0, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 1
    };
    via = percorso(10, 10, 9, 1, test3);
    if(via > 0)
        test_passati++;
    
    //TEST 4 --> random (senza percorso)
    int test4[10][10] = {           
        0, 0, 0, 1, 1, 1, 0, 0, 1, 0,
        1, 0, 1, 0, 1, 0, 0, 1, 0, 1,
        0, 1, 1, 0, 1, 0, 1, 0, 1, 1,
        0, 0, 1, 1, 1, 1, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
        0, 0, 1, 1, 1, 1, 0, 0, 1, 0,
        1, 0, 1, 0, 1, 0, 0, 1, 0, 1,
        0, 1, 0, 0, 1, 0, 1, 0, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 1
    };
    via = percorso(10, 10, 9, 3, test4);
    if(via == 0)
        test_passati++;
    
    return test_passati;
}
