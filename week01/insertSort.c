/*
 * insertSort.c
 * Insertion Sort 함수 구현
 * 
 * Created by Son Myeong Jun on 2015. 03. 05..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

void insertionSort(int *arr, int length); 
int isSorted(int *arr, int length);
int assertTestCase();

int main(void)
{
    int arr[10] = {10,6,3,4,6,8,9,5,3,5};

    insertionSort(arr, 10);
    if(isSorted(arr, 10))
    {
        printf("is sorted\n");
    }
    return 0;
}

void insertionSort(int *arr, int length)
{
    int lastIndex = length - 1;
    int startIndex = 1;
    
    int index;
    for (index = startIndex; index <= lastIndex; index++)
    {
        int target = arr[index];
        int subIndex = index - 1;
        while(target < arr[subIndex] && subIndex >= 0)
        {
            arr[subIndex + 1] = arr[subIndex];
            subIndex--;
        }
        arr[subIndex + 1] = target;
    }
}

int isSorted(int *arr, int length)
{
    int i;
    for (i = 0; i < length - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
            continue;
        else 
            return FALSE;
    }
    return TRUE;
}

