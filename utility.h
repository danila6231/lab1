#ifndef LAB1_UTILITY_H
#define LAB1_UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* str_concat(char *A, char *B) {
    int len_a = (int) strlen(A);
    int len_b = (int) strlen(B);
    char *C = (char *) malloc(sizeof(char) * (len_a + len_b));
    for (int i = 0; i < len_a; i++) C[i] = A[i];
    for (int i = len_a; i < len_a + len_b; i++) C[i] = B[i - len_a];
    return C;
}

char* str_multiplication_by_3(char* A) {
    char* C = (char*) malloc(sizeof(A) * 3);
    for (int i = 0; i < 3; i++) {
        C = str_concat(C, A);
    }
    return C;
}

bool len_less_than_4(char* A) {
    if (strlen(A) >= 4) return 0;
    return 1;
}

bool cmp_s(char* A, char* B) {
    int len_a = (int) strlen(A);
    int len_b = (int) strlen(B);
    return (len_a < len_b);
}

bool cmp_s_decr(char* A, char* B) {
    int len_a = (int) strlen(A);
    int len_b = (int) strlen(B);
    return (len_a > len_b);
}

int multiply_by_3(int A) {
    return A*3;
}

bool check_if_positive(int A){
    return A > 0;
}

bool check_if_negative(int A) {
    return A < 0;
}

bool cmp_i(int A, int B) {
    return (A > B);
}

int inc(int a) {
    return a+1;
}

int dec(int a) {
    return a-1;
}

bool cmp_i_incr(int A, int B) {
    return A < B;
}

#endif //LAB1_UTILITY_H
