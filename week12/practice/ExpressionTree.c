#include "ExpressionTree.h"
#include "ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

BTreeNode * makeExpTree(char exp[])
{
    Stack stack;
    BTreeNode * node;

    int expLen = strlen(exp);
    int i;
   
    stackInit(&stack);

    for (i = 0; i < expLen; ++i)
    {
        node = makeBTreeNode();

        if (isdigit(exp[i]))
            setData(node, exp[i] - '0');
        else
        {
            makeRightSubTree(node, stackPop(&stack));
            makeLeftSubTree(node, stackPop(&stack));
            setData(node, exp[i]);
        }

        stackPush(&stack, node);
    }

    return stackPop(&stack);
}

int evaluateExpTree(BTreeNode * bTree)
{
    int op1, op2;

    if (getLeftSubTree(bTree) == NULL && getRightSubTree(bTree) == NULL)
        return getData(bTree);

    op1 = evaluateExpTree(getLeftSubTree(bTree));
    op2 = evaluateExpTree(getRightSubTree(bTree));

    switch (getData(bTree))
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }       

    return 0;
}

void showNodeData(int data)
{
    if (0 <= data && data <= 9)
        printf("%d ", data);
    else
        printf("%c ", data);
}

void showPrefixTypeExp(BTreeNode * bTree)
{
    preOrderTraverse(bTree, showNodeData);
}

void showInfixTypeExp(BTreeNode * bTree)
{
    if (bTree == NULL)
        return;

    if (bTree->left != NULL || bTree->right != NULL)
        printf(" ( ");

    showInfixTypeExp(bTree->left);
    showNodeData(bTree->data);
    showInfixTypeExp(bTree->right);

    if (bTree->right != NULL || bTree->right != NULL)
        printf(" ) ");
}

void showPostfixTypeExp(BTreeNode * bTree)
{
    postOrderTraverse(bTree, showNodeData);
}

