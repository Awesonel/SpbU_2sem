#include "graph.h"

int main() {
    graph* graph = graph_init(5);

    add_edge(graph, 0, 3);
    add_edge(graph, 0, 0);
    add_edge(graph, 0, 4);
    add_edge(graph, 0, 2);
    print_graph(graph);
    delete_graph(&graph);
    return 0;
}
