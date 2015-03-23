#include <stdio.h>

int maxSumFromStartPos(int *arr, int size);
int maxSumFromStartPos2(int *arr, int size);

int main(void)
{
    int arr[8] = {1,3,-5,1,2,3,-3,-5};
    int result = maxSumFromStartPos2(arr, 8);

    printf("result : %d\n", result);

    return 0;
}

int maxSumFromStartPos(int *arr, int size)
{
    if (arr == NULL || size <= 0)
        return 0;

    int i;
    int tempSum = 0;
    int currentMaxIndex = -1;

    for (i = 0; i < size; ++i)
    {
        if (tempSum + arr[i] <= 0)
        {
            tempSum += arr[i];
        } else {
            currentMaxIndex = i;
            tempSum = 0;
        }
    }

    return currentMaxIndex;
}

int maxSumFromStartPos2(int *arr, int size)
{
    if (arr == NULL || size <= 0)
        return 0;
    
    int i;
    int maxSum = arr[0];
    int currentSum = arr[0];
    int currentMaxIndex = 0;

    for (i = 1; i < size; ++i)
    {
        currentSum += arr[i];
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            currentMaxIndex = i;
        }
    }

    return currentMaxIndex;
}
