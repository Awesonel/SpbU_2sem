#ifndef GRAPH_BFS_AND_DFS_H
#define GRAPH_BFS_AND_DFS_H
#include "graph.h"

// Проверка на двудольность
// Возвращает массив, в котором значения "1" и "0" - две доли соответственно, или NULL, если граф не двудольный
// (i-ый элемент соответствует i-ому узлу)
int* dfs_check_bipartisanship(Graph* graph);

#endif //GRAPH_BFS_AND_DFS_H
