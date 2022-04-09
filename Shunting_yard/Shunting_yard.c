#include "Shunting_yard.h"

Token* shunting_yard(Token* expression)
{
    Token *result_seq;
    add_token(&result_seq, "0", NUMBER);
    Token *output = result_seq;
    Token *input = expression->next;
    Stack *stack = NULL;

    while (input)
    {
        if (input->type == NUMBER)
        {
            add_token(&(output->next), input->value, NUMBER);
            output = output->next;
        }
        else if (input->type == FUNCTION || input->type == OPEN_BR)
        {
            push(&stack, input->value[0], input->type);
        }
        else if (input->type == CLOSE_BR)
        {
            while (stack->type != OPEN_BR && stack->type != FUNCTION)
            {
                Token_type temp = stack->type;
                add_token(&(output->next), char_to_string(pop(&stack)), temp);
                output = output->next;
            }
            if (stack->type == OPEN_BR) pop(&stack);
            else {
                add_token(&(output->next), char_to_string(pop(&stack)), FUNCTION);
                output = output->next;
            }
        }
        else if (input->type == COMMA)
        {
            while (stack->type != FUNCTION)
            {
                Token_type temp = stack->type;
                add_token(&(output->next), char_to_string(pop(&stack)), temp);
                output = output->next;
            }
        }
        else if (input->type == OPERATION)
        {
            while (stack && /*(stack->type == FUNCTION ||*/ operation_precedence(get(stack)) >= operation_precedence(input->value[0]))
            {
                Token_type temp = stack->type;
                add_token(&(output->next), char_to_string(pop(&stack)), temp);
                output = output->next;
            }
            push(&stack, input->value[0], input->type);
        }
        input = input->next;
    }
    while (stack)
    {
        Token_type temp = stack->type;
        add_token(&(output->next), char_to_string(pop(&stack)), temp);
        output = output->next;
    }

    delete_stack(&stack);
    return result_seq;
}