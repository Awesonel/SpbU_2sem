#include <malloc.h>
#include <stdio.h>
#include "graph.h"
#include "bfs_and_dfs.h"

int main() {
    Graph* graph = graph_init(4);
    add_arc(graph, 0, 1);
    add_arc(graph, 1, 2);
    add_arc(graph, 3, 0);


    print_graph(graph);
    int *a = dfs_check_bipartisanship(graph);
    if (a == NULL) printf("NULL");
    else
        for (int i = 0; i < graph->count; ++i) printf("%d ", a[i]);

    delete_graph(&graph);
    return 0;
}
