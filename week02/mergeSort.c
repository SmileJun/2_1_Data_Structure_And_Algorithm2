/*
 * HW#1.C2
 * mergeSort.c
 * merge 함수 구현
 * 
 * Created by Son Myeong Jun on 2015. 03. 10..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

int getMaxValue(int *arr, int begin, int last);
void merge(int *arr, int begin, int last);
void mergeSort(int *arr, int begin, int last);
int isSorted(int *arr, int length);
int isValidateCase(int *arr, int length);
void validateAllCases();
void printArr(int *arr, int length);

int main(void)
{
    validateAllCases();
    return 0;
}

int getMaxValue(int *arr, int begin, int last)
{
    if (arr == NULL)
        return -1;

    int i;
    int max = arr[begin];
    for (i = begin; i <= last; ++i) 
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

void merge(int *arr, int begin, int last)
{
    if (arr == NULL)
        return;

    int i, j, k;
    int middle = begin + (last - begin) / 2;
    int numOfLeftElement = middle - begin + 1;
    int numOfRightElement = last - middle;

    int *leftArr = (int *)malloc((numOfLeftElement + 1) * sizeof(int));
    int *rightArr = (int *)malloc((numOfRightElement + 1) * sizeof(int));
    int dummyValue = getMaxValue(arr, begin, last) + 1;

    for (i = 0; i < numOfLeftElement; ++i)
        leftArr[i] = arr[begin + i];
    for (i = 0; i < numOfRightElement; ++i)
        rightArr[i] = arr[numOfLeftElement + begin + i];
    leftArr[numOfLeftElement] = dummyValue;
    rightArr[numOfRightElement] = dummyValue;

    i = 0; j = 0; k = begin;
    while (k <= last)
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    free(leftArr);
    free(rightArr);
}

void mergeSort(int *arr, int begin, int last)
{
    if (arr == NULL)
        return;

    if (last <= begin)
        return;

    int middle = begin + (last - begin) / 2;
    mergeSort(arr, begin, middle);
    mergeSort(arr, middle + 1, last);
    merge(arr, begin, last);
}


int isSorted(int *arr, int length)
{
    if (arr == NULL)
        return -1;

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

int isValidateCase(int *arr, int length)
{
    if (arr == NULL)
        return FALSE;

    mergeSort(arr, 0, length - 1);
    
    printf("sorted array : ");
    printArr(arr, length);

    if (isSorted(arr, length))
        return TRUE;
    else
        return FALSE;
}

void validateAllCases(void)
{
    // check element num case
    int numCaseArr1[0] = {};
    int numCaseArr2[1] = {1};
    int numCaseArr3[2] = {1,2};
    int numCaseArr4[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    // check special case
    int specialCaseArr1[10] = {1,2,3,4,5,6,7,8,9,10}; // by ascendant order 
    int specialCaseArr2[10] = {10,9,8,7,6,5,4,3,2,1}; // by descendant order
    int specialCaseArr3[10] = {15,1,6,3,7,8,3,2,3,4}; // random number
    int specialCaseArr4[10] = {4,5,6,6,5,4,4,7,1,10}; // have same value
   
    assert(isValidateCase(numCaseArr1, 0));
    assert(isValidateCase(numCaseArr2, 1));
    assert(isValidateCase(numCaseArr3, 2));
    assert(isValidateCase(numCaseArr4, 20));

    assert(isValidateCase(specialCaseArr1, 10));
    assert(isValidateCase(specialCaseArr2, 10));
    assert(isValidateCase(specialCaseArr3, 10));
    assert(isValidateCase(specialCaseArr4, 10));
}

void printArr(int *arr, int length)
{
    int i;
    for (i = 0; i < length; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
