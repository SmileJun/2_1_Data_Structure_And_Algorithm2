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
BTData getData(BTreeNode * bTree);
void setData(BTreeNode * bTree, BTData data);

BTreeNode * getLeftSubTree(BTreeNode * bTree);
BTreeNode * getRightSubTree(BTreeNode * bTree);

void makeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void makeRightSubTree(BTreeNode * main, BTreeNode * sub);

typedef void visitFuctPtr(BTData data);

void preOrderTraverse(BTreeNode * bTree, visitFuctPtr action);
void inOrderTraverse(BTreeNode * bTree, visitFuctPtr action);
void postOrderTraverse(BTreeNode * bTree, visitFuctPtr action);

void deleteTree(BTreeNode * bTree);

#endif
