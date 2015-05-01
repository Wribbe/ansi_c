/* replicate the for loop:
 * for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; i++)
 * but without && or ||. */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int i, c = 0;
    int lim = 10;
    while(1) {
        if (i == lim-1) {
            break;
        } else {
            c = getchar();
            if (c == '\n') {
                break;
            } else if (c == EOF) {
                break;
            } else {
                i++;
                putchar(c);
            }
        }
    }
}
