/* 2.6 setbits(x,p,n,y) - return x with the n bits
 * that begin at position p set to the rightmost n
 * bits of y, other bits unchanged. */

#include <stdlib.h>
#include <stdio.h>

int setbits(int x,int p,int n,int y)
{
    int ybits = ~(~0 << n) & y;
    return ybits;
}

int stoi(char* string)
{
    return (int) strtol(string, NULL, 10);
}

int main(int argc, char* argv[])
{
    int num_arguments = 4;
    if (argc < 1+num_arguments) {
        printf("[ERROR] Provide at least %d arguments.\n",num_arguments);
        EXIT_FAILURE;
    }
    int result = setbits(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]), stoi(argv[4]));
    printf("result: %d\n", result);
}
