/* 2.9_bitcount: write a faster version of bitcount using the
 * x &= (x-1) operation. */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int min_arguments = 1;
    if (argc < min_arguments+1) {
        printf("Need at least %d argument.\n", min_arguments);
        exit(EXIT_FAILURE);
    }
}
