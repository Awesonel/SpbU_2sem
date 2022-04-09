#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Additional.h"

void push(Stack **head, char value, Token_type type) {
    Stack *new = malloc(sizeof(Stack));
    new->type = type;
    new->value = value;
    new->next = *head;
    *head = new;
}

char get(Stack *head) {
    if (head != NULL) return head->value;
    return INVALID_OPERATION_EXCEPTION;
}

char pop(Stack **head) {
    if (*head != NULL) {
        char result = (*head)->value;
        Stack *temp = *head;
        *head = (*head)->next;
        free(temp);
        return result;
    }
    return INVALID_OPERATION_EXCEPTION;
}

void print_stack(Stack *head) {
    Stack *ptr = head;
    while (ptr) {
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
    printf("---\n");
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
