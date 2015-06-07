#include "ArrayBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

void stackInit(Stack * stack)
{
    stack->topIndex = -1;
}

int stackIsEmpty(Stack * stack)
{
    if (stack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void stackPush(Stack * stack, Data data)
{
    stack->topIndex += 1;
    stack->stackArr[stack->topIndex] = data;
}

Data stackPop(Stack * stack)
{
    int rIndex;

    if (stackIsEmpty(stack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    rIndex = stack->topIndex;
    stack->topIndex -= 1;

    return stack->stackArr[rIndex];
}

Data stackPeek(Stack * stack)
{
    if (stackIsEmpty(stack))
    {
        printf("Stack Memoty Error!");
        exit(-1);
    }
    
    return stack->stackArr[stack->topIndex];
}


