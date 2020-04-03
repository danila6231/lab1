#ifndef LAB1_INTERFACE_H
#define LAB1_INTERFACE_H

#include "int_dyn_array.h"
#include "string_dyn_array.h"
#include "utility.h"

void interface_string(char** array, int size) {
    printf("\nEnter your elements\n");
    for (int i = 0; i < size; i++) {
        char str[100];
        printf("--> ");
        scanf("%s", str);
        int len = (int) strlen(str);
        array[i] = (char*) malloc(sizeof(char) * len);
        for (int j = 0; j < len; j++) {
            array[i][j] = str[j];
        }
    }
    while (true) {
        printf("\nWhat to you want to do with your array\n"
               "1. Output array\n"
               "2. Multiply all elements by 3\n"
               "3. Save only strings with length less than 4\n"
               "4. Sort by length in increasing order\n"
               "5. Sort by length in decreasing order\n"
               "6. Concatenation\n"
               "7. Exit\n"
               "--> ");
        char ans[100];
        scanf("%s", ans);
        if (!strcmp(ans, "1")) {
            output_array_s(array, size);
        }
        else if (!strcmp(ans, "2")) {
            array = map_s(str_multiplication_by_3, array, size);
        }
        else if (!strcmp(ans, "3")) {
            int new_size = 0;
            for(int i =0; i < size; i++) {
                if (len_less_than_4(array[i])) new_size++;
            }
            array = where_s(len_less_than_4, array, size);
            size = new_size;
        }
        else if (!strcmp(ans, "4")) {
            sort_s(array, size, cmp_s);
        }
        else if (!strcmp(ans, "5")) {
            sort_s(array, size, cmp_s_decr);
        }
        else if (!strcmp(ans, "6")) {
            printf("\nEnter the size of your second array\n"
                   "--> ");
            int size2;
            scanf("%d", &size2);
            char** array2 = create_array_s(size2);
            printf("\nEnter your elements\n");
            for (int i = 0; i < size2; i++) {
                char str[100];
                printf("--> ");
                scanf("%s", str);
                int len = (int) strlen(str);
                array2[i] = (char*) malloc(sizeof(char) * len);
                for (int j = 0; j < len; j++) {
                    array2[i][j] = str[j];
                }
            }

            array = concat_s(array, size, array2, size2);
            size += size2;
        }
        else break;
    }
}

void interface_integer(int* array, int size) {
    printf("\nEnter your elements\n");
    for (int i = 0; i < size; i++) {
        printf("--> ");
        scanf("%d", &array[i]);
    }
    while (true) {
        printf("\nWhat to you want to do with your array\n"
               "1. Output array\n"
               "2. Increment all elements\n"
               "3. Decrement all elements\n"
               "4. Save only positive elements\n"
               "5. Save only negative elements\n"
               "6. Sort in increasing order\n"
               "7. Sort in decreasing order\n"
               "8. Concatenation\n"
               "9. Exit\n"
               "--> ");
        char ans[100];
        scanf("%s", ans);
        if (!strcmp(ans, "1")) {
            output_array_i(array, size);
        }
        else if (!strcmp(ans, "2")) {
            array = map_i(inc, array, size);
        }
        else if (!strcmp(ans, "3")) {
            array = map_i(dec, array, size);
        }
        else if (!strcmp(ans, "4")) {
            int new_size = 0;
            for(int i =0; i < size; i++) {
                if (check_if_positive(array[i])) new_size++;
            }
            array = where_i(check_if_positive, array, size);
            size = new_size;
        }
        else if (!strcmp(ans, "5")) {
            int new_size = 0;
            for(int i =0; i < size; i++) {
                if (check_if_negative(array[i])) new_size++;
            }
            array = where_i(check_if_negative, array, size);
            size = new_size;
        }
        else if (!strcmp(ans, "6")) {
            sort_i(array, size, cmp_i_incr);
        }
        else if (!strcmp(ans, "7")) {
            sort_i(array, size, cmp_i);
        }
        else if (!strcmp(ans, "8")) {
            printf("\nEnter the size of your second array\n"
                   "--> ");
            int size2;
            scanf("%d", &size2);
            int* array2 = create_array_i(size2);
            printf("\nEnter your elements\n");
            for (int i = 0; i < size2; i++) {
                printf("--> ");
                scanf("%d", &array2[i]);
            }

            array = concat_i(array, size, array2, size2);
            size += size2;
        }
        else break;
    }
}

#endif //LAB1_INTERFACE_H
