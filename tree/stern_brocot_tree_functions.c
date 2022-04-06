#include "stern_brocot_tree_functions.h"
#include <stdio.h>
#include <malloc.h>



sbt *stern_brocot_fraction(sbf *fraction, int n) {
    if (!fraction) return NULL;
	if (fraction->depth > n) return NULL;

	sbt *node = (sbt*)malloc(sizeof(sbt));
	node->numerator = fraction->left_ancestor->numerator + fraction->right_ancestor->numerator;
	node->denominator = fraction->left_ancestor->denominator + fraction->right_ancestor->denominator;

	//Структуры для создания левого и правого ребёнка
	sbf *for_left = (sbf*)malloc(sizeof(sbf));
	for_left->left_ancestor = fraction->left_ancestor;
	for_left->right_ancestor = node;
	for_left->depth = fraction->depth + 1;

	sbf *for_right = (sbf*)malloc(sizeof(sbf));
	for_right->left_ancestor = node;
	for_right->right_ancestor = fraction->right_ancestor;
	for_right->depth = fraction->depth + 1;

	node->left = stern_brocot_fraction(for_left, n);
	node->right = stern_brocot_fraction(for_right, n);

	//free(for_left);
	//free(for_right);

	return node;
}

sbt *create_stern_brocot_tree(int n) {
	// Фиктивные дроби
	sbt *zero = (sbt*)malloc(sizeof(sbt));
	zero->numerator = 0;
	zero->denominator = 1;
	zero->left = NULL;
	zero->right = NULL;

	sbt *inf = (sbt*)malloc(sizeof(sbt));
	inf->numerator = 1;
	inf->denominator = 0;
	inf->left = NULL;
	inf->right = NULL;

	int depth = 0;

	// Создание дерева
	sbf *tree = (sbf*) malloc(sizeof(sbf));
	if (!tree) return NULL;
	tree->left_ancestor = zero;
	tree->right_ancestor = inf;
	tree->depth = depth + 1;

	sbt *result = stern_brocot_fraction(tree, n);

	free(tree);
	return result;
}

void print_sbt(sbt *tree) {
	if (!tree) return;
	print_sbt(tree->left);
	printf("%d/%d\n", tree->numerator, tree->denominator);
	print_sbt(tree->right);
}

void search_number(sbt *node, double number, int *i, char *answer) {
	if (node == NULL) {
		answer[*i] = '\0';
		return;
	}
	double fraction = (double)(node->numerator) / (node->denominator);
	if (fraction == number) {
		answer[*i] = '\0';
	}
	else if (number > fraction) {
		answer[*i] = 'R';
		++(*i);
		search_number(node->right, number, i, answer);
	}
	else {
		answer[*i] = 'L';
		++(*i);
		search_number(node->left, number, i, answer);
	}
}

char* find_sbt(sbt *tree, double number, int depth) {
	char* answer = (char*) calloc(depth + 1, sizeof(char));
	int i = 0;

	double fraction = (double)(tree->numerator) / (tree->denominator);
	if (fraction == number) {
		answer[i] = '\0';
	}
	else if (number > fraction) {
		answer[i] = 'R';
		++i;
		search_number(tree->right, number, &i, answer);
	}
	else {
		answer[i] = 'L';
		++i;
		search_number(tree->left, number, &i, answer);
	}

	if (i + 1 != depth) {
		answer = (char*)realloc(answer, (i + 1) * sizeof(char));
	}
	return answer;
}

