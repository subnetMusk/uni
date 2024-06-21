// Restituisce l'esponente e massimo per cui f^e divide n. Se f non divide n ritorna 0
// Pre: n >=0, f > 1
int fattore_primo(int n, int p){
    int count = 0;
    while(!(n % p)){
        if(!(n % p)){
            count++;
            n /= p;
        }
    }
    return count;
}

// Se il numero n è primo ritorna 1 (true), altrimenti ritorna 0 (false)
// Pre: n > 0
int verifica_primo(int n){
    int d = 0;
    for(int i = 2; i < (n / 2) + 1; i++){
        if(!(n % i))
            return 0;
    }
    return 1;
}

// Restituisce il valore massimo tra n1, n2, n3
int max(int n1, int n2, int n3){
    if(n1 >= n2){
        if(n1 >= n3)
            return n1;
        else
            return n3;
    }
    else{
        if(n2 >= n3)
            return n2;
        else
            return n3;
    }
}

// Restituisce il numero "base" elevato alla potenza indicata da "esponente"
// Pre: esponente >= 0
int potenza(int base, int esponente){
    if(esponente == 0)
        return 1;
    if(esponente == 1)
        return base;
    return base * potenza(base, esponente - 1);
}
