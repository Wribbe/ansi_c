#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum statuses {ERROR,SUCCESS} STATUS;

STATUS check_input(char* input)
{
    if (strcmp(input, "success") == 0) {
        return SUCCESS;
    } else {
        return ERROR;
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Need additional arguments.\n");
        exit(EXIT_FAILURE);
    }
    if (check_input(argv[1]) == SUCCESS) {
        printf("check resolved ok!\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("check resolved returned ERROR!\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
