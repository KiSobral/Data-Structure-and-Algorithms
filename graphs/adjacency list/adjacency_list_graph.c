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
