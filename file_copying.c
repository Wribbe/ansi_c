#include <stdio.h>

/* copy input to output: 1st version */
int main()
{
        printf("EOF: %d\n",EOF);
        int c;
        while((c = getchar() != EOF)) {
                /* Use CTRL-D to produce a EOF.. */
                printf("c: %d\n", c);
        }
        printf("c: %d\n", c);
}
