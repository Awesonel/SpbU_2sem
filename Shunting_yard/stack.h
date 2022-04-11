#ifndef TREE_STACK_H
#define TREE_STACK_H
#define INVALID_OPERATION_EXCEPTION -110
#include "tokens.h"


typedef struct stack
{
    char value;
    Token_type type;
    struct stack *next;
} Stack_tokens;

typedef struct stack_numbers
{
    int value;
    struct stack_numbers *next;
} Stack_numbers;

void push_number(Stack_numbers **head, int value);
int pop_number(Stack_numbers **head);

void push_token(Stack_tokens **head, char value, Token_type type);
char get_token(Stack_tokens *head);
char pop_token(Stack_tokens **head);

void delete_stack_operations(Stack_tokens **stack);
void delete_stack_numbers(Stack_numbers **stack);

#endif //TREE_STACK_H
