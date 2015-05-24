#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 1

#define debug_printf(fmt, ...) \
                     do { if (DEBUG) fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, \
                                             __LINE__, __func__, __VA_ARGS__); } while (0)

typedef enum statuses {ERROR,SUCCESS} STATUS;

STATUS check_input(char* input)
{
    if (strcmp(input, "success") == 0) {
        debug_printf("%s\n", "Trying input against \"sucess\".\n");
        return SUCCESS;
    } else {
        debug_printf("%s\n", "Input check failed, returning ERROR.");
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
