/* Write a program to check basic C syntax errors like
 * unbalanced parentheses, brackets and braces.
 * Don't forget about quotes (single/double), escape
 * sequences and comments. */

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int c;
    struct Node* next;
} Node;

//Node* push(Node*, Node*)
//{
//
//}

Node* node(int c)
{
    Node* pointer = (Node*) malloc(sizeof(Node));
    if (pointer == NULL) {
        return pointer;
    }
    pointer->c = c;
    return pointer;
}

int main(void)
{
    Node* root = node('a');
    printf("root %c\n",root->c);
}
