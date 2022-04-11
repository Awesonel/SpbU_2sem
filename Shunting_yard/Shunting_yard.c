#include "Shunting_yard.h"
#include "stack.h"
#include "Additional.h"

Token* shunting_yard(Token* expression)
{
    Token *result_seq;
    add_token(&result_seq, "0", NUMBER);
    Token *output = result_seq;
    Token *input = expression->next;
    Stack_tokens *stack = NULL;

    while (input)
    {
        if (input->type == NUMBER)
        {
            add_token(&(output->next), input->value, NUMBER);
            output = output->next;
        }
        else if (input->type == FUNCTION || input->type == OPEN_BR)
        {
            push_token(&stack, input->value[0], input->type);
        }
        else if (input->type == CLOSE_BR)
        {
            while (stack->type != OPEN_BR && stack->type != FUNCTION)
            {
                Token_type temp = stack->type;
                add_token(&(output->next), char_to_string(pop_token(&stack)), temp);
                output = output->next;
            }
            if (stack->type == OPEN_BR) pop_token(&stack);
            else
            {
                add_token(&(output->next), char_to_string(pop_token(&stack)), FUNCTION);
                output = output->next;
            }
        }
        else if (input->type == COMMA)
        {
            while (stack->type != FUNCTION)
            {
                Token_type temp = stack->type;
                add_token(&(output->next), char_to_string(pop_token(&stack)), temp);
                output = output->next;
            }
        }
        else if (input->type == OPERATION)
        {
            while (stack && /*(stack->type == FUNCTION ||*/ operation_precedence(get_token(stack)) >= operation_precedence(input->value[0]))
            {
                Token_type temp = stack->type;
                add_token(&(output->next), char_to_string(pop_token(&stack)), temp);
                output = output->next;
            }
            push_token(&stack, input->value[0], input->type);
        }
        input = input->next;
    }
    while (stack)
    {
        Token_type temp = stack->type;
        add_token(&(output->next), char_to_string(pop_token(&stack)), temp);
        output = output->next;
    }

    delete_stack_operations(&stack);
    return result_seq;
}

int calculate_expression(Token* expression)
{
    Token *current_token = expression;
    Stack_numbers *stack = NULL;

    while (current_token)
    {
        if (current_token->type == NUMBER)
        {
            push_number(&stack, strtol(current_token->value, NULL, 10));
        }
        else
        {
            int temp1 = pop_number(&stack);
            int temp2 = pop_number(&stack);
            switch (current_token->value[0])
            {
                case '+':
                    push_number(&stack, temp2 + temp1);
                    break;
                case '-':
                    push_number(&stack, temp2 - temp1);
                    break;
                case '*':
                    push_number(&stack, temp2 * temp1);
                    break;
                case '/':
                    push_number(&stack, temp2 / temp1);
                    break;
                case 'G':
                    push_number(&stack, GCD(temp2, temp1));
                    break;
                case 'L':
                    push_number(&stack, LCM(temp2, temp1));
                    break;
            }
        }
        current_token = current_token->next;
    }
    int result = pop_number(&stack);
    delete_stack_numbers(&stack);
    return result;
}