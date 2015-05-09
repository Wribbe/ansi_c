/* 2.9_bitcount: write a faster version of bitcount using the
 * x &= (x-1) operation. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int book_bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>=1) {
        if (x & 0x1) {
            b++;
        }
    }
    return b;
}

int own_bitcount(unsigned x)
{
    int b;
    for(b=0; x!=0; x &= (x-1)) {
        b++;
    }
    return b;
}

unsigned strtoi(char* string)
{
    return (unsigned) strtoul(string, NULL, 10);
}

int main(int argc, char* argv[])
{
    int min_arguments = 2;
    if (argc < min_arguments+1) {
        printf("Need at least %d arguments.\n", min_arguments);
        exit(EXIT_FAILURE);
    }

    int result, number = 0;
    char* command = "";

    number = strtoi(argv[2]);
    command = argv[1];

    if (strcmp(command,"book") == 0) {
        result = book_bitcount(number);
    } else if (strcmp(command, "own") == 0) {
        result = own_bitcount(number);
    } else {
        printf("No such command %s.\n", command);
        exit(EXIT_FAILURE);
    }

    printf("Result of running with %s: %d\n",command,result);
}
