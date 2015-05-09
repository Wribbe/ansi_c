/* 2.10_conditional_lower: write a lower function that returns the
 * lowercase word using conditional expression */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* args[])
{
    int min_arguments = 1;
    if (argc < min_arguments+1) {
        printf("Need at least %d argument.\n",min_arguments);
        exit(EXIT_FAILURE);
    }
}
