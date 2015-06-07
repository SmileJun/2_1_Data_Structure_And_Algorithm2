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

BTreeNode * getLeftSubTree(BTreeNode * bTree)
{
    return bTree->left;
}

BTreeNode * getRightSubTree(BTreeNode * bTree)
{
    return bTree->right;
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

BTreeNode * removeLeftSubTree(BTreeNode * bTree)
{
    BTreeNode * delNode;

    if (bTree != NULL)
    {
        delNode = bTree->left;
        bTree->left = NULL;
    }
    return delNode;
}

BTreeNode * removeRightSubTree(BTreeNode * bTree)
{
    BTreeNode * delNode;

    if (bTree != NULL)
    {
        delNode = bTree->right;
        bTree->right = NULL;
    }
    return delNode;
}

void changeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    main->left = sub;
}

void changeRightSubTree(BtreeNode * main, BTreeNode * sub)
{
    main->right = sub;
}

void preOrderTraverse(BTreeNode * bTree, visitFuctPtr action)
{
    if (bTree == NULL)
        return;
    
    action(bTree->data);
    preOrderTraverse(bTree->left, action);
    preOrderTraverse(bTree->right, action);
}

void inOrderTraverse(BTreeNode * bTree, visitFuctPtr action)
{
    if (bTree == NULL)
        return;
    
    inOrderTraverse(bTree->left, action);
    action(bTree->data);
    inOrderTraverse(bTree->right, action);
}

void postOrderTraverse(BTreeNode * bTree, visitFuctPtr action)
{
    if (bTree == NULL)
        return;
    
    postOrderTraverse(bTree->left, action);
    postOrderTraverse(bTree->right, action);
    action(bTree->data);
}

void deleteTree(BTreeNode * bTree)
{
    if (bTree == NULL)
        return;

    deleteTree(bTree->left);
    deleteTree(bTree->right);
    free(bTree);
}

