#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define exch(A,B) { Item t=A;A=B;B=t; }

// swim -> Bottom-Up Heapify
void fixUp(Item *v, int k){
    while (k>1 && less(v[k/2], v[k])) {
        exch(v[k], v[k/2])
        k = k/2;
    }
}

// sink -> Up-Bottom Heapify
void fixDown(Item *v, int k, int n){
    int j;

    while (2*k <= n){
        j = 2*k;
        if (j<n && less(v[j], v[j+1])) j++;
        
        if (!less(v[k], v[j])) break;
        else {
            exch(v[k], v[j]);
            k=j;
        }
    }
}

typedef struct pq_st {
    Item *pq;
    int N;
} pq_st;

void PQinit(int maxN, pq_st *PQ){
    PQ->pq = malloc(sizeof(Item) * (maxN+1));
    PQ->N  = 0;
}

int PQempty(pq_st *PQ){
    return PQ->N==0;
}

void PQinsert(pq_st *PQ, Item new){
    PQ->pq[++PQ->N] = new;
    fixUp(PQ->pq, PQ->N);
}

Item PQdelMax(pq_st *PQ){
    exch(PQ->pq[1], PQ->pq[PQ->N]);
    fixDown(PQ->pq, 1, --PQ->N);
    return PQ->pq[PQ->N+1];
}
