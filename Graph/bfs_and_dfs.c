#include "bfs_and_dfs.h"
#include <malloc.h>
#include "stack.h"

void fill_array(int *array, int a, int count)
{
    for (int i = 0; i <  count; ++i) array[i] = a;
}

int* dfs_check_bipartisanship(Graph* graph)
{
    int *result = calloc(graph->count, sizeof(int));
    fill_array(result, 2, graph->count);
    Stack *stack = NULL;
    int color = 0;
    push(&stack, 0);
    result[0] = color;
    while (stack)
    {
        color = !color;
        int current_node = pop(&stack);
        node *temp = graph->adj_list[current_node];
        while (temp)
        {
            if (result[temp->name] == 2)
            {
                result[temp->name] = color;
                push(&stack, temp->name);
            }
            else if (result[temp->name] == !color)
            {
                free(result);
                delete_stack(&stack);
                return NULL;
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < graph->count; ++i)
    {
        if (result[i] == 2)
        {
            free(result);
            delete_stack(&stack);
            return NULL;
        }
    }
    return result;
}
