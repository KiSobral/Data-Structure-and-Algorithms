#include <stdio.h>
#include <stdlib.h>

typedef int Item;

Item *data;

typedef struct pq_ist {
    int N;   // Tamanho da fila de prioridade
    int *heap_index; // Fila de prioridades, armazena os índices de um conjunto de itens
    int *index_to_heap; // Armazena a posição da heap para o elemento de índice K do conjunto de itens. Algo parecido como uma "hash"
} pq_ist;

int less(pq_ist *PQ, int A, int B){
    return (data[PQ->heap_index[A]] < data[PQ->heap_index[B]]);
}

void exch(pq_ist *PQ, int i, int j){
    // index_to_heap exch
    int t;
    t         = PQ->index_to_heap[i]; 
    PQ->index_to_heap[i] = PQ->index_to_heap[j];
    PQ->index_to_heap[j] = t;

    // pq exch
    PQ->heap_index[PQ->index_to_heap[i]] = i;
    PQ->heap_index[PQ->index_to_heap[j]] = j;
}

// swim -> Bottom-Up Heapify
void fixUp(pq_ist *PQ, int k){
    while (k>1 && less(PQ, k/2, k)){
        exch(PQ, PQ->heap_index[k], PQ->heap_index[k/2]);
        k = k/2;
    }
}

// sink -> Up-Bottom Heapify
void fixDown(pq_ist *PQ, int k){
    int j;

    while ((2*k) <= PQ->N){
        j = 2*k;
        if (j<PQ->N && less(PQ, j, j+1)) j++;

        if (!less(PQ, k, j)) break;
        else {
            exch(PQ, PQ->heap_index[k], PQ->heap_index[j]);
            k=j;
        }
    }
}

void PQinit(pq_ist *PQ, int MAX){
    PQ->N = 0;
    PQ->heap_index = malloc(sizeof(pq_ist) * (MAX+1));
    PQ->index_to_heap = malloc(sizeof(pq_ist) * (MAX+1));
}

int PQempty(pq_ist *PQ){
    return PQ->N == 0;
}

void PQinsert(pq_ist *PQ, int k){
    PQ->index_to_heap[k] = ++PQ->N;
    PQ->heap_index[PQ->N] = k;
    fixUp(PQ, PQ->N);
}

Item PQdelMax(pq_ist *PQ){
    exch(PQ, PQ->heap_index[1], PQ->heap_index[PQ->N]);
    PQ->N--;
    fixDown(PQ, 1);
    return data[PQ->heap_index[PQ->N+1]];
}

void PQchange(pq_ist *PQ, int k){
    fixUp(PQ, PQ->index_to_heap[k]);
    fixDown(PQ, PQ->index_to_heap[k]);
}

int main() {
    data = malloc(sizeof(Item)*5);
    data[0]=100; data[1]=90; data[2]=93; data[3]=97; data[4]=79;

    pq_ist *PQ = malloc(sizeof(pq_ist));
    PQinit(PQ, 5);
    PQinsert(PQ, 4);
    PQinsert(PQ, 3);
    PQinsert(PQ, 2);
    PQinsert(PQ, 1);
    PQinsert(PQ, 0);

    printf("---------FORMATO INICIAL DA HEAP--------\n");
    printf("--  HASH COM ÍNDICES DA HEAP  --\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", PQ->heap_index[i]);
    printf("\n");
    printf("-- VALORES RESGATADOS DA HEAP --\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", data[PQ->heap_index[i]]);
    printf("\n");

    printf("\n-----MUDANÇA DE PRIORIDADE DE 97 PARA 61-----\n");
    data[3] = 61;
    PQchange(PQ, 3);
    printf("--  HASH COM ÍNDICES DA HEAP  --\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", PQ->heap_index[i]);
    printf("\n");
    printf("-- VALORES RESGATADOS DA HEAP --\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", data[PQ->heap_index[i]]);
    printf("\n");

    printf("\n-----MUDANÇA DE PRIORIDADE DE 100 PARA 92-----\n");
    data[0] = 92;
    PQchange(PQ, 0);
    printf("--  HASH COM ÍNDICES DA HEAP  --\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", PQ->heap_index[i]);
    printf("\n");
    printf("-- VALORES RESGATADOS DA HEAP --\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", data[PQ->heap_index[i]]);
    printf("\n");

    printf("\n-----MUDANÇA DE PRIORIDADE DE 79 PARA 91-----\n");
    data[4] = 91;
    PQchange(PQ, 4);
    printf("--  HASH COM ÍNDICES DA HEAP  --\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", PQ->heap_index[i]);
    printf("\n");
    printf("-- VALORES RESGATADOS DA HEAP --\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", data[PQ->heap_index[i]]);
    printf("\n\n");

    free(PQ->heap_index);
    free(PQ->index_to_heap);
    free(PQ);
    return 0;
}

