#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include <stdio.h>

void BSTMakeAndInit(BTreeNode ** root)
{
    *root = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return getData(bst);
}

void BSTInsert(BTreeNode ** root, BSTData data)
{
    BTreeNode * pNode = NULL;
    BTreeNode * cNode = *root;
    BTreeNode * nNode = NULL;

    while (cNode != NULL)
    {
        if (data == getData(cNode))
            return;

        pNode = cNode;

        if (getData(cNode) > data)
            cNode = getLeftSubTree(cNode);
        else
            cNode = getRightSubTree(cNode);
    }

    nNode = makeBTreeNode();
    setData(nNode, data);

    if (pNode != NULL)
    {
        if (data < getData(pNode))
            makeLeftSubTree(pNode, nNode);
        else
            makeRightSubTree(pNode, nNode);
    }
    else
        *root = nNode;
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst;
    BSTData cd;
    
    while (cNode != NULL)
    {
        cd = getData(cNode);

        if (target == cd)
            return cNode;
        else if (target < cd)
            cNode = getLeftSubTree(cNode);
        else
            cNode = getRightSubTree(cNode);
    }

    return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** root, BSTData target)
{
    BTreeNode * virtualRoot = makeBTreeNode();
    BTreeNode * pNode = virtualRoot;
    BTreeNode * cNode = *root;
    BTreeNode * dNode;

    changeRightSubTree(virtualRoot, *root);
    
    while(cNode != NULL && getData(cNode) != target)
    {
        pNode = cNode;

        if (target < getData(cNode))
            cNode = getLeftSubTree(cNode);
        else
            cNode = getRightSubTree(cNode);
    }

    if (cNode == NULL)
        return NULL;
    
    dNode = cNode;

    if (getLeftSubTree(dNode) == NULL && getRightSubTree(dNode) == NULL)
    {
        if (getLeftSubTree(pNode) == dNode)
            removeLeftSubTree(pNode);
        else
            removeRightSubTree(pNode);
    }
    else if (getLeftSubTree(dNode) == NULL || getRightSubTree(dNode) == NULL)
    {
        BTreeNode * dcNode;

        if (getLeftSubTree(dNode) != NULL)
            dcNode = getLeftSubTree(dNode);
        else
            dcNode = getRightSubTree(dNode);

        if (getLeftSubTree(pNode) == dNode)
            changeLeftSubTree(pNode, dcNode);
        else
            changeRightSubTree(pNode, dcNode);
    }
    else
    {
        BTreeNode * mNode = getRightSubTree(dNode);
        BTreeNode * mpNode = dNode;
        int delData;

        while (getLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = getLeftSubTree(mNode);
        }

        delData = getData(dNode);
        setData(dNode, getData(mNode));

        if (getLeftSubTree(mpNode) == mNode)
            changeLeftSubTree(mpNode, getRightSubTree(mNode));
        else
            changeRightSubTree(mpNode, getRightSubTree(mNode));

        dNode = mNode;
        setData(dNode, delData);
    }

    if (getRightSubTree(virtualRoot) != *root)
        *root = getRightSubTree(virtualRoot);

    free(virtualRoot);
    return dNode;
}
