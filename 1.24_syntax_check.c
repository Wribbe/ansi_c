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

int pop(void)
{
    if (root == NULL) {
        return 0;
    }

    Node* temp = root;
    root = temp->next;
    int c = temp->c;

    free(temp);

    return c;
}

int main(void)
{
    root = node(' ');
    root->next = NULL;

    int c, other_side;

    while((c = getchar()) != EOF) {
        c = get_relevant_char(c);
        if (c == '{' || c == '(' || c == '[') {
            push(c);
        } else if (c == '}' || c == ')' || c == '[') {
            other_side = pop();
            check_mirror(other_side, c);
        }
    }
}