#ifndef __LISTBASE_STACK_H__
#define __LISTBASE_STACK_H__

#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0

typedef BTreeNode * Data;

typedef struct node
{
    Data data;
    struct node * next;
} Node;

typedef struct listStack
{
    Node * head;
} ListStack;

typedef ListStack Stack;

void stackInit(Stack * stack);
int stackIsEmpty(Stack * stack);

void stackPush(Stack * stack, Data data);
Data stackPop(Stack * stack);
Data stackPeek(Stack * stack);

#endif

