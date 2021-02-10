#include <stdio.h>

int binarySearch(int *v, int alvo, int l, int r){
    while (l <= r) {
        int meio = (l + r) / 2;

        if (v[meio] == alvo) {
            return meio;
        } else if (v[meio] > alvo) {
            r = meio - 1;
        } else if (v[meio] < alvo) {
            l = meio + 1;
        }
    }

    return -1;
}

int binarySearchRec(int *v, int alvo, int l, int r){
    if (l > r) return -1;

    int meio = (l + r) / 2;

    if (v[meio] == alvo) {
        return meio;
    } else if (v[meio] > alvo) {
        binarySearchRec(v, alvo, l, meio-1);
    } else if (v[meio] < alvo) {
        binarySearchRec(v, alvo, meio+1, r);
    }
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};

    printf("Vetor: ");
    for (int i=0; i<5; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("--CASO IMPERATIVO--\n");
    printf("Posição do número 4 no vetor: %d\n", binarySearch(v, 4, 0, 4));
    
    printf("--CASO RECURSIVO--\n");
    printf("Posição do número 5 no vetor: %d\n", binarySearchRec(v, 5, 0, 4));

    return 0;
}