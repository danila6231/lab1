#ifndef LAB1_INT_DYN_ARRAY_H
#define LAB1_INT_DYN_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int* create_array_i(array_length) {
    int* array = (int*) malloc(array_length * sizeof(int));
    return array;
}

void swap_i(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort_i(int* A, int size, bool (*cmp)(int, int)) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (!cmp(A[j], A[j + 1])) swap_i(&A[j], &A[j + 1]);
        }
    }
}

int* map_i(int (*f)(int), int* l, int size) {
    int* res = (int*) malloc(sizeof(l));
    for (int i = 0; i < size; i++) {
        res[i] = f(l[i]);
    }
    return res;
}

int* where_i(bool (*h)(int), int* A, int size) {
    int true_counter = 0;
    for (int i = 0; i < size; i++)
        if (h(A[i])) true_counter++;
    int* res = malloc(true_counter * sizeof(int));
    int current_element = 0;
    for (int i = 0; i < size; i++) {
        if (h(A[i])) {
            res[current_element] = A[i];
            current_element++;
        }
    }
    return res;
}

int *concat_i(int *A, int size_a, int *B, int size_b) {
    int* res = malloc((size_a + size_b) * sizeof(int));
    for (int i = 0; i < size_a; i++)
        res[i] = A[i];
    for (int i = size_a; i < size_a + size_b; i++)
        res[i] = B[i-size_a];
    return res;
}

bool check_i(int *correct, int size_cor, int *test, int size_test) {
    if (size_cor != size_test) return 0;
    else {
        for (int i = 0; i < size_cor; i++)
            if(correct[i] != test[i]) return 0;
    }
    return 1;
}

void output_array_i(int* array, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#endif //LAB1_INT_DYN_ARRAY_H
