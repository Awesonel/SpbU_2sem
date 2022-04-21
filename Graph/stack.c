#include <malloc.h>
#include "stack.h"

void push(Stack **head, int value)
{
    Stack *new = malloc(sizeof(Stack));
    new->value = value;
    new->next = *head;
    *head = new;
}

int pop(Stack **head)
{
    if (*head != NULL)
    {
        int result = (*head)->value;
        Stack *temp = *head;
        *head = (*head)->next;
        free(temp);
        return result;
    }
    return INVALID_OPERATION_EXCEPTION;
}

void delete_stack(Stack **stack)
{
    while (*stack)
    {
        Stack *temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}
