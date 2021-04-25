#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
    int v;
    int w;
} Edge;

Edge EDGE(int v, int w){
    Edge e;
    e.v = v;
    e.w = w;
    return e;
}

struct graph {
    int v;
    int e;
    int **adj;
};
typedef struct graph* Graph;

Graph GRAPHinit(int vNum) {
    Graph g = (Graph) malloc(sizeof(struct graph));

    g->v = vNum;
    g->e = 0;
    g->adj = (int **) malloc(sizeof(int *) * vNum);
    for (int i=0; i<vNum; i++) g->adj[i] = (int *) calloc(sizeof(int), vNum);

    return g;
}
void GRAPHinsertE(Graph g, Edge e) {
    int v=e.v, w=e.w;
    
    if (g->adj[v][w]==0 || g->adj[w][v]==0) g->e++;

    g->adj[v][w] = 1;
    g->adj[w][v] = 1;
}
void GRAPHremoveE(Graph g, Edge e){
    int v=e.v, w=e.w;
    
    if (g->adj[v][w]==1 || g->adj[w][v]==1) g->e--;

    g->adj[v][w] = 0;
    g->adj[w][v] = 0;
}

int GRAPHedges(Graph g, Edge e[]){
    int v, w, E=0;
    for (v=0; v<g->v; v++){
        for (w=v+1; w<g->v; w++) {
            if (g->adj[v][w]==1) e[E++] = EDGE(v,w);
        }
    }

    return E;
}
// Graph GRAPHcopy(Graph g);

void GRAPHdestroy(Graph g) {
    for (int i=g->v-1; i>=0; i--)free(g->adj[i]);
    free(g->adj);
    free(g);
}