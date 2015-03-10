/*
 * mergeProblemCoding.c
 * merge 함수 구현
 * 
 * Created by Son Myeong Jun on 2015. 03. 10..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

int * merge(int *arr1, int size1, int *arr2, int size2);

int main(void)
{
    int i;
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {2,4,6,8,10};

    int *arr = merge(arr1, 5, arr2, 5);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int * merge(int *arr1, int size1, int *arr2, int size2)
{
    int i = 0, j = 0, k = 0;
    
    if (arr1 == NULL && arr2 == NULL)
        return NULL;
    if (arr1 != NULL && arr2 == NULL)
        return arr1;
    if (arr1 == NULL && arr2 != NULL)
        return arr2;

    int *arr = (int*)malloc((size1 + size2) * sizeof(int));
    
    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }

    if (i == size1)
        while (j < size2)
            arr[k++] = arr2[j++];
    if (j == size2)
        while (i < size1)
            arr[k++] = arr1[i++];

    return arr;
}

