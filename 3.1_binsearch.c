/* 3.1_binsearch: modify book version in such a way that there is only one
 * logical test inside the for-loop. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define unused(x) (void) x

int strtoi(char* string)
{
    return (int) strtol(string, NULL, 10);
}

int int_array(char* string, int** array_address)
{
    int i, ch, size;
    i = ch = 0;
    size = 1;
    while((ch = string[i++]) != '\0') {
        if (ch == ',') {
            size++;
        }
    }
    int* array = malloc(sizeof(int) * size);
    char* delimiter = ",";
    char* token = strtok(string, delimiter);
    i = 0;
    while(token != NULL) {
        array[i++] = strtoi(token);
        token = strtok(NULL, delimiter);
    }
    *array_address = array;
    return size;
}

int main(int argc, char* argv[])
{
    int min_args = 2;
    if (argc <= min_args) {
        printf("Need at least %d argmuents.\n", min_args);
        exit(EXIT_FAILURE);
    }

    char* comma_separated_numbers = argv[1];
    int find = strtoi(argv[2]);

    unused(find);
    int* array = {0};
    int size = int_array(comma_separated_numbers, &array);
    printf("size of array is %d\n",size);
    for (int i=0; i<size; i++) {
        printf("element %d equals: %d\n",i,array[i]);
    }
}
