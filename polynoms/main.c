#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct poly {
    int exp;
    int coeff;
    struct poly *next;
};

typedef struct poly Poly;

bool is_digit(char symbol) {
    return ((symbol >= 48) && (symbol <= 57));
}



void add_monom(Poly **polynom, int exp, int coeff) {
    if (*polynom == NULL) {
        *polynom = malloc(sizeof(Poly));
        (*polynom)->next = NULL;
        (*polynom)->coeff = coeff;
        (*polynom)->exp = exp;
    }
    else {
        Poly *prev = malloc(sizeof(Poly));
        Poly *temp = prev;
        Poly *ptr = *polynom;
        prev->next = *polynom;

        while ((ptr != NULL) && (ptr->exp > exp)) {
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr == NULL) {
            prev->next = malloc(sizeof(Poly));
            ptr = prev->next;
            ptr->exp = exp;
            ptr->coeff = coeff;
            ptr->next = NULL;
        } else if (ptr->exp == exp) {
            ptr->coeff += coeff;
            if (ptr->coeff == 0) {
                if ((ptr == *polynom) && (ptr->next == NULL))
                {
                    *polynom = NULL;
                    return;
                }
                int flag = exp - (*polynom)->exp;
                prev->next = ptr->next;
                ptr->next = NULL;
                free(ptr);
                ptr = prev->next;
                if (flag == 0) *polynom = ptr;
            }

        } else {
            prev->next = malloc(sizeof(Poly));
            prev->next->next = ptr;
            ptr = prev->next;
            ptr->exp = exp;
            ptr->coeff = coeff;
        }

        if (exp > (*polynom)->exp) *polynom = ptr;

        free(temp);
    }
}

Poly* get_polynom(char* str) {
    Poly *polynom = NULL;
    char *str_ptr = str;
    int state = 1, coeff = 1, exp;
    while (*str_ptr != '\0') {
        switch (state) {
            case 1:
                if ((*str_ptr == '+') || (*str_ptr == '-')) {
                    if (*str_ptr == '-') coeff *= -1;
                    ++str_ptr;
                }
                else if (is_digit(*str_ptr)) state = 2;
                else if (*str_ptr == 'x') {
                    state = 3;
                    ++str_ptr;
                    if (*str_ptr == '\0') add_monom(&polynom, 1, coeff);
                }
                break;
            case 2:
                if ((*str_ptr == '+') || (*str_ptr == '-')) {
                    add_monom(&polynom, 0, coeff);
                    coeff = 1;
                    state = 1;
                }
                else if (*str_ptr == 'x') {
                    state = 3;
                    ++str_ptr;
                    if (*str_ptr == '\0') add_monom(&polynom, 1, coeff);
                }
                else if (is_digit(*str_ptr)) {
                    coeff *= strtol(str_ptr, &str_ptr, 10);
                    if (*str_ptr == '\0') add_monom(&polynom, 0, coeff);
                }
                break;
            case 3:
                if ((*str_ptr == '+') || (*str_ptr == '-')) {
                    add_monom(&polynom, 1, coeff);
                    coeff = 1;
                    state = 1;
                }
                else if (*str_ptr == '^') {
                    ++str_ptr;
                    state = 4;
                }
                break;
            case 4:
                exp = strtol(str_ptr, &str_ptr, 10);
                add_monom(&polynom, exp, coeff);
                coeff = 1;
                state = 1;
                break;
        }
    }
    return polynom;
}

/*void print_polynom(Poly *polynom) {
    Poly *ptr = polynom;
    if (ptr == NULL) printf("0");
    while (ptr != NULL) {
        printf("%d %d\n", ptr->coeff, ptr->exp);
        ptr = ptr->next;
    }
    printf("\n");
}*/

Poly* add_poly(Poly *first, Poly *second) {
    Poly *result = NULL;
    Poly *ptr = first;
    while (ptr) {
        add_monom(&result, ptr->exp, ptr->coeff);
        ptr = ptr->next;
    }
    ptr = second;
    while (ptr) {
        add_monom(&result, ptr->exp, ptr->coeff);
        ptr = ptr->next;
    }
    return result;
}

Poly* mult_polynoms(Poly *first, Poly *second) {
    Poly *result = NULL;
    Poly *first_ptr = first;
    Poly *second_ptr = second;
    while (first_ptr != NULL) {
        while (second_ptr != NULL) {
            add_monom(&result, first_ptr->exp + second_ptr->exp, first_ptr->coeff * second_ptr->coeff);
            second_ptr = second_ptr->next;
        }
        second_ptr = second;
        first_ptr = first_ptr->next;
    }
    return result;
}

void free_polynom(Poly **polynom) {
    while (*polynom) {
        Poly *temp = (*polynom)->next;
        free(*polynom);
        *polynom = temp;
    }
    *polynom = NULL;
}

void polynom_print(Poly *polynom) {
    Poly *ptr = polynom;
    if (ptr != NULL) {
        if (ptr->coeff == 1 || ptr->coeff == -1) {
            if (ptr->coeff == -1) printf("-");
        }
        else printf("%d", ptr->coeff);
        if (ptr->exp == 1) printf("x ");
        else if (ptr->exp == 0) printf(" ");
        else printf("x^%d ", ptr->exp);
        ptr = ptr->next;
    } else printf("0");
    while (ptr != NULL) {
        if (ptr->coeff == 1 || ptr->coeff == -1) {
            if (ptr->coeff == -1) printf("-");
            else printf("+");
        }
        else printf("%d", ptr->coeff);
        if (ptr->exp == 1) printf("x ");
        else if (ptr->exp == 0) printf(" ");
        else printf("x^%d ", ptr->exp);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    Poly *fpolynom = get_polynom("x^2+x");
    Poly *spolynom = get_polynom("-x+x^2");
    polynom_print(fpolynom);
    polynom_print(spolynom);

    Poly *poly = mult_polynoms(fpolynom, spolynom);
    printf("---Mult---\n");
    polynom_print(poly);

    poly = add_poly(fpolynom, spolynom);
    printf("---Add---\n");
    polynom_print(poly);

    free_polynom(&fpolynom);
    free_polynom(&spolynom);
    free_polynom(&poly);
    return 0;
}
