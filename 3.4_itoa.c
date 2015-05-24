/* Exercise 3.4_itoa.c: write a function that converts digits in a number
 * to the corresponding characters in a string. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "minunit.h"

#define DEBUG 1

STATUS reverse(char input[])
{
    int temp, i, j;

    for(i = 0; j = strlen(input)-1, i < j; i++, j--) {
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    return SUCCESS;

int main(void)
{
    run_tests();
}

//------------------------------------------------------------------------------
//-- Tests
//------------------------------------------------------------------------------

static char* test_reverse()
{
    char input[] = "abc";
    char* expected = "cab";
    reverse(input);
    mu_assert("Result from reveres incorrect.", strcmp(input, expected) == 0);
    return 0;
}

static char* all_tests()
{
    mu_run_test(test_reverse);
    return 0;
}
