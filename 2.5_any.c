/* 2.5_any.c - Write the function any(s1, s2) that takes two strings and
 * returns the first location where a string from s2 occurs in s1. */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define unused(x) (void)x

void any(char* string1, char* string2)
{
    int chars['~'] = {0};
    unused(chars);
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Supply at least 2 parameters.\n");
        EXIT_FAILURE;
    }

    any(argv[1], argv[2]);
}
