#include<stdio.h>

//restituisce il valore del triangolo magico ad x, y
int S(int x, int y){ //con input troppo grandi va in stack overflow 
    if(x == 0 && y == 0)
        return 1;
    if(x < 0 || y < 0 || y > x)
        return 0;
    return T(x - 1, y) + T(x - 1, y - 1);
}

int T(int x, int y){
    if(x == 0 && y == 0)
        return 1;
    if(x == 0 && y > 0)
        return 0;
    if(x > 0 && y == 0)
        return T(x - 1, y);
    return T(x - 1, y) + T(x - 1, y - 1);
}

/*
    T() ed S() dati gli stessi input (pre-> x, y >= 0) producono lo stesso output (n >= 0)
*/

int main(int argc, char** argv){
    int dim = 6;
    printf("TRIANGOLO MAGICO:\n");
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++)
            printf("%5d", T(i, j));
        printf("\n");
    }

    return 0;
}
