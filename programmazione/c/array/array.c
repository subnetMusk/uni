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

void stampaMatrice(int *p, int righe, int colonne){
    printf("matrice[%d][%d]:\n{\n", righe, colonne);
    for(int i = 0; i < righe * colonne; i++){
        printf("%d", *(p + i));
        if(((i + 1) % colonne) || i == 0)
            printf(" ");
        else
            printf("\n");
    }
    printf("}\n");
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
