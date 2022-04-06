#include "stack.h"
#include <stdio.h>
#include <malloc.h>

Stack* push(Stack **head, int value) {
    Stack *new = malloc(sizeof(Stack));
    new->value = value;
    new->next = *head;
    *head = new;
    return *head;
}

int get(Stack *head, int *error_code) {
    if (head != NULL) {
        *error_code = 0;
        return head->value;
    }
    *error_code = INVALID_OPERATION_EXCEPTION;
    return INVALID_OPERATION_EXCEPTION;
}

int pop(Stack **head, int *error_code) {
    if (*head != NULL) {
        *error_code = 0;
        int result = (*head)->value;
        Stack *temp = *head;
        *head = (*head)->next;
        free(temp);
        return result;
    }
    *error_code = INVALID_OPERATION_EXCEPTION;
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
