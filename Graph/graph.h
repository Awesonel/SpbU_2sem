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
} Graph;

// Инициализация графа
Graph* graph_init(int node_number);

// Добавить направленное ребро из begin в end
void add_edge(Graph* graph, int begin, int end);

// Добавить ненаправленное ребро (дугу) между first_node и second_node
void add_arc(Graph* graph, int first_node, int second_node);

// Удалить ребро из begin в end
void delete_edge(Graph* graph, int begin, int end);

// Печать графа
void print_graph(Graph* graph);

// Удаление графа
void delete_graph(Graph** graph);

#endif //GRAPH_GRAPH_H
