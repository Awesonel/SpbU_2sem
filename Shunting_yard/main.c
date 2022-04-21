#include <stdio.h>
#include "tokens.h"
#include "Shunting_yard.h"

int main()
{
    Token *tokens = get_token_notation("GCD(-12,3)");//"-36+GCD(-45+12/2,(14+1)*2)");
    print_token_notation(tokens);

    tokens = shunting_yard(tokens);
    print_token_notation(tokens);

    int answer = calculate_expression(tokens);
    printf("%d\n", answer);
    delete_token_list(&tokens);
    return 0;
}
