/* 2.8_rigthrot: write a function rightrot(x,n) that returns the value
 * of the integer x rotated to the right by n bit positions. */

#include <stdlib.h>
#include <stdio.h>

#define unused(x) (void) x


unsigned int get_bits(unsigned int number) {
    if (number == 0 || number == 1) {
        return number;
    }
    return (number % 2 + get_bits(number/2)*10);
}

int length(int x) {
    int i = 0;
    if (x == 0) {
        return 1;
    }
    while(x != 0) {
        x = x >> 1;
        i++;
    }
    return i;
}

int rotate(int x, int rotations)
{
    int rightmost_bit = 0;
    int bitlength = length(x);
    while (rotations > 0) {
        rightmost_bit = x % 2;
        x = x >> 1;
        x = x | rightmost_bit << (bitlength-1);
        rotations--;
    }
    return x;
}

int strtoi(char* string)
{
    return (int) strtol(string, NULL, 10);
}

int main(int argc, char* argv[])
{
    int num_args = 2;
    if (argc < num_args+1) {
        printf("Need %d arguments.\n",num_args);
        exit(EXIT_FAILURE);
    }
    int number = strtoi(argv[1]);
    int rotations = strtoi(argv[2]);

    int rotated_number = rotate(number, rotations);
    printf("Started with %d --> %d\n",number,get_bits(number));
    printf("After rotating %d turns --> %d\n",rotations, get_bits(rotated_number));
}
