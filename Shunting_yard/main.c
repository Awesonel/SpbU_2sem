#include <stdio.h>
#include "stack.h"
#include "tokens.h"
#include "Additional.h"

int main() {
    int error_code = 0;
    Token *tokens = get_token_notation("113 + 484 * GCD(322 - 62, 97 * LCM(-42, (8 * (24 + 3638))/29) - 23) * (912 + 1590)");
    print_token_notation(tokens);
    return 0;
}
