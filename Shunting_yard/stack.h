#ifndef TREE_STACK_H
#define TREE_STACK_H
#define INVALID_OPERATION_EXCEPTION -110
#include "tokens.h"


typedef struct stack {
    char value;
    Token_type type;
    struct stack *next;
} Stack;


void push(Stack **head, char value, Token_type type);
char get(Stack *head);
char pop(Stack **head);

void print_stack(Stack *head);


#endif //TREE_STACK_H
