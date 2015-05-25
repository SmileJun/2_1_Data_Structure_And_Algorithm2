#include "BinaryTree.h"
#include <stdio.h>

int main(void)
{
    BTreeNode * bt1 = MakeBTreeNode();
    BTreeNode * bt2 = MakeBTreeNode();
    BTreeNode * bt3 = MakeBTreeNode();
    BTreeNode * bt4 = MakeBTreeNode();
    
    setData(bt1, 1);
    setData(bt2, 2);
    setData(bt3, 3);
    setData(bt4, 4);
    
    makeLeftSubTree(bt1, bt2);
    makeRightSubTree(bt1, bt3);
    makeLeftSubTree(bt2, bt4);

    printf("%d \n", getData(getLeftSubTree(bt1)));

    printf("%d \n", getData(getLeftSubTree(GetLeftSubTree(bt1))));

    return 0;
}
