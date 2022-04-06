#ifndef TREE_TREE_FUNCTIONS_H
#define TREE_TREE_FUNCTIONS_H

struct tree {
    int value;
    struct tree *left;
    struct tree *right;
};

typedef struct tree Tree;

void add_element(Tree **tree, int value);
Tree *create_tree(const int *array, int n);
void fill_array(Tree *tree, int *array, int *i);
void tree_sort(int *array, int n);

#endif
