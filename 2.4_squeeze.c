/* 2.4 squeeze: write a functions that takes string1 and string2 and
 * deletes all characters from string1 that matches any character in
 * string2 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int floor_char(char c)
{
    return tolower(c)-'a';
}

void trim(char* string1, char* string2)
{
    int chars[26] = { 0 };
    int i,c = 0;
    while ((c = string2[i++]) != '\0') {
        chars[floor_char(c)] = 1;
    }
    i = c = 0;
    int j = 0;
    while ((c = string1[i++]) != '\0') {
        if (chars[floor_char(c)]) {
            continue;
        } else {
            string1[j++] = c;
        }
    }
    string1[j] = '\0';
    printf("resulting string: %s\n",string1);
}

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Note enough parameters, provide at least 2.\n");
        exit(1);
    }
    trim(argv[1],argv[2]);
}
