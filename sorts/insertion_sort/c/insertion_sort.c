#include <stdio.h>

void insertionSort(int vetor[], int n) { 
    int i; 
    int j;
    int valor;
    
    for (i = 1; i < n; i++) { 
        valor = vetor[i]; 
  
        for (j=i-1; j>=0 && vetor[j]>valor; j--) vetor[j+1] = vetor[j];

        vetor[j + 1] = valor; 
    }
}

void recursiveInsertionSort(int vetor[], int n) {
    if (n<=1) return;

    recursiveInsertionSort(vetor, n-1);

    int valor = vetor[n-1];
    int j;

    for (j=n-2; j>=0 && vetor[j]>valor; j--) vetor[j+1] = vetor[j];

    vetor[j+1] = valor;
}

int main() {
    int vetor[5] = {5, 4, 3, 1, 2};

    for (int i=0; i<5; i++) printf("%d ", vetor[i]);
    printf("\n");

    recursiveInsertionSort(vetor, 5);

    for (int i=0; i<5; i++) printf("%d ", vetor[i]);
    printf("\n");

    return 0;
}