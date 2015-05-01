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

int check_mirror(int a, int b)
{
    if (a == '{' && b == '}') {
        return 1;
    } else if (a == '(' && b == ')') {
        return 1;
    } else if (a == '[' && b == ']') {
        return 1;
    }
    printf("result failed for %c %c\n",a,b);
    return 0;
}
int ignore_comments(int c)
{
    if (c == '/') {
        int d = getchar();
        if (d == '*') {
            c = getchar();
            d = getchar();
            while(c != '*' || d != '/') {
                c = d;
                d = getchar();
            }
            return getchar();
        } else {
            return d;
        }

    } else {
        return c;
    }
}

int ignore_quotes(int c)
{
    int d;
    if (c == '\'' || c == '"') {
        while((d = getchar()) != EOF) {
            if (d == '\\') {
                getchar();
                continue;
            } else if (d == c) {
                break;
            }
        }
    }
    if (d == EOF) {
        return EOF;
    }
    return c;
}

int get_relevant_char(int c)
{
    int non_comment_char;
    non_comment_char = ignore_comments(c);
    return ignore_quotes(non_comment_char);
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
