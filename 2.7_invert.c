/* 2.7 write a function invert(x,p,n) that returns x with
 * the n bits that begin at position p inverted. */

#include <stdlib.h>
#include <stdio.h>

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

int invert(int x,int p,int n) {
    int shift = (p+1-n);
    if (shift < 0) {
        shift = 0;
    }
    int mask = ~((~0) << n) << shift;
    return mask;
}

int main (int argc, char* argv[]) {
    printf("%u\n",get_bits(invert(256,1,3)));
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
