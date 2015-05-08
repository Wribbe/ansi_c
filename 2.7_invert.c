/* 2.7 write a function invert(x,p,n) that returns x with
 * the n bits that begin at position p inverted. */

#include <stdlib.h>
#include <stdio.h>

#define unused(x) (void)x

unsigned int get_bits(int num) {
    if (num == 1 || num == 0 ) {
        return num;
    }
    return (num%2 + get_bits((num/2))*10);
}

int stoi(char* string)
{
    return (int) strtol(string, NULL, 10);
}

int get_mask(int p,int n) {
    return  ~((~0) << n) << p;
}

int main (int argc, char* argv[]) {

    int min_args = 3;
    if (argc < min_args+1) {
        printf("need at least %d arguments.\n",min_args);
        exit(EXIT_FAILURE);
    }

    int x, p, n;

    x = stoi(argv[1]);
    p = stoi(argv[2]);
    n = stoi(argv[3]);

    printf("starting with %d -> %d\n",x,get_bits(x));
    int mask = get_mask(n, p);
    printf("generating mask %d\n",get_bits(mask));
    int masked_x = x ^ mask;
    printf("x after XOR'ing with the mask: %d\n",get_bits(masked_x));
}

/*
 5 4 3 2 1 0
 -----------
 0 0 0 0 0 0

 xor?

 1 0 1 1 0 0 with n=3 and p=1

 -->

 1 1 0 0 0 0

 --

 1 0 1 1 0 0
 0 1 1 1 0 0 xor
 ----------------
 1 1 0 0 0 0
 */
