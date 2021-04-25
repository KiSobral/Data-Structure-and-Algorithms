#include <stdio.h>
#include <stdlib.h>


// Edge funcs
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


// Node funcs
typedef struct node {
    int v;
    struct node* next;
} Node;
typedef Node* link;

link NEW(int v, link next){
    link noh = malloc(sizeof(struct node));
    noh->v = v;
    noh->next = next;
    return noh;
}


// Graph funcs
struct graph {
    int v;
    int e;
    link *adj;
};
typedef struct graph* Graph;

Graph GRAPHinit(int vNum){
    Graph g = malloc(sizeof(struct graph));
    g->v = vNum;
    g->e = 0;
    g->adj = (link *) malloc(sizeof(link) * vNum);
    for (int i=0; i<vNum; i++) g->adj[i] = NULL;
    return g;
}

void GRAPHinsertE(Graph g, Edge e) {
    int v=e.v, w=e.w;
    g->adj[v] = NEW(w, g->adj[v]);
    g->adj[w] = NEW(v, g->adj[w]);
    g->e++;
}

// void GRAPHremoveE(Graph g, Edge e) {
//     int v=e.v, w=e.w;
// }

int GRAPHedges(Graph g, Edge e[]){
    int v, E=0;
    link t;
    for (v=0; v<g->v; g++){
        for (t=g->adj[v]; t!=NULL; t=t->next){
            if (v < t->v) e[E++] = EDGE(v, t->v);
        }
    }
    return E;
}
// Graph GRAPHcopy(Graph g);
void GRAPHdestroy(Graph g) {
    link t;
    for (int i=0; i<g->v; i++){
        t = g->adj[i];

        while(t!=NULL){
            link aux = t;
            t=t->next;
            free(aux);
        }
    }
    free(g->adj);
    free(g);
}

int main() {
    Graph g = GRAPHinit(5);

    for (int i=0; i<5; i++){
        if (g->adj[i] == NULL) printf("Deu tudo certo na %d\n", i);
        else printf("Deu errado na %d\n", i);
    }

    GRAPHdestroy(g);
    

    return 0;
}
