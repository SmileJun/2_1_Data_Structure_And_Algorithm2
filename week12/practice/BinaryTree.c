#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

BTreeNode * makeBTreeNode(void)
{
    BTreeNode * node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->left = NULL;
    node->right = NULL;
    return node;
}

BTData getData(BTreeNode * bTreeNode)
{
    return bTreeNode->data;
}

void setData(BTreeNode * bTreeNode, BTData data)
{
    bTreeNode->data = data;
}

BTreeNode * getLeftSubTree(BTreeNode * bTreeNode)
{
    return bTreeNode->left;
}

BTreeNode * getRightSubTree(BTreeNode * bTreeNode)
{
    return bTreeNode->right;
}

void makeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    if (main->left != NULL)
        free(main->left);

    main->left = sub;
}

void makeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    if (main->right != NULL)
        free(main->right);

    main->right = sub;
}
