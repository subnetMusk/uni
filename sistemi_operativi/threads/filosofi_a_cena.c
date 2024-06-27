//Leonardo Soligo
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdarg.h>
#if defined(__APPLE__)
    #include<dispatch/dispatch.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#elif defined(__linux__)
    #include <fcntl.h> //non lo uso ma in caso è qua (servirebbe a stampare i messaggi di errore su stdout)
    #include<semaphore.h>
    #include<unistd.h>
#endif

#if defined(__APPLE__)
    typedef struct{
        dispatch_semaphore_t sem;
        unsigned int valore;
    }semaforo;


    //ritorna:
    //0 --> successo // altro --> errore
    int inizializza_semaforo(semaforo *sem, int pshared, unsigned int value){
        sem -> sem = dispatch_semaphore_create(value);
        sem -> valore = value;
        if(!sem -> sem)
            return 1;
        return 0;
    }

    //ritorna:
    //0 --> successo // altro --> errno
    int P(semaforo *sem) {
        return dispatch_semaphore_wait(sem -> sem, DISPATCH_TIME_FOREVER);
    }

    //ritorna:
    //0 --> successo // altro --> errno
    int V(semaforo *sem){
        return dispatch_semaphore_signal(sem -> sem);
    }

    //ritorna:
    //0 --> successo // altro --> errno
    int try_p(semaforo *sem){
        return dispatch_semaphore_wait(sem -> sem, DISPATCH_TIME_NOW);
    }

    //ritorna:
    //0 --> successo // altro --> spero di no
    int destroy_sem(semaforo *sem){
        dispatch_release(sem -> sem);
        return 0;
    }

    //N.B. i colori di output della console dovrebbero essere:
    //thread creato / filosofo pensa --> black
    //filosofo mangia --> green
    //filosofo rilascia fork dopo aver mangiato --> white
    //filosofo non riesce ad accedere alla risorsa / errori vari --> red
    
    //detto ciò è possibile che i colori non sempre vengano rispettati perché 
    //se un thread cambia il colore dell'output mentre un altro sta stampando si sminchia
    void print_green(const char* format, ...){
        printf("\x1b[32m");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\x1b[0m");
    }

    void print_red(const char* format, ...){
        printf("\x1b[31m");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\x1b[0m");
    }

    void print_gray(const char* format, ...){
        printf("\x1b[90m");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\x1b[0m");
    }
#elif defined(_WIN32) || defined(_WIN64)
    //essendo che di semafori su windows non me ne intendo queste le ha scritte chatGPT [non le ho testate btw]
    typedef struct {
        HANDLE sem;
    } semaforo;

    int inizializza_semaforo(semaforo *sem, int pshared, unsigned int value) {
        sem->sem = CreateSemaphore(NULL, value, LONG_MAX, NULL);
        if (sem->sem == NULL) {
            return 1;
        }
        return 0;
    }

    int P(semaforo *sem) {
        DWORD wait_result = WaitForSingleObject(sem -> sem, INFINITE);
        if (wait_result == WAIT_OBJECT_0) {
            return 0;
        } else {
            return GetLastError();
        }
    }

    int V(semaforo *sem) {
        if (ReleaseSemaphore(sem->sem, 1, NULL) == 0) {
            return GetLastError();
        }
        return 0;
    }

    int try_p(semaforo *sem) {
        DWORD wait_result = WaitForSingleObject(sem -> sem, 0);
        if (wait_result == WAIT_OBJECT_0) {
            return 0;
        } else {
            return GetLastError();
        }
    }

    int destroy_sem(semaforo *sem) {
        if (CloseHandle(sem->sem) == 0) {
            return GetLastError();
        }
        return 0;
    }

    void set_console_color(WORD color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

    void reset_console_color() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

    void print_green(const char* format, ...) {
        set_console_color(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        reset_console_color();
    }

    void print_red(const char* format, ...) {
        set_console_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        reset_console_color();
    }

    void print_gray(const char* format, ...) {
        set_console_color(90);
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        reset_console_color();
    }

#elif defined(__linux__)
    typedef sem_t semaforo;

    //ritornano gli stessi valori delle funzioni analoghe per macOS (che ho riscritto per farle funzionare come le POSIX qui sotto)
    int inizializza_semaforo(semaforo *sem, int pshared, int value) {
        return sem_init(sem, pshared, value);
    }

    int P(semaforo *sem) {
        return sem_wait(sem);
    }

    int V(semaforo *sem) {
        return sem_post(sem);
    }

    int try_p(semaforo *sem){
        return sem_trywait(sem);
    }

    int destroy_sem(semaforo *sem) {
        return sem_destroy(sem);
    }

    void print_green(const char *format, ...){
        printf("\033[32m");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\033[0m");
    }

    void print_red(const char *format, ...){
        printf("\033[31m");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\033[0m");
    }

    void print_gray(const char *format, ...){
        printf("\033[90m");
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\033[0m");
    }
#endif


//variabili globali
#define n_filosofi 5
int numero_clicli = 3; //quante volte ogni filosofo deve mangiare 
int completamento[n_filosofi]; //conto quante volte ogni filosofo ha mangiato
semaforo forchette[n_filosofi];

semaforo create; //per assegnare un numero univoco ad ogni filosofo durante la fase di creazione dei threads
int numero_f = 0;


//funzioni
void inizializza_array(int value); //inizializza tutti gli elementi di 'completamento[]' a 'value'

int inizializza_semafori(); //inizializza 'forchette[]'

int distruggi_semafori(); //distrugge 'forchette[]'

void *filosofo(void *arg);


int main(int argc, char ** argv){
    inizializza_array(0);

    //inizializzazione semafori
    if(!inizializza_semafori()){
        print_red("sem_init_error");
        exit(EXIT_FAILURE);
    }
    if(inizializza_semaforo(&create, 0, 1)){
        print_red("sem_init_error");
        exit(EXIT_FAILURE);
    }

    //creazione threads
    pthread_t id[n_filosofi];
    for(int i = 0; i < n_filosofi; i++){
        if(pthread_create(&id[i], NULL, filosofo, NULL)){
            print_red("pthread_create_error");
            exit(EXIT_FAILURE);
        }
    }

    //distruzione threads
    for(int i = 0; i < n_filosofi; i++){
        if(pthread_join(id[i], NULL)){
            print_red("pthread_join_error");
            exit(EXIT_FAILURE);
        }
    }

    printf("\n\nTUTTI I FILOSOFI HANNO MANGIATO E PENSATO ABBASTANZA\n\n");

    //distruzione semafori
    if(!distruggi_semafori()){
        print_red("sem_destroy_error");
        exit(EXIT_FAILURE);
    }
    destroy_sem(&create);

    return 0;
}

void inizializza_array(int value){
    for(int i = 0; i < n_filosofi; i++)
        completamento[i] = value;
    return;
}

int inizializza_semafori(){
    for(int i = 0; i < n_filosofi; i++){
        if(inizializza_semaforo(&forchette[i], 0, 1))
            return 0;
    }
    return 1;   
}

int distruggi_semafori(){
    for(int i = 0; i < n_filosofi; i++){
        if(destroy_sem(&forchette[i]))
            return 0;
    }
    return 1;   
}

void *filosofo(void *arg){
    int numero_filosofo = 0;
    P(&create);
    numero_filosofo = numero_f;
    numero_f++;
    V(&create);

    print_gray("[Filosofo %d] >> creato\n", numero_filosofo);

    while(completamento[numero_filosofo] < numero_clicli){
        if(!try_p(&forchette[numero_filosofo])){
            if(!try_p(&forchette[(numero_filosofo + 1) % n_filosofi])){
                //mangia
                print_green("[Filosofo %d] >> MANGIA (blocca f%d e f%d)(%d volta / %d rimanenti)\n", numero_filosofo, numero_filosofo, (numero_filosofo + 1) % n_filosofi, completamento[numero_filosofo] + 1, (numero_clicli - (completamento[numero_filosofo] + 1)));
                completamento[numero_filosofo]++;
                sleep(1);
                printf("[Filosofo %d] >> RILASCIA f%d e f%d\n", numero_filosofo, numero_filosofo, (numero_filosofo + 1) % n_filosofi);
                V(&forchette[(numero_filosofo + 1) % n_filosofi]);
                V(&forchette[numero_filosofo]);
            }
            else{
                print_red("[Filosofo %d] >> non è riuscito a bloccare f%d, RILASCIA f%d\n", numero_filosofo, (numero_filosofo + 1) % n_filosofi, numero_filosofo);
                V(&forchette[numero_filosofo]);
            }
        }
        else{
            print_red("[Filosofo %d] >> non è riuscito a bloccare f%d\n", numero_filosofo, numero_filosofo);
        }
        if(completamento[numero_filosofo] < numero_clicli){
            //filosofeggia
            print_gray("[Filosofo %d] >> pensa\n", numero_filosofo);
            sleep(2);
        }
    }

    print_green("[Filosofo %d]  ----- HA TERMINATO -----\n\n", numero_filosofo);
    pthread_exit(NULL);
    return NULL;
}
