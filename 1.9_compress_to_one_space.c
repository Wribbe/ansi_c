#include <stdio.h>

int main()
{
    /* copy input to output but scrap multiple spaces 
     * and replace with a single space. */

    char multiple_spaces = 0;

    int character;

    while((character = getchar()) != EOF) {
        if (character == ' ') {
            if (multiple_spaces) {
                continue;
            } else {
                putchar(character);
                multiple_spaces = 1;
            }
        } else {
            multiple_spaces = 0;
            putchar(character);
        }
    }
}
