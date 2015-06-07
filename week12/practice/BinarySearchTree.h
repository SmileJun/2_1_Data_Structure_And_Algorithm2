#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

typedef BTData BSTData;


void BSTMakeAndInit(BTreeNode ** root);
BSTData BSTGetNodeData(BTreeNode * bst);


void BSTInsert(BTreeNode ** root, BSTData data);
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);
BTreeNode * BSTRemove(BTreeNode * bst, BSTData target);
void BSTShowAll(BTreeNode * bst);

#endif
