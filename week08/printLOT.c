#include <stdio.h>

typedef struct node {
    node * leftChild;
    node * rightChild;
    int value;
} Node

int printLevelOrderTraversal(Node *root);

int main(void)
{
    return 0;
}

int printLevelOrderTraversal(Node *root)
{
    if (root == NULL) return false;
}
