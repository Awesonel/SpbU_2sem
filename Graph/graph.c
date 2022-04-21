#include <malloc.h>
#include <stdio.h>
#include "graph.h"

Graph* graph_init(int node_number)
{
    Graph *result = malloc(sizeof(Graph));
    result->count = node_number;
    result->adj_list = (node**)calloc(node_number, sizeof(node*));
    for (int i = 0; i < node_number; ++i)
        result->adj_list[i] = NULL;
    return result;
}

void add_edge(Graph* graph, int begin, int end)
{
    node *temp = graph->adj_list[begin];
    while (temp)
    {
        if (temp->name == end)
        {
            return;
        }
        temp = temp->next;
    }

    temp = graph->adj_list[begin];
    graph->adj_list[begin] = calloc(1, sizeof(node));
    graph->adj_list[begin]->name = end;
    graph->adj_list[begin]->next = temp;
}

void add_arc(Graph* graph, int first_node, int second_node)
{
    add_edge(graph, first_node, second_node);
    add_edge(graph, second_node, first_node);
}

void delete_edge(Graph* graph, int begin, int end)
{
    node *ptr = graph->adj_list[begin];
    if (ptr != NULL)
    {
        if (ptr->name == end)
        {
            node *temp = ptr;
            graph->adj_list[begin] = ptr->next;
            free(temp);
        }
        else
        {
            while(ptr->next != NULL && ptr->next->name != end)
            {
                ptr = ptr->next;
            }
            if (ptr->next != NULL)
            {
                node *temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
            }
        }
    }
}

void print_graph(Graph* graph)
{
    for (int i = 0; i < graph->count; ++i)
    {
        printf("%d: ", i);
        node *temp = graph->adj_list[i];
        while (temp)
        {
            printf("%d ", temp->name);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void delete_graph(Graph** graph)
{
    for (int i = 0; i < (*graph)->count; ++i)
    {
        node *ptr = (*graph)->adj_list[i];
        while (ptr)
        {
            node *temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
    free((*graph)->adj_list);
    free(*graph);
    *graph = NULL;
}

