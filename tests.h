#ifndef LAB1_TESTS_H
#define LAB1_TESTS_H

#include "string_dyn_array.h"
#include "int_dyn_array.h"
#include "utility.h"

void test1() {
    //test1: string array concatenation test

    //array1 initialization
    int size1 = 3;
    char** array1 = create_array_s(size1);
    array1[0] = "a1";
    array1[1] = "a2";
    array1[2] = "a3";

    //array2 initialization
    int size2 = 2;
    char** array2 = create_array_s(size2);
    array2[0] = "b1";
    array2[1] = "b2";

    //correct array after concatenation initialization
    int size_correct = size1 + size2;
    char** correct_array = create_array_s(size_correct);
    correct_array[0] = "a1";
    correct_array[1] = "a2";
    correct_array[2] = "a3";
    correct_array[3] = "b1";
    correct_array[4] = "b2";

    //test array initialization
    char** test_array = concat_s(array1, size1, array2, size2);

    printf("String array concatenation test: ");
    if(check_s(correct_array, size_correct, test_array, size1 + size2))
        printf("SUCCESS\n");
    else printf("FAILED\n");
}

void test2() {
    //test2: string array sorting test

    //array to be sorted initialization
    int size = 5;
    char** array = create_array_s(size);
    array[0] = "1234";
    array[1] = "123";
    array[2] = "12";
    array[3] = "123456";
    array[4] = "1";

    //correct array after sorting initialization
    char** correct_array = create_array_s(size);
    correct_array[0] = "1";
    correct_array[1] = "12";
    correct_array[2] = "123";
    correct_array[3] = "1234";
    correct_array[4] = "123456";

    //array sorting by string length
    sort_s(array, size, cmp_s);

    printf("String array sorting test: ");
    if(check_s(correct_array, size, array, size))
        printf("SUCCESS\n");
    else printf("FAILED\n");
}

void test3() {
    // test3: string array map() test

    //array to map initialization
    int size = 5;
    char** array = create_array_s(size);
    array[0] = "word1";
    array[1] = "lalala";
    array[2] = "";
    array[3] = "hey";
    array[4] = "welcome";

    //correct array initialization
    char** correct_array  = create_array_s(size);
    correct_array[0] = "word1word1word1";
    correct_array[1] = "lalalalalalalalala";
    correct_array[2] = "";
    correct_array[3] = "heyheyhey";
    correct_array[4] = "welcomewelcomewelcome";

    //test array initialization (multiply each element by 3)
    char** test_array = map_s(str_multiplication_by_3, array, size);

    printf("String array map() test: ");
    if(check_s(correct_array, size, test_array, size))
        printf("SUCCESS\n");
    else printf("FAILED\n");
}

void test4() {
    // test4: string array where() test

    //array initialization
    int size = 5;
    char** array = create_array_s(size);
    array[0] = "w12";
    array[1] = "lalala";
    array[2] = "";
    array[3] = "hello";
    array[4] = "we";

    //correct array initialization
    int correct_size = 3;
    char** correct_array  = create_array_s(correct_size);
    correct_array[0] = "w12";
    correct_array[1] = "";
    correct_array[2] = "we";

    //test array initialization (save elements with length less than 4)
    char** test_array = where_s(len_less_than_4, array, size);

    printf("String array where() test: ");
    if(check_s(correct_array, correct_size, test_array, correct_size))
        printf("SUCCESS\n");
    else printf("FAILED\n");
}

void test5() {
    //test5: int array concatenation test

    //array1 initialization
    int size1 = 3;
    int* array1 = create_array_i(size1);
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;

    //array2 initialization
    int size2 = 2;
    int* array2 = create_array_i(size2);
    array2[0] = 1;
    array2[1] = 2;

    //correct array after concatenation initialization
    int size_correct = size1 + size2;
    int* correct_array = create_array_i(size_correct);
    correct_array[0] = 1;
    correct_array[1] = 2;
    correct_array[2] = 3;
    correct_array[3] = 1;
    correct_array[4] = 2;

    //test array initialization
    int* test_array = concat_i(array1, size1, array2, size2);

    printf("Integer array concatenation test: ");
    if(check_i(correct_array, size_correct, test_array, size1 + size2))
        printf("SUCCESS\n");
    else printf("FAILED\n");
}

void test6() {
    //test6: int array sorting test

    //array to be sorted initialization
    int size = 5;
    int* array = create_array_i(size);
    array[0] = 1;
    array[1] = 30000;
    array[2] = 57;
    array[3] = -300;
    array[4] = 2342;

    //correct array after sorting initialization
    int* correct_array = create_array_i(size);
    correct_array[0] = 30000;
    correct_array[1] = 2342;
    correct_array[2] = 57;
    correct_array[3] = 1;
    correct_array[4] = -300;

    //array sorting in decreasing order
    sort_i(array, size, cmp_i);

    printf("Integer array sorting test: ");
    if(check_i(correct_array, size, array, size))
        printf("SUCCESS\n");
    else printf("FAILED\n");
}

void test7() {
    // test7: int array map test

    //array to map initialization
    int size = 5;
    int* array = create_array_i(size);
    array[0] = 34;
    array[1] = 82;
    array[2] = -122;
    array[3] = 332;
    array[4] = 0;

    //correct array initialization
    int* correct_array  = create_array_i(size);
    correct_array[0] = 102;
    correct_array[1] = 246;
    correct_array[2] = -366;
    correct_array[3] = 996;
    correct_array[4] = 0;

    //test array initialization (multiply each element by 3)
    int* test_array = map_i(multiply_by_3, array, size);

    printf("Integer array map() test: ");
    if(check_i(correct_array, size, test_array, size))
        printf("SUCCESS\n");
    else printf("FAILED\n");
}

void test8() {
    // test4: string array where test

    //array to map initialization
    int size = 5;
    int* array = create_array_i(size);
    array[0] = 4;
    array[1] = -5;
    array[2] = 0;
    array[3] = 33;
    array[4] = 2;

    //correct array initialization
    int correct_size = 3;
    int* correct_array  = create_array_i(correct_size);
    correct_array[0] = 4;
    correct_array[1] = 33;
    correct_array[2] = 2;

    //test array initialization (save only positive elements)
    int* test_array = where_i(check_if_positive, array, size);

    printf("Integer array where() test: ");
    if(check_i(correct_array, correct_size, test_array, correct_size))
        printf("SUCCESS\n");
    else printf("FAILED\n");
}

void tests() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
}

#endif //LAB1_TESTS_H
