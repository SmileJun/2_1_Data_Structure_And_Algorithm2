#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BTreeNode * makeExpTree(char exp[]);
int evaluateExpTree(BTreeNode * bTree);

void showPrefixTypeExp(BTreeNode * bTree);
void showInfixTypeExp(BTreeNode * bTree);
void showPostfixTypeExp(BTreeNode * bTree);

#endif
