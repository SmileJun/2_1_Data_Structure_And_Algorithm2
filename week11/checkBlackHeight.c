#include <stdio.h>

typedef enum boolEnum { TRUE = 1, FALSE = 0 } Boolean;
typedef enum color { RED, BLACK } Color;

typedef struct node_t
{
    int data;
    struct node_t * left;
    struct node_t * right;
    Color color;
} Node;

int checkBlackHeight(Node *node)
{
    if (node == NULL) return 0;

    int leftBlackHeight = 0;
    int rightBlackHeight = 0;

    if (!(node->left) || node->left->color == BLACK)
        leftBlackHeight = checkBlackHeight(node->left) + 1;
    else
        leftBlackHeight = checkBlackHeight(node->left);

    if (!(node->right) || node->right->color == BLACK)
        rightBlackHeight = checkBlackHeight(node->right) + 1;
    else
        rightBlackHeight = checkBlackHeight(node->right);

    if (leftBlackHeight == -1 || rightBlackHeight == -1)
        return -1;

    if (leftBlackHeight != rightBlackHeight)
        return -1;

    return leftBlackHeight;
}
