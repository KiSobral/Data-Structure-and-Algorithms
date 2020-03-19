#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

struct AdjList {
    struct AdjListNode* head;
} AdjList;

struct Graph {
    int num_of_edges;
    struct AdjList* array;
} Graph;

struct AdjListNode* newAdjListNode(int dest) { 
    struct AdjListNode* new_node = malloc(sizeof(struct AdjListNode)); 
    
    new_node->dest = dest; 
    new_node->next = NULL; 
    
    return new_node; 
} 

struct Graph* createGraph(int num_of_edges) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->num_of_edges = num_of_edges;

    graph->array = malloc(num_of_edges * sizeof(struct AdjList));

    for (int i=0; i<num_of_edges; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int from, int dest) { 
    struct AdjListNode* new_node = newAdjListNode(dest); 
    new_node->next = graph->array[from].head; 
    graph->array[from].head = new_node; 
  
    new_node = newAdjListNode(from); 
    new_node->next = graph->array[dest].head; 
    graph->array[dest].head = new_node; 
} 

void printGraph(struct Graph* graph) 
{ 
    int v; 
    for (v = 0; v < graph->num_of_edges; v++) 
    { 
        struct AdjListNode* pCrawl = graph->array[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // create the graph given in above fugure 
    int V = 5; 
    struct Graph* graph = createGraph(V); 
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
  
    // print the adjacency list representation of the above graph 
    printGraph(graph); 
  
    return 0; 
} 