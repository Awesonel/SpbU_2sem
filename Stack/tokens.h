#ifndef STACK_TOKENS_H
#define STACK_TOKENS_H

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

// *p_token становится "токеновским нулём"
void add_zero_as_token(Token **p_token);

// **p_token становится токеном, хранящим знак sign
void add_sign_as_token(Token **p_token, char* sign);

// Создаёт токеновскую запись выражения expression
Token* get_token_notation(char* expression);

// Вывод списка токенов
void print_token_notation(Token *token_notation);

#endif //STACK_TOKENS_H
