#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "minunit.h"

int tests_run = 0;
static char* all_tests();
void run_tests();

static char* test_hello(void);
char* hello(void)
{
    return("HELLO WORLD!");
}

int main(void)
{
    run_tests();
}

static char* all_tests()
{
    mu_run_test(test_hello);
    return 0;
}

void run_tests()
{
    char* result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
}

static char* test_hello(void)
{
    char* string =  hello();
    mu_assert("hello returned wrong string.", strcmp(string, "HELLO WORLD!!") == 0);
    return 0;
}
