/* 3.3_expand: write a function expand(s1,s2) that expands shorthand notations
 * like a-z in the string s1 to the complete sequence abc..z in s2.
 * Allow letters/numbers and upper and lower case.
 * examples: a-b-c, a-z0-9, -a-z */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "minunit.h"

char* get_split_interval(char start1, char stop1, char start2, char stop2);

char* get_chars(char start, char end)
{
    if (start > end) {
        if(isdigit(start) && isdigit(end)) {
            return get_chars(end, start);
        }
        return get_split_interval(start, 'z', 'A', end);
    } else if (isupper(start) && islower(end)) {
        return get_split_interval(start, 'Z', 'a', end);
    }
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

char* get_split_interval(char start1, char stop1, char start2, char stop2)
{
        char* first = get_chars(start1, stop1);
        char* second = get_chars(start2, stop2);
        int length = strlen(first)+strlen(second)+1;
        char* return_string = malloc(sizeof(char)*length);
        strcat(return_string, first);
        strcat(return_string, second);
        free(first);
        free(second);
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
    int i, num_tokens;
    char** tokens;

    num_tokens = parse_input(input, &tokens);
    if (num_tokens == 3) {
        if (strlen(tokens[1]) > 1) {
            *result = get_split_interval(tokens[0][0], tokens[1][0], tokens[1][1], tokens[2][0]);
        } else {
            *result = get_split_interval(tokens[0][0], tokens[1][0], tokens[1][0]+1, tokens[2][0]);
        }
    } else {
        *result = get_chars(tokens[0][0],tokens[1][0]);
    }
    for (i = 0; i < num_tokens; i++) {
        printf("Token %d: %s\n",i,tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    printf("Result: %s\n",*result);
}

int main(void)
{
    run_tests();
}

//------------------------------------------------------------------------------
//-- Tests
//------------------------------------------------------------------------------

static char* expand_test(char* message, char* input, char* expected)
{
    char* result;
    expand(input, &result);
    mu_assert(message, strcmp(result, expected) == 0);
    free(result);
    return 0;
}


static char* expand_test_number_string()
{
    expand_test("expand did not produce the string 1 to 9.", "1-9", "123456789");
    return 0;
}

static char* expand_test_number_string_wrong_order()
{
    expand_test("expand did not produce the string 1 to 9.", "9-1", "123456789");
    return 0;
}

static char* expand_test_alpha_string_lowercase()
{
    expand_test("expand did not produce the lower case alphabet.", "a-z", "abcdefghijklmnopqrstuvwxyz");
    return 0;
}

static char* expand_test_alpha_string_uppercase()
{
    expand_test("expand did not produce the upper case alphabet.", "A-Z", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    return 0;
}

static char* expand_test_alpha_string_mixed_case_lower_first()
{
    expand_test("expand did not produce the mixed case alphabet (lower fist).", "a-Z",
                "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    return 0;
}

static char* expand_test_alpha_string_mixed_case_upper_first()
{
    expand_test("expand did not produce the mixed case alphabet (upper first).", "A-z",
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    return 0;
}

static char* expand_test_alphanumeraical_lowercase()
{
    expand_test("expand dit not produce the correct lowercase alphanumerical string.", "a-z1-9",
                "abcdefghijklmnopqrstuvwxyz123456789");
    return 0;
}

static char* expand_test_alphanumeraical_mixedcase()
{
    expand_test("expand dit not produce the correct mixedcase alphanumerical string.", "a-Z1-9",
                "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789");
    return 0;
}

static char* expand_test_numericalalpha_mixedcase()
{
    expand_test("expand dit not produce the correct mixedcase alphanumerical string.", "1-9a-Z",
                "123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    return 0;
}

static char* expand_test_abc()
{
    expand_test("expand dit not produce the correct abc string.", "a-b-c", "abc");
    return 0;
}

static char* all_tests()
{
    mu_run_test(expand_test_number_string);
    mu_run_test(expand_test_number_string_wrong_order);
    mu_run_test(expand_test_alpha_string_lowercase);
    mu_run_test(expand_test_alpha_string_uppercase);
    mu_run_test(expand_test_alpha_string_mixed_case_lower_first);
    mu_run_test(expand_test_alpha_string_mixed_case_upper_first);
    mu_run_test(expand_test_alphanumeraical_lowercase);
    mu_run_test(expand_test_alphanumeraical_mixedcase);
    mu_run_test(expand_test_numericalalpha_mixedcase);
    mu_run_test(expand_test_abc);
    return 0;
}
