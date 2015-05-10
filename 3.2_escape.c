/* exercise 3-2: write a function escape(s,t) that converts
 * characters from escape characters to ex. \n and \t.
 * Use switch-case and write a function to reverse the escape function */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printwithfunc(char* string, void func(char*))
{
    func(string);
}

void printme(char* string)
{
    printf("ME: %s\n",string);
}

int main(int argc, char* argv[])
{
    int num_arguments = 1;
    if (argc <= num_arguments) {
        printf("Need att least %d argmuent.\n", num_arguments);
        exit(EXIT_FAILURE);
    }
    printwithfunc("this is a test", printme);
}
