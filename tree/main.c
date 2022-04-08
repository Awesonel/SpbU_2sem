#include <stdio.h>
#include "tree_functions.h"
#include "stern_brocot_tree_functions.h"
#include "additional.h"
#define len_array(a) sizeof(a)/sizeof(int)


int main() {
    int a[] = {2, 35, 177, -6, 11, 35};
    tree_sort(a, len_array(a));
    print_array(a, len_array(a));
    return 0;
}
