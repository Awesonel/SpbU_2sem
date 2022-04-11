#include "stack.h"
#include <stdio.h>
#include <malloc.h>

void push_token(Stack_tokens **head, char value, Token_type type)
{
    Stack_tokens *new = malloc(sizeof(Stack_tokens));
    new->type = type;
    new->value = value;
    new->next = *head;
    *head = new;
}

char get_token(Stack_tokens *head)
{
    if (head != NULL) return head->value;
    return INVALID_OPERATION_EXCEPTION;
}

char pop_token(Stack_tokens **head)
{
    if (*head != NULL)
    {
        char result = (*head)->value;
        Stack_tokens *temp = *head;
        *head = (*head)->next;
        free(temp);
        return result;
    }
    return INVALID_OPERATION_EXCEPTION;
}

void push_number(Stack_numbers **head, int value)
{
    Stack_numbers *new = malloc(sizeof(Stack_numbers));
    new->value = value;
    new->next = *head;
    *head = new;
}

int pop_number(Stack_numbers **head)
{
    if (*head != NULL)
    {
        int result = (*head)->value;
        Stack_numbers *temp = *head;
        *head = (*head)->next;
        free(temp);
        return result;
    }
    return INVALID_OPERATION_EXCEPTION;
}

void delete_stack_operations(Stack_tokens **stack)
{
    while (*stack)
    {
        Stack_tokens *temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

void delete_stack_numbers(Stack_numbers **stack)
{
    while (*stack)
    {
        Stack_numbers *temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}
