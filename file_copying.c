#include <stdio.h>

/* copy input to output: 1st version */
int main() 
{
        int c;

        printf("EOF: %d\n",EOF);
        while((c = getchar()) != EOF) {
                printf("getchar() != EOF was not 0, but %d\n",c != EOF);
                putchar(c);
        }
}
