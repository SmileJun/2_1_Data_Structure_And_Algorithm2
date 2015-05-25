#include <stdio.h>

typedef struct node {
    node * left;
    node * right;
    int value;
} node_t;

int checkTree(node_t *node)
{
    if (node == NULL) 
        return 1;
    if (node->left != NULL && node->value < node->left.value) 
        return 0;
    if (node->right != NULL && node->value < node->right.value) 
        return 0;
    
    return checkTree(node->left) && checkTree(node->right);
}

int main(void)
{
    return 0;
}
