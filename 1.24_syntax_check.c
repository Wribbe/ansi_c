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

Node* root;

Node* node(int c)
{
    Node* pointer = (Node*) malloc(sizeof(Node));
    if (pointer == NULL) {
        return pointer;
    }
    pointer->c = c;
    return pointer;
}

void push(int c)
{
    Node* temp = node(c);
    temp->next=root;
    root=temp;
}

int main(void)
{
    root = node('a');
    root->next = NULL;

    push('b');
    push('c');

    printf("root %c\n",root->c);
}
