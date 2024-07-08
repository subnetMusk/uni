#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int value;
    struct nodo *next;
}nodo;

typedef struct L2E{
    nodo *I;
    nodo *F;
}L2E;

nodo *new_node(int val){
    nodo *new = (nodo *)malloc(sizeof(nodo));
    new -> value = val;
    new -> next = NULL;
    return new;
}

L2E *new_l2e(){
    L2E *new = (L2E*)malloc(sizeof(L2E));
    new -> I = NULL;
    new -> F = NULL;
    return new;
}

void addI(L2E **x, nodo *n){
    if((*x) -> I == NULL){
        (*x) -> I = n;
        (*x) -> F = n;
        return;
    }
    n -> next = (*x) -> I;
    (*x) -> I = n;
    return;
}

void addF(L2E **x, nodo *n){
    if((*x) -> I == NULL){
        (*x) -> I = n;
        (*x) -> F = n;
        return;
    }
    (*x) -> F -> next = n;
    (*x) -> F = n;
    return;
}

void stampa_lista(nodo *ptr){
    if(ptr == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", ptr -> value);
    stampa_lista(ptr -> next);
}

void stampa_l2e(L2E *ptr){
    if(ptr == NULL){
        printf("Null\n");
        return;
    }
    printf("Inizio = %d\n", ptr -> I -> value);
    printf("Lista = ");
    stampa_lista(ptr -> I);
    printf("Fine = %d\n", ptr -> F -> value);
    return;
}

void test(){
    printf("-------------------\n");
    printf("TEST:\n");
    L2E *x = new_l2e();
    addI(&x, new_node(1));
    addI(&x, new_node(2));
    addF(&x, new_node(3));
    addF(&x, new_node(4));
    addI(&x, new_node(0));
    stampa_l2e(x);
    printf("-------------------\n");
    return;
}

int main(int argc, char** argv){
    test();

    L2E *list = new_l2e();
    int val = -1;
    do{
        printf("Inserire il valore da immettere nella lista: (-1 per terminare): ");
        scanf(" %d", &val);
        if(val == -1)
            break;
        
        char scelta[1];
        printf("Inserire in testa o coda (t/c): ");
        scanf(" %c", scelta);
        switch(*scelta){
            case 't':
                addI(&list, new_node(val));
                stampa_l2e(list);
                break;
            case 'c':
                addF(&list, new_node(val));
                stampa_l2e(list);
                break;
            default:
                printf("Errore nell'inserimento della scelta!\n");
                break;
        }
    }while(val != -1);

    return 0;
}
