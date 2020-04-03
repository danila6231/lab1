#ifndef LAB1_STRING_DYN_ARRAY_H
#define LAB1_STRING_DYN_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char** create_array_s(array_length) {
    char **array = (char**) malloc(array_length * sizeof(char*));
    return array;
}

void swap_s(char** x, char** y) {
    char* temp = *x;
    *x = *y;
    *y = temp;
}

void sort_s(char** A, int size, bool (*cmp)(char*, char*)) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (!cmp(A[j], A[j + 1])) swap_s(&A[j], &A[j + 1]);
        }
    }
}

char** map_s(char* (*f)(char*), char** l, int size) {
    char** res = (char**) malloc(sizeof(l));
    for (int i = 0; i < size; i++) {
        res[i] = f(l[i]);
    }
    return res;
}

char** where_s(bool (*h)(char*), char** A, int size) {
    int true_counter = 0;
    for (int i = 0; i < size; i++)
        if (h(A[i])) true_counter++;
    char** res = malloc(true_counter * sizeof(char*));
    int current_element = 0;
    for (int i = 0; i < size; i++) {
        if (h(A[i])) {
            res[current_element] = A[i];
            current_element++;
        }
    }
    return res;
}

char** concat_s(char** A, int size_a, char** B, int size_b) {
    char** res = malloc((size_a + size_b) * sizeof(char*));
    for (int i = 0; i < size_a; i++)
        res[i] = A[i];
    for (int i = size_a; i < size_a + size_b; i++)
        res[i] = B[i-size_a];
    return res;
}

bool check_strings(char* str1, char* str2) {
    int len1 = (int) strlen(str1);
    int len2 = (int) strlen(str2);
    if (len1 != len2) return 0;
    else {
        for (int i = 0; i < len1; i++) {
            if (str1[i] != str2[i]) return 0;
        }
    }
    return 1;
}

bool check_s(char** correct, int size_cor, char** test, int size_test) {
    if (size_cor != size_test) return 0;
    else {
        for (int i = 0; i < size_cor; i++)
            if(!check_strings(correct[i], test[i])) return 0;
    }
    return 1;
}

void output_array_s(char** array, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", array[i]);
    }
    printf("\n");
}

#endif //LAB1_STRING_DYN_ARRAY_H
