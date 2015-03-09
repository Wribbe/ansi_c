#include <stdio.h>

int main()
{
    int tabs = 0;
    int newlines = 0;
    int spaces = 0;

    int ch;

    while((ch = getchar()) != EOF) {
        if (ch == '\t') {
            tabs++;
        } else if (ch == ' ') {
            spaces++;
        } else if (ch == '\n') {
            newlines++;
        }
    }
    printf("tabs:%d spaces:%d newlines:%d\n",tabs,spaces,newlines);
}
