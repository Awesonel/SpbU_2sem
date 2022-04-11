#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

typedef struct node
{
    int name;
    struct node *next;
} node;

typedef struct graph
{
    int count;
    node **adj_list;
} graph;

graph* graph_init(int node_number);
void add_edge(graph* graph, int begin, int end);
void delete_edge(graph* graph, int begin, int end);
void print_graph(graph* graph);

void delete_graph(graph** graph);

#endif //GRAPH_GRAPH_H
