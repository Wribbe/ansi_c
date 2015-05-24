/* Exercise 3.4_itoa.c: write a function that converts digits in a number
 * to the corresponding characters in a string. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "minunit.h"

#define DEBUG 1

typedef enum status {ERROR, SUCCESS} STATUS;

STATUS reverse(char input[])
{
    int temp, i, j;

    for(i = 0, j = strlen(input)-1; i < j; i++, j--) {
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    return SUCCESS;
}

STATUS itoa(int n, char s[])
{
    return ERROR;
}

int main(void)
{
    run_tests();
}

//------------------------------------------------------------------------------
//-- Tests
//------------------------------------------------------------------------------

static char* test_reverse()
{
    char input[] = "1234";
    char* expected = "4321";
    reverse(input);
    mu_assert("Result from reveres incorrect.", strcmp(input, expected) == 0);
    return 0;
}

static char* test_itoa()
{
    int pos_input = 1337;
    int neg_input = -1337;

    char* pos_expected = "1337";
    char* neg_expected = "-1337";

    char pos_result[5];
    char neg_result[5];

    itoa(pos_input, pos_result);
    itoa(neg_input, neg_result);

    mu_assert("failed to convert positive number.", strcmp(pos_result, pos_expected) == 0);
    mu_assert("failed to convert negative number.", strcmp(neg_result, neg_expected) == 0);
    return 0;
}

static char* all_tests()
{
    mu_run_test(test_reverse);
    mu_run_test(test_itoa);
    return 0;
}
