#include<stdio.h>
#include<stdlib.h>

/*
    Il secondo problema riguarda invece una forma di pattern matching in cui sono ammessi 
    errori come spiegato dal seguente esempio: 
    siano T= “abbabab” e P=”aab”, rispettivamente  il testo ed il pattern da cercare nel testo. Ci 
    sono 2 match di P in T, il primo considera T[0]=’a’, T[3]=’a’ e T[4]=’b’, mentre il secondo 
    match considera T[3]=’a’, T[5]=’a’ e T[6]=’b’. La distanza di un match è la misura dei 
    “buchi” che lascia tra i match in T dei successivi caratteri di P. Quindi nel nostro esempio, la 
    distanza del primo match è: (3-0-1)+(4-3-1)=2, mentre quella del secondo match è: (5-3-
    1)+(6-5-1)=1. Si osservi che un match che non lascia buchi, cioè in T[i], T[i+1] e T[i+2], ha 
    distanza (i+1-i-1)+(i+2-(i+1)-1)=0. 
    
    Si chiede di scrivere una funzione che riceve T e P e le loro dimensioni come parametri e 
    che calcola se esiste un match di P in T, e in questo caso trova il match di distanza minima 
    restituendo appunto la sua distanza e la posizione di T in cui il match ha inizio.  
    Nel nostro esempio la funzione richiesta dovrebbe calcolare: true (c’è match), 1 e 3 (in T[3] 
    inizia il match migliore, cioè quello con distanza 1).
*/

typedef struct match{
    int dist;
    int index;
}match;

int lung_stringa(char *s){
    if(*s == '\0')
        return 0;
    return 1 + lung_stringa(s+1);
}

void inizializza_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        *(A + i) = -1;
    return;
}

int calcola_distanza(int *index, int dim){
    if(dim < 2)
        return 0;
    int distanza = 0;
    for(int i = 1; i < dim; i++){
        distanza += (index[i] - index[i - 1] - 1);
    }
    return distanza;
}

 match *find_match(char *T, char *P, int dimT, int dimP){
    if(dimT < dimP)
        return 0;
    
    int ind[dimP];
    int count = 0;
    int min_dist = -1;
    
    match *m = malloc(sizeof(match));
    m -> index = -1;
    m -> dist = -1;

    //cerchiamo il primo carattere di p in t
    for(int i = dimT - dimP; i >= 0; i--){
        count = 0;
        inizializza_array(ind, dimP);
        if(T[i] == *P){
            ind[count] = i;
            count++;
            //trovato il primo carattere di p cerchiamo ora gli altri
            for(int j = i + 1; j < dimT && (count < dimP); j++){
                if(T[j] == P[count]){
                    ind[count] = j;
                    count++;
                }
            }
            if(count == dimP){
                int distanza = calcola_distanza(ind, dimP);
                if(min_dist == -1 || distanza < min_dist){
                    min_dist = distanza;
                    m -> index = ind[0];
                    m -> dist = distanza;
                }
            }
        }
    }
    return m;
}

void stampa_match(match *ptr){
    if(ptr == NULL || ptr -> dist == -1){
        printf("Match non trovato!\n");
        return;
    }

    printf("Match con distanza minore (%d) inizia a %d.\n", ptr -> dist, ptr -> index);
    return;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");
    char T[7] = "abbabab";
    int dimT = 7;
    char P[3] = "aab";
    int dimP = 3;
    printf("T: %s // P: %s \n", T, P);

    match *match = find_match(T, P, dimT, dimP);
    printf("Expected: Match con distanza minore (1) inizia a 3.\n");
    stampa_match(match);
    printf("-------------------\n\n");
    return;
}

int main(int argc, char** argv){
    test();

    char T[100];
    printf("Inserire T (max 100 caratteri): ");
    scanf("%s", T);

    char P[100];
    printf("Inserire P (max 100 caratteri): ");
    scanf("%s", P);

    int dimT = lung_stringa(T);
    int dimP = lung_stringa(P);

    match *match = find_match(T, P, dimT, dimP);
    stampa_match(match);
    return 0;
}
