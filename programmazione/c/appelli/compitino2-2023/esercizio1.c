#include <stdio.h>
/*
    Scrivere una funzione ricorsiva che dati 2 array A e B ritorni 
        1 -- se tutti gli elementi di A (anche con segno inverso) sono contenuti in B nello stesso ordine
        0 -- altrimenti
*/

//PRE: 2 array di interi A e B e le rispettive dimensioni (int)
int array_stesso_ordine(int A[], int dimA, int B[], int dimB){
    if(dimB < 1 || dimA < 1)
        return 0;

    if(*A == *B || (*A * -1) == *B){
        if(dimA != 1)
            return array_stesso_ordine(A + 1, dimA - 1, B, dimB);
        else
            return 1;
    }
    else{
        return array_stesso_ordine(A, dimA, B + 1, dimB - 1);
    }
}
/*
POST: la funzione esegue ricorsivamente il controllo se Ai (o Ai * -1) (primo elemento di A da trovare in B) è uguale
    a Bj (elemento dell'array B puntato attualmente). Se (Ai || Ai * -1) == Bj scorro l'array A chiamando dunque la
    funzione su A(i+1) altrimenti scorro l'array B controllando dunque (Ai || Ai * -1) == B(j+1)

    Se dimB < 1 --> non avrò trovato tutti gli elementi (o inversi) di A in B, ritornerò dunque 0

    Se trovo l'ultimo elemento di A (o il suo inverso) in B, prima di aver scorso quest'ultimo interamente, ritorno 1
    
*/
int main(int argc, char**argv){
    int c = 0;

    int A[2] = {0, 1};
    int B[5] = {0, -1, 2, 4, 8};

    printf("C[%d] --> %d\n", c, array_stesso_ordine(A, 2, B, 5)); //1

    int C[3] = {-5, 0, 1};
    int D[5] = {0, -1, 2, 4, 8};
    c+=1;
    printf("C[%d] --> %d\n", c, array_stesso_ordine(C, 3, D, 5)); //0

    int E[3] = {-5, 0, 1};
    int F[5] = {0, -1, 5, 4, 8};
    c+=1;
    printf("C[%d] --> %d\n", c, array_stesso_ordine(E, 3, F, 5)); //0

    int G[1] = {1};
    int H[5] = {0, -1, 2, 4, 8};
    c+=1;
    printf("C[%d] --> %d\n", c, array_stesso_ordine(G, 1, H, 5)); //1

    int I[3] = {-5, 0, 1};
    int J[3] = {2, 4, 8};
    c+=1;
    printf("C[%d] --> %d\n", c, array_stesso_ordine(I, 3, J, 3)); //0

    int K[0] = {};
    int L[5] = {0, -1, 2, 4, 8};
    c+=1;
    printf("C[%d] --> %d\n", c, array_stesso_ordine(K, 0, L, 5)); //0

    int M[3] = {-5, 0, 1};
    int N[0] = {};
    c+=1;
    printf("C[%d] --> %d\n", c, array_stesso_ordine(M, 2, N, 0)); //0
    
    return 0;
}
