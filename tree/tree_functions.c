#include <stdio.h>
#include <malloc.h>
#include "tree_functions.h"

Tree *get_node(int val) {
    Tree* tree = malloc(sizeof(Tree));
    tree->value = val;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void add_element(Tree **tree, int value) {
    if (*tree) {
        Tree *ptr = *tree;
        while (ptr) {
            if (value >= ptr->value) {
                if (ptr->right == NULL) {
                    ptr->right = get_node(value);
                    break;
                }
                ptr = ptr->right;
            } else {
                if (ptr->left == NULL) {
                    ptr->left = get_node(value);
                    break;
                }
                ptr = ptr->left;
            }
        }
    }
    else *tree = get_node(value);
}

Tree *create_tree(const int *array, const int n) {
    Tree *result = NULL;
    for (int i = 0; i < n; ++i) {
        add_element(&result, array[i]);
    }
    return result;
}

//void fill_array(Tree *tree, int *array, int *i);

void fill_array(Tree *tree, int *array, int *i) {
    if (tree) {
        fill_array(tree->left, array, i);
        array[*i] = tree->value;
        ++(*i);
        fill_array(tree->right, array, i);
    }
}

void tree_sort(int *array, int n) {
    Tree *tree = create_tree(array, n);
    int i = 0;
    fill_array(tree, array, &i);
}
