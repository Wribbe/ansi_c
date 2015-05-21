/* exercise 3-2: write a function escape(s,t) that converts
 * characters from escape characters to ex. \n and \t.
 * Use switch-case and write a function to reverse the escape function */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "minunit.h"

int num_escapes(char* string)
{
    int ch, i, len;
    ch = i = len = 0;

    while((ch = string[i++]) != '\0') {
        switch(ch) {
            case '\n':
            case '\t':
                len += 1;
                break;
        }
    }
    return len;
}

void escape(char* from, char** to)
{
    char* return_string = malloc(sizeof(char)*num_escapes(from));

    int ch = 0;
    int i = 0;
    int k = 0;

    while((ch = from[i++]) != '\0'){
        switch(ch) {
            case '\n':
               return_string[k++] = '\\';
               return_string[k++] = 'n';
               break;
            case '\t':
               return_string[k++] = '\\';
               return_string[k++] = 't';
               break;
            default:
               return_string[k++] = ch;
               break;
        }
    }
    *to = return_string;
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
        printf("TEST FAILED\n");
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
}

static char* test_num_escapes()
{
    mu_assert("num_escapes returned wrong number.", num_escapes("1234") == 0);
    mu_assert("num_escapes returned wrong number.", num_escapes("12\n5\t8") == 2);
    return 0;
}

static char* test_escape()
{
    char* input = "Escape sequences: \n\t";
    char* output;
    escape(input, &output);
    char* correct_output = "Escape sequences: \\n\\t";
    mu_assert("escape did not return correct output.", strcmp(correct_output,output) == 0);
    return 0;
}

static char* all_tests()
{
    mu_run_test(test_num_escapes);
    mu_run_test(test_escape);
    return 0;
}

