#include "ExpressionTree.h"
#include <stdio.h>

int main(void)
{
    char exp[] = "12+7*";
    BTreeNode * eTree = makeExpTree(exp);

    printf("전위 표기법의 수식: ");
    showPrefixTypeExp(eTree); printf("\n");

    printf("후위 표기법의 수식: ");
    showInfixTypeExp(eTree); printf("\n");

    printf("후위 표기법의 수식: ");
    showPostfixTypeExp(eTree); printf("\n");
}

