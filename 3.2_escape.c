/* exercise 3-2: write a function escape(s,t) that converts
 * characters from escape characters to ex. \n and \t.
 * Use switch-case and write a function to reverse the escape function */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "minunit.h"

int visible_length(char* string)
{
    int ch, i, len;
    ch = i = len = 0;

    while((ch = string[i++]) != '\0') {
        switch(ch) {
            case '\n':
            case '\t':
                len += 2;
                break;
            default:
                len += 1;
                break;
        }
    }
    return len;
}

void printme(char* string)
{
    printf("ME: %s\n",string);
}

int main(int argc, char* argv[])
{
    run_tests();
    int num_arguments = 1;
    if (argc <= num_arguments) {
        printf("Need att least %d argmuent.\n", num_arguments);
        exit(EXIT_FAILURE);
    }
}

//------------------------------------------------------------------------------
//--- Tests
//------------------------------------------------------------------------------

int tests_run = 0;

void run_tests()
{
    char* result = all_tests();
    if (result !=0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
}

static char* test_visible_length()
{
    mu_assert("visible_length returned wrong length.", visible_length("1234") == 4);
    mu_assert("visible_length returned wrong length.", visible_length("12\n5\t8") == 8);
    return 0;
}

static char* all_tests()
{
    mu_run_test(test_visible_length);
    return 0;
}

