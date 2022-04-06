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
