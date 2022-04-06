#ifndef TREE_STERN_BROCOT_TREE_FUNCTIONS_H
#define TREE_STERN_BROCOT_TREE_FUNCTIONS_H

struct sbt {
    int denominator;
    int numerator;
    struct sbt *left;
    struct  sbt *right;
};
typedef struct sbt sbt;

struct sbf {
    sbt *left_ancestor;
    sbt *right_ancestor;
    int depth;
};
typedef struct sbf sbf;

sbt *stern_brocot_fraction(sbf *fraction, int n);
sbt *create_stern_brocot_tree(int n);
void print_sbt(sbt *tree);
void search_number(sbt *node, double number, int *i, char *answer);
char* find_sbt(sbt *tree, double number, int depth);

#endif
