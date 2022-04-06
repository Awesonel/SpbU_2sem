#include <malloc.h>
#include <stdio.h>
#include "tokens.h"

int is_operation(char x) {
    return ((x == '+') || (x == '-') || (x == '*') || (x == '/'));
}

void add_zero_as_token(Token **p_token) {
    (*p_token) = malloc(sizeof(Token));
    (*p_token)->value = (char *) malloc(sizeof(char));
    (*p_token)->value = "0";
    (*p_token)->type = NUMBER;
    (*p_token)->next = NULL;
}

void add_sign_as_token(Token **p_token, char* sign) {
    (*p_token) = malloc(sizeof(Token));
    (*p_token)->value = (char *) malloc(sizeof(char));
    (*p_token)->value = sign;
    (*p_token)->type = OPERATION;
    (*p_token)->next = NULL;
}

Token* get_token_notation(char* expression) {
    Token *token_notation;
    add_zero_as_token(&token_notation);
    Token *current_token = token_notation;
    char *ptr = expression;

    if (*ptr != '-') {
        add_sign_as_token(&(current_token->next), "+");
        current_token = current_token->next;
    }
    int state = 0;
    while (*ptr != '\0') {
        switch (state) {
            case 1: {   // Создание "токеновского нуля" после открывающихся скобок и запятых
                add_zero_as_token(&(current_token->next));
                current_token = current_token->next;
                if (*ptr != '-') {
                    current_token->next = malloc(sizeof(Token));
                    current_token = current_token->next;
                    current_token->value = (char*)malloc(sizeof(char));
                    current_token->value = "+";
                    current_token->type = OPERATION;
                    current_token->next = NULL;
                }
                state = 0;
                break;
            }
            case 2: {   // Запись числа как токена
                char *temp = ptr;
                int number = strtol(ptr, &ptr, 10);
                int number_length =(int) (ptr - temp);
                current_token->next = malloc(sizeof(Token));
                current_token = current_token->next;
                current_token->next = NULL;
                current_token->type = NUMBER;
                current_token->value = (char *) malloc((number_length + 1) * sizeof(char));
                itoa(number, current_token->value, 10);
                state = 0;
                break;
            }
            default: {  // Считывание строки
                if (((*ptr) >= 48) && ((*ptr) <= 57)) {
                    state = 2;
                } else {
                    current_token->next = malloc(sizeof(Token));
                    current_token = current_token->next;
                    current_token->value = (char *) malloc(sizeof(char));
                    current_token->next = NULL;
                    if (is_operation(*ptr)) {
                        current_token->type = OPERATION;
                        current_token->value[0] = *ptr;
                        current_token->value[1] = '\0';
                    } else if (*ptr == '(') {
                        current_token->type = OPEN_BR;
                        current_token->value = "(";
                        state = 1;
                    } else if (*ptr == ')') {
                        current_token->type = CLOSE_BR;
                        current_token->value = ")";
                    } else if (*ptr == 'G') {
                        current_token->type = FUNCTION;
                        current_token->value = "G";
                        ptr += 3;
                        state = 1;
                    } else if (*ptr == 'L') {
                        current_token->type = FUNCTION;
                        current_token->value = "L";
                        ptr += 3;
                        state = 1;
                    } else if (*ptr == ',') {
                        current_token->type = COMMA;
                        current_token->value = ",";
                        state = 1;
                    }
                    ++ptr;
                }
                break;
            }
        }

    }
    return token_notation;
}

void print_token_notation(Token *token_notation) {
    Token *ptr = token_notation;
    while (ptr) {
        printf("%s ", ptr->value);
        ptr = ptr->next;
    }
}
