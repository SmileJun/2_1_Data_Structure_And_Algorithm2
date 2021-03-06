/*
 * insertSort.c
 * Insertion Sort 함수 구현
 * 
 * Created by Son Myeong Jun on 2015. 03. 10..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

void insertionSort(int *arr, int length); 
int isSorted(int *arr, int length);
int isValidateCase(int *arr, int length);
void validateAllCases(void);

int main(void)
{
    validateAllCases();
    return 0;
}

void insertionSort(int *arr, int length)
{
    if (arr == NULL || length == 0)
        return;

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

int isValidateCase(int *arr, int length)
{
    insertionSort(arr, length);
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
    int specialCaseArr3[10] = {4,5,6,6,5,4,4,7,1,10}; // have same value
    int specialCaseArr4[10] = {15,1,6,3,7,8,3,2,3,4}; // random number

    assert(isValidateCase(numCaseArr1, 0));
    assert(isValidateCase(numCaseArr2, 1));
    assert(isValidateCase(numCaseArr3, 2));
    assert(isValidateCase(numCaseArr4, 20));

    assert(isValidateCase(specialCaseArr1, 10));
    assert(isValidateCase(specialCaseArr2, 10));
    assert(isValidateCase(specialCaseArr3, 10));
    assert(isValidateCase(specialCaseArr4, 10));
}
