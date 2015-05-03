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

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("[ERROR] Provide at least two arguments.\n");
        EXIT_FAILURE;
    }
}
