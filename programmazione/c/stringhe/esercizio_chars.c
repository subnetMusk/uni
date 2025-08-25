//
// Created by Leonardo Soligo on 8/26/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_ones(char* A){
    int count = 0;
    for(int i = 0; *(A + i) != '\0'; i++)
        count += (*(A + i) == '1') ? 1 : 0;
    return count;
}

int main(int argc, char *argv[]) {
    char array[8] = {'0', '0', '1', '1', '1', '0', '1', '\0'}; //4 zeri

    printf("%d\n", count_ones(array));
    return 0;
}