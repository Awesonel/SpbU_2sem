#ifndef STACK_TOKENS_H
#define STACK_TOKENS_H

int operation_precedence(char operation);

enum token_type{
    NUMBER,
    OPERATION,
    OPEN_BR,
    CLOSE_BR,
    FUNCTION,
    COMMA,
};
typedef enum token_type Token_type;

struct token {
    Token_type type;
    char* value;
    struct token *next;
};
typedef struct token Token;

// x - операция или нет
int is_operation(char x);

// Добавление токена в *p_token
void add_token(Token **p_token, const char val[], enum token_type tt);

// Создаёт токеновскую запись выражения expression
Token* get_token_notation(char* expression);

// Вывод списка токенов
void print_token_notation(Token *token_notation);

void delete_token_list(Token **list);

#endif //STACK_TOKENS_H
