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
        if (ch == '#') {
            break;
        }
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
    if (strlen(number) == 0) {
        for (int i = 0; i < strlen(string); i++) {
            if (!isspace(string[i]) && !semicolon) {
                exit(EXIT_FAILURE);
            }
        }
        return 0;
    } else {
        return strtof(number, NULL);
    }
}

void reset(char string[], int len)
{
    for(int i = 0; i < len; i++) {
        string[i] = ' ';
    }
}

int main()
{
    int ch, i;
    float total = 0;
    i = 0;
    char current_line[100];
    while ((ch = getchar()) != EOF) {
        if (ch == '\n' || ch == '#') {
            current_line[i+1] = '\0';
            if (current_line[0] != '#' && strlen(current_line) > 1) {
                printf("checking value for line: %s\n",current_line);
                total += get_number(current_line);
                reset(current_line, 100);
            }
            i = 0;
            while(ch != '\n') {
                ch = getchar();
            }
        } else {
            current_line[i++] = ch;
        }
    }
    printf("Current total: %2.2f\n",total);
}
