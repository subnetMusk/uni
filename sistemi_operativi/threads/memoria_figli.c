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
    #include <sys/types.h> 
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
        DWORD wait_result = WaitForSingleObject(sem->sem, INFINITE);
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
        DWORD wait_result = WaitForSingleObject(sem->sem, 0);
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
int X = 10;
int Y = 20;
int a;
int b;

semaforo mutex;
semaforo create;
int id_thread = 0;

//funzioni
void *thread(void *arg){
    int id = 0;
    P(&create);
    id = id_thread;
    id_thread++;
    V(&create);
    
    P(&mutex);
    print_green("PREMODIFICA:\n");
    printf("[THREAD %d] VALORE DI X = %d [address: %p]\n", id, X, (void*)&X);
    printf("[THREAD %d] VALORE DI Y = %d [address: %p]\n", id, X, (void*)&Y);
    printf("[THREAD %d] VALORE DI a = %d [address: %p]\n", id, a, (void*)&a);
    printf("[THREAD %d] VALORE DI b = %d [address: %p]\n", id, b, (void*)&b);
    V(&mutex);
    
    P(&mutex);
    a += id + 1;
    b += id + 1;
    print_red("\n\nPOSTMODIFICA:\n");
    printf("[THREAD %d] VALORE DI X = %d [address: %p]\n", id, X, (void*)&X);
    printf("[THREAD %d] VALORE DI Y = %d [address: %p]\n", id, X, (void*)&Y);
    printf("[THREAD %d] VALORE DI a = %d [address: %p]\n", id, a, (void*)&a);
    printf("[THREAD %d] VALORE DI b = %d [address: %p]\n", id, b, (void*)&b);
    V(&mutex);
    
    
    pthread_exit(NULL);
}

int main(int argc, char ** argv){
    a = -10;
    b = -20;

    if(inizializza_semaforo(&create, 0, 1)){
        print_red("sem_init_error");
        exit(EXIT_FAILURE);
    }

    if(inizializza_semaforo(&mutex, 0, 1)){
        print_red("sem_init_error");
        exit(EXIT_FAILURE);
    }

    pthread_t threads[2];
    for(int i = 0; i < 2; i++){
        if(pthread_create(&threads[i], NULL, thread, NULL)){
            print_red("ERRORE NELLA CREAZIONE DEL THREAD %d", i);
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i < 2; i++){
        if(pthread_join(threads[i], NULL)){
            print_red("ERRORE NELLA DISTRUZIONE DEL THREAD %d", i);
            exit(EXIT_FAILURE);
        }
    }

    if(destroy_sem(&create)){
        print_red("ERRORE NELLA DISTRUZIONE DEL SEMAFORO create\n");
        exit(EXIT_FAILURE);
    }


    
    pid_t id_p = fork();

    if(id_p < 0){
        print_red("ERRORE NELLA fork()");
        exit(EXIT_FAILURE);
    }



    if(!id_p){
        P(&mutex);
        print_green("[pid %d] PROCESSO FIGLIO:\nPRE:", getpid());
        printf("VALORE DI X = %d [address: %p]\n", X, (void*)&X);
        printf("VALORE DI Y = %d [address: %p]\n", X, (void*)&Y);
        printf("VALORE DI a = %d [address: %p]\n", a, (void*)&a);
        printf("VALORE DI b = %d [address: %p]\n", b, (void*)&b);

        print_green("\n\n[pid %d] PROCESSO FIGLIO:\nPOST:", getpid());
        X = 1;
        Y = 2;
        a = 3;
        b = 4;
        printf("VALORE DI X = %d [address: %p]\n", X, (void*)&X);
        printf("VALORE DI Y = %d [address: %p]\n", X, (void*)&Y);
        printf("VALORE DI a = %d [address: %p]\n", a, (void*)&a);
        printf("VALORE DI b = %d [address: %p]\n", b, (void*)&b);
        V(&mutex);
    }
    else{
        P(&mutex);
        print_green("[pid %d] PROCESSO PADRE:\nPRE:", getpid());
        printf("VALORE DI X = %d [address: %p]\n", X, (void*)&X);
        printf("VALORE DI Y = %d [address: %p]\n", X, (void*)&Y);
        printf("VALORE DI a = %d [address: %p]\n", a, (void*)&a);
        printf("VALORE DI b = %d [address: %p]\n", b, (void*)&b);

        print_green("\n\n[pid %d] PROCESSO PADRE:\nPOST:", getpid());
    
        printf("VALORE DI X = %d [address: %p]\n", X, (void*)&X);
        printf("VALORE DI Y = %d [address: %p]\n", X, (void*)&Y);
        printf("VALORE DI a = %d [address: %p]\n", a, (void*)&a);
        printf("VALORE DI b = %d [address: %p]\n", b, (void*)&b);
        V(&mutex);
    }
 
    

    destroy_sem(&mutex);

    return 0;
}