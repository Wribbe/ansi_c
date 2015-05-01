/* Write function htoi(s) that converts a string to
 * hexadecimal digits into equivalent integer value. */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int htoi(char* string)
{
    int i;
    int c;
    for(i = 0; (c = string[i]) != '\0'; i++) {
        c = tolower(c);
        putchar(c);
    }
    return 1;
}

int main(void)
{
    htoi("tesT");
}
