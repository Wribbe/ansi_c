#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s\n", longest);
        printf("Longest line: %d\n",max);
    }
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    /* Ex 1-16, make main count arbitrary line length */

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; i++) {
        s[i] = c;
    } 
    if (c == '\n') {
        s[i] = c;
        i++;
    }/* don't put more chars in the array */
    s[i] = '\0';

    /* continue counting */
    while((c=getchar()) != EOF && c!='\n') {
        i++;
    }

    return i;
}

void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
