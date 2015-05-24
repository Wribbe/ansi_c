/* 3.3_expand: write a function expand(s1,s2) that expands shorthand notations
 * like a-z in the string s1 to the complete sequence abc..z in s2.
 * Allow letters/numbers and upper and lower case.
 * examples: a-b-c, a-z0-9, -a-z */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "minunit.h"

char* get_chars(char start, char end)
{
    int i, length, k;
    length = (end-start)+2;
    char* return_string;
    return_string = malloc(sizeof(char)*length);
    k = 0;
    for(i = start; i<= end; i++) {
        return_string[k++] = i;
    }
    return_string[k] = '\0';

    return return_string;
}

int parse_input(char input[], char** tokens[])
{
    int length, num_dashes;

    length = strlen(input);
    char temp_string[length];
    strcpy(temp_string, input);

    num_dashes = 0;
    for(int i = 0; i<length; i++) {
        if (input[i] == '-') {
            num_dashes++;
        }
    }
    num_dashes++;

    char** return_data = malloc(sizeof(char*)*(num_dashes));
    int token_length, i;

    i = 0;

    char* current_token;
    current_token = strtok(temp_string, "-");
    while (current_token != NULL) {
        token_length = strlen(current_token)+1;
        char* return_string = malloc(sizeof(char)*token_length);
        strcpy(return_string, current_token);
        return_data[i++] = return_string;
        current_token = strtok(NULL, "-");
    }

    *tokens = return_data;
    return num_dashes;
}

void expand(char input[], char** result)
{
    int num_tokens;
    char** tokens;
    num_tokens = parse_input(input, &tokens);
    *result = get_chars('1','9');
    printf("num_tokens: %d\n",num_tokens);
    int i;
    for (i = 0; i<num_tokens; i++) {
        printf("token#%d: %s\n",i,tokens[i]);
    }
}

int main(void)
{
    run_tests();
}

//------------------------------------------------------------------------------
//-- Tests
//------------------------------------------------------------------------------

static char* expand_test_number_string()
{
    char* input = "1-9";
    char* result;
    char* expected = "123456789";
    expand(input, &result);
    mu_assert("expand did not produce the string 1 to 9.", strcmp(result, expected) == 0);
    return 0;
}

static char* expand_test_alpha_string_lowercase()
{
    char* input = "a-z";
    char* result;
    char* expected = "abcdefghijklmnopqrstuvwxyz";
    expand(input, &result);
    mu_assert("expand did not produce the lower case alphabet.", strcmp(result, expected) == 0);
    return 0;
}

static char* expand_test_alpha_string_uppercase()
{
    char* input = "A-Z";
    char* result;
    char* expected = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
    expand(input, &result);
    mu_assert("expand did not produce the upper case alphabet.", strcmp(result, expected) == 0);
    return 0;
}

static char* expand_test_alpha_string_mixed_case_lower_first()
{
    char* input = "a-Z";
    char* result;
    char* expected = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXYZ";
    expand(input, &result);
    mu_assert("expand did not produce the mixed case alphabet (lower fist).", strcmp(result, expected) == 0);
    return 0;
}

static char* expand_test_alpha_string_mixed_case_upper_first()
{
    char* input = "A-z";
    char* result;
    char* expected = "ABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvwxyz";
    expand(input, &result);
    mu_assert("expand did not produce the mixed case alphabet (upper first).", strcmp(result, expected) == 0);
    return 0;
}

static char* expand_test_alphanumeraical_lowercase()
{
    char* input = "a-z1-9";
    char* result;
    char* expected = "abcdefghijklmnopqrstuvwxyz123456789";
    expand(input, &result);
    mu_assert("expand dit not produce the correct lowercase alphanumerical string.", strcmp(result, expected) == 0);
    return 0;
}

static char* all_tests()
{
    mu_run_test(expand_test_number_string);
    mu_run_test(expand_test_alpha_string_lowercase);
    mu_run_test(expand_test_alpha_string_uppercase);
    mu_run_test(expand_test_alpha_string_mixed_case_lower_first);
    mu_run_test(expand_test_alpha_string_mixed_case_upper_first);
    mu_run_test(expand_test_alphanumeraical_lowercase);
    return 0;
}
