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

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while(low <= high) {
        mid = (low+high)/2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
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

    int* array = {0};
    int size = int_array(comma_separated_numbers, &array);

    int result = binsearch(find, array, size);

    if (result == -1) {
        printf("could not find %d\n",find);
    } else {
        printf("found %d at position %d.\n",find,result);
    }

    free(array);
}
