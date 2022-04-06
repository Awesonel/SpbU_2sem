#include <stdio.h>
#include "additional.h"

void print_array(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
