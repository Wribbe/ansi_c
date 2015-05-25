/* course_calculator.c: read input file and calculate total
 * course point for next semester. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

float get_number(char string[])
{
    int ch, i, k;
    char semicolon = 0;
    char number[20];

    i = 0;
    k = 0;

    while((ch = string[i++]) != '\n') {
        if (semicolon) {
            if (!isspace(ch)) {
                number[k++] = ch;
            }
            continue;
        } else if (ch == ':') {
            semicolon = 1;
            continue;
        } else {
            continue;
        }
    }
    number[k] = '\0';
    return strtof(number, NULL);
}

int main()
{
    int ch, i;
    float total = 0;
    i = 0;
    char current_line[100];
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            current_line[i+1] = '\0';
            total += get_number(current_line);
            i = 0;
        } else {
            current_line[i++] = ch;
        }
    }
    printf("Current total: %f\n",total);
}
