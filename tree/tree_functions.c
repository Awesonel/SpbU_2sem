#include <stdio.h>
#include <malloc.h>
#include "tree_functions.h"

void add_element(Tree **tree, int value) {
    if ((*tree) == NULL) {
        *tree = malloc(sizeof(Tree));
        (*tree)->value = value;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else {
        Tree *ptr = *tree;
        int flag = 1;
        while (flag) {
            if (value >= ptr->value) {
                if (ptr->right == NULL) {
                    ptr->right = malloc(sizeof(Tree));
                    flag = 0;
                }
                ptr = ptr->right;
            } else {
                if (ptr->left == NULL) {
                    ptr->left = malloc(sizeof(Tree));
                    flag = 0;
                }
                ptr = ptr->left;
            }
        }
        ptr->value = value;
        ptr->left = NULL;
        ptr->right = NULL;
    }
}

Tree *create_tree(const int *array, const int n) {
    Tree *result = NULL;
    for (int i = 0; i < n; ++i) {
        add_element(&result, array[i]);
    }
    return result;
}

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
