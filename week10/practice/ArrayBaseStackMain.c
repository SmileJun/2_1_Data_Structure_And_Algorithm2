#include "ArrayBaseStack.h"
#include <stdio.h>

int main(void)
{
    Stack stack;
    stackInit(&stack);

    stackPush(&stack, 1);
    stackPush(&stack, 2);
    stackPush(&stack, 3);
    stackPush(&stack, 4);
    stackPush(&stack, 5);

    while (!stackIsEmpty(&stack))
        printf("%d ", stackPop(&stack));

    return 0;
}
