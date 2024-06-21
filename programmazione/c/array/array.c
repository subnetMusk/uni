void leggi_array(int a[], int dim){
    for(int i = 0; i < dim; i++)
        scanf("%d", (a + i));
    return;
}

void stampa_array(int dim, int a[dim]){
    for(int i = 0; i < dim; i++)
        printf("%d ", a[i]);
    printf("\n");
    return;
}

void incrementa_array(int* A, int length, int x, int pos){
    int array_copia[length];
    for(int i = 0; i < length; i++){
        array_copia[i] = A[i];
    }
    for(int i = pos; i < length; i++){
        A[i + 1] = array_copia[i];
    }
    return;
}


void swap(int a[], int i1, int i2){
    int appoggio = a[i1];
    *(a+i1) = a[i2];
    *(a+i2) = appoggio;
    return;
}


int partition(int A[], int lo, int hi){
    int pivot = A[lo];
    int i = lo - 1, j = hi + 1;
    while(1){
        do
            i++;
        while (A[i] < pivot);

        do
            j--;
        while (A[j] > pivot);

        if(i >= j)
            return j;
        swap(A, i, j);
    }
    return -1;
}

void quicksort(int A[], int lo, int hi){
    if(lo >= 0 && hi >= 0 && lo < hi){
        int p = partition(A, lo, hi);
        quicksort(A, lo, p);
        quicksort(A, p + 1, hi);
    }
    return;
}

int partition_d(int A[], int lo, int hi){
    int pivot = A[lo];
    int i = lo - 1, j = hi + 1;
    while(1){
        do
            i++;
        while (A[i] > pivot);

        do
            j--;
        while (A[j] < pivot);

        if(i >= j)
            return j;
        swap(A, i, j);
    }
    return -1;
}

void quicksort_d(int A[], int lo, int hi){
    if(lo >= 0 && hi >= 0 && lo < hi){
        int p = partition_d(A, lo, hi);
        quicksort_d(A, lo, p);
        quicksort_d(A, p + 1, hi);
    }
    return;
}

unsigned short iscrescente(int a[], unsigned int dim){
    if(dim <= 1)
        return 1;
    if(a[dim - 2] <= a[dim - 1])
        return 1 * crescente(a, dim - 1);
    else
        return 0;
}

unsigned short isdecrescente(int a[], unsigned int dim){
    if(dim <= 1)
        return 1;
    if(a[dim - 2] >= a[dim - 1])
        return 1 * decrescente(a, dim - 1);
    else
        return 0;
}

int confronta_array(int *X, int *Y, int dim){
    for(int i = 0; i < dim; i++){
        if(*(X + i) != *(Y + i))
            return 0;
    }
    return 1;
}

//pre: 1 array di interi e la sua dimensione
//post: l'array risulterà "invertito"
void inverti(int *A, int dim){
    int copia[dim];
    for(int i = 0; i < dim; i++){
        copia[i] = A[dim - 1 - i];
    }
    for(int i = 0; i < dim; i++){
        A[i] = copia[i];
    }
    return;
}

//pre: 1 array di dimensione N
//post: ritorno 1 se l'array è palindromo, 0 altrimenti
int palindromo(int array[], int n){
    int copia[n];
    for(int i = 0; i < n; i++){
        copia[i] = array[i];
    }
    inverti(copia, n);
    return confronta_array(array, copia, n);
}
