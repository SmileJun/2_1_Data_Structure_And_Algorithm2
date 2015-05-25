#include <stdio.h>

void printChildren(int *treeArr, int nodeNum, int givenNodeId)
{
    if (treeArr == NULL || nodeNum < 1 || givenNodeId < 1 || givenNodeId > nodeNum) return;
    
    if (givenNodeId * 2 <= nodeNum)
        printf("%d ", treeArr[givenNodeId * 2]);

    if (givenNodeId * 2 + 1 <= nodeNum)
        printf("%d", treeArr[givenNodeId * 2 + 1]);
}

int main(void)
{
    return 0;
}
