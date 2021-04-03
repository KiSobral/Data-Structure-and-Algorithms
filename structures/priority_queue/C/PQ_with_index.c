#include <stdio.h>
#include <stdlib.h>

typedef int Item;

Item *data;

typedef struct pq_ist {
    int N;   // Tamanho da fila de prioridade
    int *pq; // Fila de prioridades, armazena os índices de um conjunto de itens
    int *qp; // Armazena a posição da heap para o elemento de índice K do conjunto de itens. Algo parecido como uma "hash"
} pq_ist;

int less(pq_ist *PQ, int A, int B){
    return (data[PQ->pq[A]] < data[PQ->pq[B]]);
}

void exch(pq_ist *PQ, int i, int j){
    // qp exch
    int t;
    t         = PQ->qp[i]; 
    PQ->qp[i] = PQ->qp[j];
    PQ->qp[j] = t;

    // pq exch
    PQ->pq[PQ->qp[i]] = i;
    PQ->pq[PQ->qp[j]] = j;
}

// swim -> Bottom-Up Heapify
void fixUp(pq_ist *PQ, int k){
    while (k>1 && less(PQ, k/2, k)){
        exch(PQ, PQ->pq[k], PQ->pq[k/2]);
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
            exch(PQ, PQ->pq[k], PQ->pq[j]);
            k=j;
        }
    }
}

void PQinit(pq_ist *PQ, int MAX){
    PQ->N = 0;
    PQ->pq = malloc(sizeof(pq_ist) * (MAX+1));
    PQ->qp = malloc(sizeof(pq_ist) * (MAX+1));
}

int PQempty(pq_ist *PQ){
    return PQ->N == 0;
}

void PQinsert(pq_ist *PQ, int k){
    PQ->qp[k] = ++PQ->N;
    PQ->pq[PQ->N] = k;
    fixUp(PQ, PQ->N);
}

Item PQdelMax(pq_ist *PQ){
    exch(PQ, PQ->pq[1], PQ->pq[PQ->N]);
    PQ->N--;
    fixDown(PQ, 1);
    return data[PQ->pq[PQ->N+1]];
}

void PQchange(pq_ist *PQ, int k){
    fixUp(PQ, PQ->qp[k]);
    fixDown(PQ, PQ->qp[k]);
}

int main() {
    data = malloc(sizeof(Item)*5);
    data[0]=100; data[1]=90; data[2]=93; data[3]=97; data[4]=79;

    pq_ist *PQ = malloc(sizeof(pq_ist));
    PQinit(PQ, 5);
    PQinsert(PQ, 4);
    PQinsert(PQ, 2);
    PQinsert(PQ, 3);

    printf("-----HEAP COM INDICES DO VETOR DATA-----\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", PQ->pq[i]);
    printf("\n");
    printf("-----ARVORE RESGATADA COM OS INDICES DA HEAP-----\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", data[PQ->pq[i]]);
    printf("\n");

    printf("\n-----MUDANÇA DE PRIORIDADE DE 79 PARA 98-----\n");
    data[4] = 98;
    PQchange(PQ, 4);
    printf("-----HEAP COM INDICES DO VETOR DATA-----\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", PQ->pq[i]);
    printf("\n");
    printf("-----ARVORE RESGATADA COM OS INDICES DA HEAP-----\n");
    for (int i=1; i<=PQ->N; i++) printf("%d ", data[PQ->pq[i]]);
    printf("\n");

    free(PQ->pq);
    free(PQ->qp);
    free(PQ);
    return 0;
}

