#include <math.h>
#include "Additional.h"

int GCD(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return abs(a);
}

int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

char *char_to_string(char symbol) {
    char *str = calloc(2, sizeof(char));
    str[0] = symbol;
    return str;
}
