#include <stdio.h>

void showArray(int arr[], int arrSize);
void sort(int arr[], int arrSize);
int findInsertIndex(int arr[], int arrSize);

#define ARR_SIZE 10

int main(void)
{
    int arr[ARR_SIZE] = {1,3,5,7,9,11,13,15,17,8};
    sort(arr, ARR_SIZE);


    return 0;
}

void showArray(int arr[], int arrSize)
{
    if (arr == NULL || arrSize == 0)
        return;

    int i;
    for (i=0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sort(int arr[], int arrSize)
{
    if (arr == NULL || arrSize == 0)
        return;

    int targetValue = arr[arrSize - 1];
    int insertIndex = findInsertIndex(arr, arrSize);

    int i;
    for(i = arrSize; i > insertIndex; i--)
    {
         
    }
}

int findInsertIndex(int arr[], int arrSize)
{
    if (arr == NULL || arrSize == 0)
        return 0; // what is the better way to treat this type of return case? if return -1, then use of this function should be more complex;

    int targetValue = arr[arrSize - 1];
    int insertIndex = 0;
    
    int i;
    for (i=0; i < arrSize; i++)
    {
        if (arr[i] < targetValue)
            continue;

        insertIndex = i;
    }
    return insertIndex;
}

