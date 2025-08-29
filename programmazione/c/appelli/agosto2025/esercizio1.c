/*
Dato un array di chars in input (da tastiera in esame, qui per semplicità lo inizializzo
direttamente) scrivere una funzione RICORSIVA 'int even1runs(char *s)' che restituisca:
    true se:
        non contiene elementi = '1'
        l'array contiene occorrenze di elementi='1' disposte in maniera contigua e a gruppi pari

    false:
        altrimenti

Per esempio:
    - v = [0 1 1 0 1 1 0], f(v)=1
    - w = [0 0 0 0 0 0 0], f(w)=1
    - t = [1 1 1 1 0 0 0], f(t)=1

    - x = [0 0 1 0 0 1 1], f(x)=0
    - y = [1 1 1 1 1 1 1], f(y)=0
    - z = [0 0 0 1 1 1 0], f(z)=0

    (assumo che:
        - vi sia il carattere terminatore alla fine dell'array
        - f('\0')=true
        - gli elementi in ingresso siano tutti '1' oppure '0', non ritorno dunque particolari errori
          e/o eccezioni per valori discrepanti
    )

    Si noti che il valore di ritorno (int) della funzione è da interpretarsi come booleano, il valore
    ritornato è pari a:
    k + 2:    con k rappresentante il numero di '1' nel vettore, se il vettore è conforme perché
              la funzioni ritorni true

    0:        da interpretarsi come false, per indicare che il vettore non è conforme alle
              specifiche dichiarate in precedenza

*/

#include <stdio.h>

// lo uso per tenere traccia delle chiamate ricorsive e aggiungere una condizione aggiuntiva
// sul primo elemento del vettore (che sarà poi quello il cui res tornerà al main)
int counter = 0;

//PRE: un puntatore a un array di char con terminatore '\0' ed elementi=('0'||'1').
//     l'array PUÒ essere vuoto
int even1runs(char *s) {
    if (*s == '\0')
        return 2;

    counter = counter + 1;
    const int succ = even1runs(s + 1);
    counter = counter - 1;

    if (succ == 0)
        return 0;

    if (!(succ % 2)) {
        if (*s == '1') {
            if (counter == 0)
                return 0;

            return succ + 1;
        }
        return succ;
    }

    if (*s == '0')
        return 0;

    return succ + 1;
}
//POST: un valore intero da interpretarsi come booleano (0=false, else=true).
//      se l'array contiene gruppi SOLO pari di elementi contigui uguali a '1' viene ritornato
//      k + 2 dove k è il numero totale di '1' presenti nell'array (k può essere 0)
//      altrimenti 0

int main(void) {
    char p[11] = {'0', '1', '1', '1', '1', '0', '1', '1', '0', '0', '\0'}; // pari: 4
    char d[11] = {'0', '1', '1', '0', '0', '0', '1', '1', '1', '0', '\0'}; // dispari: 3

    char v[1] = {'\0'};
    char n[4] = {'0', '0', '0', '\0'};
    char t[4] = {'1', '1', '1', '\0'};
    char t1[5] = {'1', '1', '1', '1', '\0'};

    printf("p è pari? %s \n", even1runs(p) ? "SI" : "NO"); // SI
    printf("d è pari? %s \n", even1runs(d) ? "SI" : "NO"); // NO

    printf("v è pari? %s \n", even1runs(v) ? "SI" : "NO"); // SI
    printf("n è pari? %s \n", even1runs(n) ? "SI" : "NO"); // SI
    printf("t è pari? %s \n", even1runs(t) ? "SI" : "NO"); // NO
    printf("t1 è pari? %s \n", even1runs(t1) ? "SI" : "NO"); // SI
    return 0;
}