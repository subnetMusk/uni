//non mi ricordo se l'ho effettivamente risolto, in caso si lascia la risoluzione al lettore

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void stampa_array(int d, int a[d]){
    for(int i = 0; i < d; i++){
        printf("%d", a[i]);
        if(i != d - 1)
            printf(" ");
    }
    return;
}

int main() 
{
    int n;
    scanf("%d", &n);

  	// Complete the code to print the pattern.
    int dim = (n * 2) - 1;
    int array[dim];

    for(int i = 0; i < (n * 2) - 1; i++){
        for(int j = 0; j < (n * 2) - 1; j++){
            if(i == 0 || i == (n * 2) - 2){
                for(int i = 0; i < dim; i++){
                    array[i] = n;
                }
            }
            else{
                if(j >= i)
                    array[j]--;
                if(j >= (n * 2 - 1) - i)
                    array[j]++;
            }
        }
        stampa_array(dim, array);
        printf("\n");
    }

    return 0;
}
