#include <stdio.h>

/* Write a program that prints a histogram of the lengths 
 * of the words in its input. */

#define OUT_WORD 0
#define IN_WORD 1
#define MAX_LENGTH 15

int main()
{
    int current_char, status, current_length = 0;
    int lengths[MAX_LENGTH];

    for (int i = 0; i < MAX_LENGTH; i++) {
        lengths[i] = 0;
    }

    while((current_char = getchar()) != EOF) {
        if(current_char == ' ' || current_char == '\t' || current_char == '\n') {
            if(status == IN_WORD) {
                if(current_length > MAX_LENGTH) {
                    lengths[MAX_LENGTH]++;
                } else {
                    lengths[current_length-1]++;
                }
                status = OUT_WORD;
                current_length = 0;
            }
        } else { /* non whitespace charachter. */
            current_length++;
            status = IN_WORD;
        }
    }
    printf("lengths:\n");
    for (int i = 0; i < MAX_LENGTH; i++) {
        printf("%2d: ",i+1);
        for(int j = 0; j < lengths[i]; j++) {
            printf("|");
        }
        printf("\n");
    }
}
