/* 2.7 write a function invert(x,p,n) that returns x with
 * the n bits that begin at position p inverted. */

#include <stdlib.h>
#include <stdio.h>


int get_bits(int num) {
    if (num == 1 || num == 0 ) {
        return num;
    }
    return (num%2 + get_bits((num/2))*10);
}

int stoi(char* string)
{
    return (int) strtol(string, NULL, 10);
}

int main (int argc, char* argv[]) {
    printf("%d\n",get_bits(stoi(argv[1])));
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
