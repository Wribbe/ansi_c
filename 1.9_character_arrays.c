#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);


///* print longest input line */
//int main()
//{
//    int len;    /* current line length */
//    int max;    /* maximum length seen so far */
//    char line[MAXLINE]; /* current input line */
//    char longest[MAXLINE]; /* longest line saved here */
//
//    max = 0;
//    /* Ex 1-17, print all lines > 80 */
//    while ((len = getline(line, MAXLINE)) > 0) {
//        if (len > max) {
//            max = len;
//            copy(longest, line);
//        }
//        if (len > 80) {
//            printf("%s",line);
//        }
//    }
//    if (max > 0) {
//        printf("%s\n", longest);
//        printf("Longest line: %d\n",max);
//    }
//    return 0;
//}  

/* Ex 1-18, remove trailing whitespace and empty lines */

int main()
{
    char line[MAXLINE];
    int len;

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len == 1) {    
            char c = line[0];
            if (c == '\n' || c == '\t' || c == ' ') {
                continue;
            }
        }
        printf("%s",line);
    }
}

int getline(char s[], int lim)
{
    int c, i, pos = 0;
    char multiple_whitespace = 0;

    /* Ex 1-16, make main count arbitrary line length */
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; i++) {
        if((c == ' ' || c == '\t') && multiple_whitespace) {
            continue; /* don't increment pos variable */
        } else if (c == ' ' || c == '\t') {
            multiple_whitespace = 1;
            s[pos++]= c;
        } else {
            multiple_whitespace = 0;
            s[pos++] = c;
        }
    }
    if (c == '\n') {
        s[pos++] = c;
    }/* don't put more chars in the array */
    s[pos] = '\0';

    /* continue counting */
    if( c != EOF && c!='\n' ) {
        while((c=getchar()) != EOF && c!='\n') {
            pos++;
        }
    }

    return pos;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
