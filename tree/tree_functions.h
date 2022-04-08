#ifndef TREE_TREE_FUNCTIONS_H
#define TREE_TREE_FUNCTIONS_H

typedef struct tree {
    int value;
    struct tree *left;
    struct tree *right;
} Tree;

void tree_sort(int *array, int n);

#endif
