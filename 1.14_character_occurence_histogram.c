#include <stdio.h>

/* count the occurrence of letters in the input */

#define TO_LOWERCASE 32
#define NUMBER_OF_LETTERS 26

int main()
{
    int letters[NUMBER_OF_LETTERS];
    int ch; 

    for (int i = 0; i<NUMBER_OF_LETTERS; i++) {
        letters[i] = 0;
    }

    while((ch = getchar()) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += TO_LOWERCASE;
        }
        if (ch >= 'a' && ch <= 'z') {
            letters[ch - 'a']++;
        }
    }
    for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
        printf("%c: ",i+'a');
        int letter_freq = letters[i];
        for(int j = 0; j < letter_freq; j++) {
            printf("|");
        }
        printf("\n");
    }
}
