#include "BinaryTree.h"
#include <stdio.h>

void showIntData(int data);

int main(void)
{
    BTreeNode * bt1 = makeBTreeNode();
    BTreeNode * bt2 = makeBTreeNode();
    BTreeNode * bt3 = makeBTreeNode();
    BTreeNode * bt4 = makeBTreeNode();
    BTreeNode * bt5 = makeBTreeNode();
    BTreeNode * bt6 = makeBTreeNode();
    
    setData(bt1, 1);
    setData(bt2, 2);
    setData(bt3, 3);
    setData(bt4, 4);
    setData(bt5, 5);
    setData(bt6, 6);
    
    makeLeftSubTree(bt1, bt2);
    makeRightSubTree(bt1, bt3);
    makeLeftSubTree(bt2, bt4);
    makeRightSubTree(bt2, bt5);
    makeRightSubTree(bt3, bt6);

    preOrderTraverse(bt1, showIntData);
    printf("\n");
    inOrderTraverse(bt1, showIntData);
    printf("\n");
    postOrderTraverse(bt1, showIntData);
    printf("\n");

    deleteTree(bt1);

    return 0;
}

void showIntData(int data)
{
    printf("%d ", data);
}
