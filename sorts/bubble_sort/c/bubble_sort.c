#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(int *v, int n) {

    int flag = 0;

    do {
        flag = 0;

        for (int i=1; i < n; i++) {
            if (v[i-1] > v[i]) {
                swap(&v[i-1], &v[i]);
                flag=1;
            }
        }
    } while (flag);
}

void bubbleSortRec(int *v, int n) {
    if (n==1) return;

    for (int i=1; i<n; i++) {
        if (v[i-1] > v[i]) swap(&v[i-1], &v[i]);
    }
    
    bubbleSortRec(v, n-1);
}

int main() {
    int v[5] = {3, 5, 1, 2, 4};

    printf("Vetor Inicial:\n");
    
    for (int i=0; i<5; i++) printf("%d ", v[i]);
    printf("\n");
    printf("Vetor Ordenado: ");

    bubbleSort(v, 5);

    for (int i=0; i<5; i++) printf("%d ", v[i]);
    printf("\n");
    printf("Vetor Ordenado com Recursão:\n");

    bubbleSortRec(v, 5);

    for (int i=0; i<5; i++) printf("%d ", v[i]);
    printf("\n");

    return 0;
}