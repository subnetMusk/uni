#include <stdio.h>
#include <stdlib.h>

/*
    Il problema da risolvere riguarda il pattern matching. Il testo T è un array di interi che va considerato come 
    una matrice R x C (in cui ogni elemento contiene un intero)  e il pattern da cercare in T è un array P di dimP 
    interi.  Il match parte dalla prima riga di T e cerca in questa riga P[0], se non lo trova passa alla riga 
    successiva. Se invece trova P[0] in T[i] allora  cerca di continuare il match a partire da quella posizione, cioè 
    cerca P[1] in T[i+1] e così via fino a che arrivi alla fine della riga di T oppure il match fallisca. Se a questo 
    punto si è trovato il match di P[0..j] in T[i..i+j], allora si passa alla prossima riga di T, cercando nello stesso 
    modo il match di P[j+1..dimP-1].  L’output da produrre è un array O di R interi  tale che O[k] specifichi 
    quanti elementi di P sono stati trovati nella riga k.

    Esempio: Sia T=[0,0,0,   1,1,2,  2,3,0,  0,0,0,  0,4,5]. Gli spazi servono  solo a mostrare  che T va interpretata 
    come una matrice composta da 5 righe di 3 elementi ciascuna. Quindi R=5 e C=3. Sia P=[1,2,3,4,5,6] e 
    quindi dimP=6. Allora il matching non trova nulla sulla prima riga. Riesce a fare match di P[0]=1 sul primo 
    elemento della seconda riga, ma il matching fallisce immediatamente dopo perché il secondo elemento 
    della seconda riga (cioèT[3+1]) è  1 che  è diverso da P[1]=2. Quindi si passa alla terza riga, dove si riesce a 
    trovare match per  P[1..2]=[2,3]. Visto che P[3]=4 è diverso da T[8]=0,  si passa alla quanta riga, dove non si 
    trova alcun match di P[3..5]  e quindi si passa alla quinta riga in cui si trova il match di P[3..4]=[4,5] .  
    L’output  che va calcolato è O=[0,1,2,0,2] e dice che sulla prima riga non si è trovato nulla, sulla seconda si è 
    trovato P[0], sulla terza P[1..2], sulla quanta nulla, e sulla quinta P[3..4]. Si noti che il match di P non è 
    completo e che la cosa non ha alcuna importanza.  E’ possibile anche avere output O con tutti 0. 
    
    ATTENZIONE: E’ importante capire che quando si cerca il match di P[k..dimP-1] su una riga di T, si deve 
    cercare il primo match di P[k] e, se c’è, da quel punto si deve continuare il match di P[k+1..dimP-1] finché  ha 
    successo e finché la riga non termina.  Se invece il match di T[k] non c’è, si passa alla riga successiva. 
    
    Parte ricorsiva: risolvere il problema appena descritto con una funzione ricorsiva  void FR(int* T, int r, 
    int R, int C, int * P, int dimP, int *O).  Oltre ai parametri dell’esercizio precedente, il parametro r indica la 
    riga da  considerare per il match. La funzione FR può fare uso  di altre funzioni ricorsive.
*/

void inizializza_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        *(A + i) = 0;
    return;
}

void stampa_array(int *A, int dim){
    for(int i = 0; i < dim; i++)
        printf("%d ", *(A + i));
    printf("\n");
    return;
}

void stampa_matrice(int *M, int r, int c){
    for(int i = 0; i < r; i++){
        stampa_array((M + (c * i)), c);
    }
    printf("\n");
}

int match_precedenti(int *A, int dim){
    if(dim == 0)
        return 0;
    return *A + match_precedenti(A + 1, dim - 1);
}

int match_riga_R(int *A, int C, int *P, int dimP, int colonna){
    if(colonna == C || dimP <= 0)
        return 0;
    
    if(*(A + colonna) == *P){
        if(C - colonna > 1 && dimP > 1){
            if(*(A + colonna + 1) == *(P + 1))
                return 1 + match_riga_R(A, C, P + 1, dimP - 1, colonna + 1);
            else
                return 1;
        }
        else
            return 1;
    }
    else
        return match_riga_R(A, C, P, dimP, colonna + 1);
}

