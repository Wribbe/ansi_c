/* 3.1_binsearch: modify book version in such a way that there is only one
 * logical test inside the for-loop. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argv, char* argc[])
{
    int min_args = 2;
    if (argv <= min_args) {
        printf("Need at least %d argmuents.\n", min_args);
        exit(EXIT_FAILURE);
    }
}
