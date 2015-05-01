/* Write function htoi(s) that converts a string to
 * hexadecimal digits into equivalent integer value. */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void htoi(char* string)
{
    int i;
    int c, sum = 0;
    for(i = 0; (c = string[i]) != '\0'; i++) {
        c = tolower(c);
        if (c >= 'a' && c <= 'f') {
            sum = sum*16 + c-'a'+10;
        } else if (c >= '1' && c <= '9') {
            sum = sum*16 + c-'0';
        } else {
            printf("skipping %c, not valid\n", c);
            continue;
        }
    }
    printf("result of %s is: %d\n",string, sum);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Need at least one parameter.\n");
        exit(0);
    }
    char* string = argv[1];
    int size = sizeof(string)/sizeof(string[0]);
    if (size < 3) {
        htoi(string);
    } else {
        int first, second, i;
        first = tolower(string[0]);
        second = tolower(string[1]);
        if (first == '0' && second == 'x') {
            char new_string[size-2];
            for(i = 2; i<size; i++) {
                new_string[i-2] = string[i];
            }
            htoi(new_string);
        } else {
            htoi(string);
        }
    }
}
