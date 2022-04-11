#ifndef STACK_SHUNTING_YARD_H
#define STACK_SHUNTING_YARD_H
#include "tokens.h"

Token* shunting_yard(Token* expression);

int calculate_expression(Token* expression);

#endif //STACK_SHUNTING_YARD_H
