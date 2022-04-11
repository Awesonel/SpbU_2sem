#include <malloc.h>
#include <stdio.h>
#include "tokens.h"
#include "Additional.h"
#include <string.h>

int is_operation(char x)
{
    return ((x == '+') || (x == '-') || (x == '*') || (x == '/'));
}

void add_token(Token **p_token, const char val[], enum token_type tt)
{
    if (tt != NUMBER)
    {
        (*p_token) = malloc(sizeof(Token));
        (*p_token)->value = (char *) calloc(2, sizeof(char));
        (*p_token)->value[0] = val[0];
        (*p_token)->type = tt;
        (*p_token)->next = NULL;
    }
    else
    {
        (*p_token) = malloc(sizeof(Token));
        (*p_token)->value = (char *) calloc(10, sizeof(char));
        strcpy((*p_token)->value, val);
        (*p_token)->type = tt;
        (*p_token)->next = NULL;
    }
}

int operation_precedence(char operation)
{
    if (operation == '(' || operation == 'G' || operation == 'L') return 0;
    if (operation == '+' || operation == '-') return 1;
    return 2;
}

Token* get_token_notation(char* expression)
{
    Token *token_notation;
    add_token(&token_notation, "0", NUMBER);
    if (*expression == '\0') return token_notation;
    Token *current_token = token_notation;
    char *ptr = expression;
    if (*ptr != '-')
    {
        add_token(&(current_token->next), "+", OPERATION);
        current_token = current_token->next;
    }
    int state = 0;
    while (*ptr != '\0')
    {
        switch (state)
        {
            case 1:     // Создание "токеновского нуля" после открывающихся скобок и запятых
            {
                add_token(&(current_token->next), "0", NUMBER);
                current_token = current_token->next;
                if (*ptr != '-')
                {
                    add_token(&(current_token->next), "+", OPERATION);
                    current_token = current_token->next;
                }
                state = 0;
                break;
            }
            case 2:     // Запись числа как токена
            {
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
            default:    // Считывание строки
            {
                if (((*ptr) >= '0') && ((*ptr) <= '9')) state = 2;
                else
                {
                    if (is_operation(*ptr))
                    {
                        // char temp[2] = {*ptr, '\0'};
                        add_token(&(current_token->next), char_to_string(*ptr), OPERATION);
                        current_token = current_token->next;
                    }
                    else if (*ptr == '(')
                    {
                        add_token(&(current_token->next), "(", OPEN_BR);
                        current_token = current_token->next;
                        state = 1;
                    }
                    else if (*ptr == ')')
                    {
                        add_token(&(current_token->next), ")", CLOSE_BR);
                        current_token = current_token->next;
                    }
                    else if (*ptr == 'G')
                    {
                        add_token(&(current_token->next), "G", FUNCTION);
                        current_token = current_token->next;
                        ptr += 3;
                        state = 1;
                    }
                    else if (*ptr == 'L')
                    {
                        add_token(&(current_token->next), "L", FUNCTION);
                        current_token = current_token->next;
                        ptr += 3;
                        state = 1;
                    }
                    else if (*ptr == ',')
                    {
                        add_token(&(current_token->next), ",", COMMA);
                        current_token = current_token->next;
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

void delete_token_list(Token **list)
{
    while (*list)
    {
        Token *temp = (*list)->next;
        free(*list);
        *list = temp;
    }
}

void print_token_notation(Token *token_notation)
{
    Token *ptr = token_notation;
    while (ptr)
    {
        printf("%s ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}