void FR(int *T, int R, int C, int *P, int dimP, int *O, int riga){
    if(R == riga)
        return;

    
    //la sezione sottostante (87-95) serve a mantenere invariato P e dimP all'interno delle chiamate ricorsive di questa
    //funzione per poter chiamare la funzione "match_riga_R()" con i valori corretti nel caso tutti i valori di
    //P siano gia' stati oggetto di un match
    int *P_attuale;
    int dimP_attuale, match_p = match_precedenti(O, riga);
    if(match_p >= dimP){
        P_attuale = P + (match_p % dimP);
        dimP_attuale = dimP - (match_p % dimP);
    }
    else{
        P_attuale = P + match_p;
        dimP_attuale = dimP - match_p;
    }

    *(O + riga) = match_riga_R((T + (riga * C)), C, P_attuale, dimP_attuale, 0);
    FR(T, R, C, P, dimP, O, riga + 1);
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n\n");
    
    int R = 5;
    int C = 3;
    int T[15] = {
        0,0,0,   
        1,1,2,  
        2,3,0,  
        0,0,0,  
        0,4,5
    };

    int dimP = 5;
    int P[5] = {1, 2, 3, 4, 5};

    int O[R];
    inizializza_array(O, R);

    FR(T, R, C, P, dimP, O, 0);
    printf("Matrice T [%d x %d]:\n", R, C);
    stampa_matrice(T, R, C);

    printf("P[%d]: ", dimP);
    stampa_array(P, dimP);

    printf("\nO[%d]: \nexp = 0 1 2 0 2\nact = ", R);
    stampa_array(O, R);

    printf("-------------------\n");
    return;
}

void leggi_matrice(int *M, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("[%d][%d]: ", i, j);
            scanf(" %d", (M + (c * i) + j) );
        }
    }
    return;
}

int main(int argc, char** argv){
    test();

    int righe = 0;
    do{
        printf("Inserire il numero di righe (> 0): ");
        scanf(" %d", &righe);
        if(righe <= 0)
            printf("Il valore devere essere > 0\n");
    }while(righe <= 0);

    int colonne = 0;
    do{
        printf("Inserire il numero di colonne (> 0): ");
        scanf(" %d", &colonne);
        if(colonne <= 0)
            printf("Il valore devere essere > 0\n");
    }while(colonne <= 0);

    int T[righe * colonne];
    leggi_matrice(T, righe, colonne);

    int dimP = 0;
    do{
        printf("Inserire la dimensione di P (> 0): ");
        scanf(" %d", &dimP);
        if(dimP <= 0)
            printf("Il valore devere essere > 0\n");
    }while(dimP <= 0);

    int P[dimP];
    leggi_matrice(P, 1, dimP);

    printf("\nT[%d x %d]:\n", righe, colonne);
    stampa_matrice(T, righe, colonne);
    printf("P[%d]: ", dimP);
    stampa_array(P, dimP);

    int O[righe];
    inizializza_array(O, righe);

    FR(T, righe, colonne, P, dimP, O, 0);
    printf("O[%d]: ", righe);
    stampa_array(O, righe);

    return 0;
}

/*
    output:
    -------------------
    TEST:

    Matrice T [5 x 3]:
    0 0 0 
    1 1 2 
    2 3 0 
    0 0 0 
    0 4 5 

    P[5]: 1 2 3 4 5 

    O[5]: 
    exp = 0 1 2 0 2
    act = 0 1 2 0 2 
    -------------------
    Inserire il numero di righe (> 0): 4
    Inserire il numero di colonne (> 0): 5
    [0][0]: 1
    [0][1]: 2
    [0][2]: 3
    [0][3]: 0
    [0][4]: 0
    [1][0]: 0
    [1][1]: 0
    [1][2]: 4
    [1][3]: 0
    [1][4]: 0
    [2][0]: 5
    [2][1]: 6
    [2][2]: 1
    [2][3]: 2
    [2][4]: 3
    [3][0]: 1
    [3][1]: 2
    [3][2]: 3
    [3][3]: 0
    [3][4]: 0
    Inserire la dimensione di P (> 0): 6
    [0][0]: 1
    [0][1]: 2
    [0][2]: 3
    [0][3]: 4
    [0][4]: 5
    [0][5]: 6

    T[4 x 5]:
    1 2 3 0 0 
    0 0 4 0 0 
    5 6 1 2 3 
    1 2 3 0 0 

    P[6]: 1 2 3 4 5 6 
    O[4]: 3 1 2 3  
*/
