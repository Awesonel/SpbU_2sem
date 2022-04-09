#include "tokens.h"
#include "Shunting_yard.h"

int main() {
    Token *tokens = get_token_notation("113 + 484 * GCD(322 - 62, 97 * LCM(-42, (8 * (24 + 3638))/29) - 23) * (912 + 1590)");
    print_token_notation(tokens);

    tokens = shunting_yard(tokens);
    print_token_notation(tokens);

    delete_token_list(&tokens);
    return 0;
}
