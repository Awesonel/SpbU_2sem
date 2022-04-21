#ifndef GRAPH_STACK_H
#define GRAPH_STACK_H

#define INVALID_OPERATION_EXCEPTION -101

typedef struct stack
{
    int value;
    struct stack *next;
} Stack;

void push(Stack **head, int value);
int pop(Stack **head);
void delete_stack(Stack **head);

#endif //GRAPH_STACK_H
