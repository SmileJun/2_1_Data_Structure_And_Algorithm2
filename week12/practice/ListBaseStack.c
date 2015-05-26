#include "ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

void stackInit(Stack * stack)
{
    stack->head = NULL;
}

int stackIsEmpty(Stack * stack)
{
    if (stack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void stackPush(Stack * stack, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = stack->head;

    stack->head = newNode;
}

Data stackPop(Stack * stack)
{
    Data rData;
    Node * rNode;

    if (stackIsEmpty(stack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rData = stack->head->data;
    rNode = stack->head;

    stack->head = stack->head->next;
    free(rNode);

    return rData;
}

Data stackPeek(Stack * stack)
{
    if (stackIsEmpty(stack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return stack->head->data;
}
