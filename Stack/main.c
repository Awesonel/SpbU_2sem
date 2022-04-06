#include <stdio.h>
#include "stack.h"
#include "tokens.h"
#include "Additional.h"

int main() {
    int error_code = 0;
    Token *tokens = get_token_notation("");
    print_token_notation(tokens);
    return 0;
}
