/* Exercise 3.5_itob.c: Write a function itob(n,s,b) that converts the ingeger
 * into a base b and outputs it as a string in s. */

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

STATUS itob(int n, char result[], int base)
{
    int sign, ch, i;
    sign = n;
    i = 0;

    do {
        ch = abs(n % base) + '0';
        n = n/base;
        result[i++] = ch;
    } while (n != 0);

    if (sign < 0) {
        result[i++] = '-';
    }

    result[i] = '\0'; // The reversal only goes to i-1.
    reverse(result);

    return SUCCESS;
}

STATUS itoa(int n, char result[])
{
    return itob(n, result, 10);
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
    char neg_result[6];

    itoa(pos_input, pos_result);
    itoa(neg_input, neg_result);

    mu_assert("failed to convert positive number.", strcmp(pos_result, pos_expected) == 0);
    mu_assert("failed to convert negative number.", strcmp(neg_result, neg_expected) == 0);
    return 0;
}

static char* test_itob_binary()
{
    int input = 3;
    int base = 2;

    char* expected = "11";
    char result[3];

    itob(input, result, base);
    mu_assert("itob did not do the correct binary conversion.", strcmp(result, expected) == 0);
    return 0;
}

static char* test_itob_hexa()
{
    int input = 90;
    int base = 16;

    char* expected = "5A";
    char result[3];

    itob(input, result, base);
    mu_assert("itob did not do the correct hexadecimal conversion.", strcmp(result, expected) == 0);
    return 0;
}

static char* all_tests()
{
    mu_run_test(test_reverse);
    mu_run_test(test_itoa);
    mu_run_test(test_itob_binary);
    mu_run_test(test_itob_hexa);
    return 0;
}

