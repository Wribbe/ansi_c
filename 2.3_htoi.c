/* Write function htoi(s) that converts a string to
 * hexadecimal digits into equivalent integer value. */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int htoi(char* string)
{
    int i;
    for(i = 0; string[i] != '\0'; i++) {
        putchar(string[i]);
    }
    return 1;
}

int main(void)
{
    htoi("test");
}
