#include <stdio.h>
#include "string_dyn_array.h"
#include "int_dyn_array.h"
#include "tests.h"
#include "interface.h"

int main() {
    while (true) {
        printf("\nIf yoy want to initialize an array enter 'a'\n"
               "If you want to run tests enter 't'\n"
               "If you want to exit type 'e' \n"
               "--> ");
        char ans[100] = "";
        scanf("%s", ans);
        if (!strcmp(ans, "a")) {
            printf("\nEnter the size of your array\n"
                   "--> ");
            int size;
            scanf("%d", &size);

            printf("\nEnter the type of array elements: string or integer (s/i)\n"
                   "--> ");

            char type[100] = "";
            scanf("%s", type);

            if (!strcmp(type, "s")) {
                char** array = create_array_s(size);
                interface_string(array, size);
            }
            else if (!strcmp(type, "i")) {
                int* array = create_array_i(size);
                interface_integer(array, size);
            }
            else printf("\nError\n");
        }
        else if (!strcmp(ans, "t")) {
            tests();
        }
        else {
            break;
        }
    }
    return 0;
}