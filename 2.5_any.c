/* 2.5_any.c - Write the function any(s1, s2) that takes two strings and
 * returns the first location where a string from s2 occurs in s1. */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define unused(x) (void)x

int any(char* string1, char* string2)
{
    int chars['~'] = {0};
    int c, i = 0;
    while ((c = string2[i++]) != '\0') {
        chars[c] = 1;
    }
    c = i = 0;
    while ((c = string1[i]) != '\0') {
        if (chars[c]) {
            return i;
        }
        i++;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Supply at least 2 parameters.\n");
        EXIT_FAILURE;
    }

    int result = any(argv[1], argv[2]);
    if (result >= 0) {
        printf("first char from string2 in string1 is \'%c\' at position: %d\n",argv[1][result], result+1);
    } else {
        printf("None of the chars from string2 were present in string1.\n");
    }
}
