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

int getMaxValue(int *arr, int begin, int last);
void merge(int *arr, int *bufferArr, int firstBegin, int firstLast, int secondLast);
void mergeSort(int *arr, int *bufferArr, int begin, int last);
void isSorted(int *arr, int length);
int isValidateCase(int *arr, int *bufferArr, int length);
void validateAllCases();

int main(void)
{
    validateAllCases();
    return 0;
}

int getMaxValue(int *arr, int begin, int last)
{
    int i = 0;
    int max = arr[i];
    for (i = begin; i < last - 1; ++i) 
    {
        if (arr[i] < arr[i + 1])
            max = arr[i + 1];
    }
    return max;
}

void merge(int *arr, int *bufferArr, int begin, int last)
{
    int i, j, k;
    int middle = begin + (last - begin) / 2;
    int numOfLeftElement = middle - begin + 1;
    int numOfRigitElement = last - middle;

    int leftArr[numOfLeftElement + 1] = {0};
    int rigintArr[numOfRightElement + 1] = {0};
    int dummyValue = getMaxValue(arr, begin, last) + 1;

    for (i = 0; i <= numOfLeftElement; ++i)
        leftArr[i] = arr[i];
    for (j = 0; j <= numOfRightElement; ++j)
        rightArr[j] = arr[numOfLeftElement + j];
    leftArr[numOfLeftElement] = dummyValue;
    rigitArr[numOfRightElement] = dummyValue;

    i = 0; j = 0; k = begin;
    while (k < last)
    {
        if (leftArr[i] <= rightArr[j])
            bufferArr[k++] = leftArr[i++];
        else
            bufferArr[k++] = rightArr[j++];
    }
}

void mergeSort(int *arr, int *bufferArr, int begin, int last)
{
    
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
    // sort
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
   
    int bufferArr[20] = {0};

    assere(isValidateCase(numCaseArr1, bufferArr, 0));
    assert(isValidateCase(numCaseArr2, bufferArr, 1));
    assert(isValidateCase(numCaseArr3, bufferArr, 2));
    assert(isValidateCase(numCaseArr4, bufferArr, 20));

    assert(isValidateCase(specialCaseArr1, bufferArr, 10));
    assert(isValidateCase(specialCaseArr2, bufferArr, 10));
    assert(isValidateCase(specialCaseArr3, bufferArr, 10));
    assert(isValidateCase(specialCaseArr4, bufferArr, 10));
}
