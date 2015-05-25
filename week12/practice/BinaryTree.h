#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct bTreeNode
{
    BTData data;
    struct bTreeNode * left;
    struct bTreeNode * right;
} BTreeNode;

BTreeNode * makeBTreeNode(void);
BTData getData(BTreeNode * bTreeNode);
void setData(BTreeNode * bTreeNode, BTData data);

BTreeNode * getLeftSubTree(BTreeNode * bTreeNode);
BTreeNode * getRightSubTree(BTreeNode * bTreeNode);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MAkeRightSubTree(BTreeNode * main, BTreeNode * sub);

#endif
