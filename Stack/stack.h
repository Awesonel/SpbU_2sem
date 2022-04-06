#ifndef TREE_STACK_H
#define TREE_STACK_H

#define INVALID_OPERATION_EXCEPTION -100

struct stack {
    int value;
    struct stack *next;
};

typedef struct stack Stack;

Stack* push(Stack **head, int value);
int get(Stack *head, int *error_code);
int pop(Stack **head, int *error_code);

void print_stack(Stack *head);

#endif //TREE_STACK_H
