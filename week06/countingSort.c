/*
 * HW#2.C5  
 * countingSort.c
 * 
 * Created by Son Myeong Jun on 2015. 04. 11..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define SIZE 8 

int getMaxValue(int *arr, int size);
void countingSort(int *arr, int size, int maxValue);
void testCountingSort();
void printArray(int *arr, int size);

int main(void)
{
    testCountingSort();
    return 0;
}

int getMaxValue(int *arr, int size)
{
    if (arr == NULL || size < 0)
    {
        fprintf(stderr, "%s\n", "getMaxValue() invalid arguments");
        return -1;
    }
    
    int max = arr[0];
    int i = 0;
   
    for (i = 1; i < size; ++i)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}

void countingSort(int *arr, int size, int maxValue)
{
    if (arr == NULL || size < 0)
    {
        fprintf(stderr, "%s\n", "countingSort() invalid arguments");
        return;
    }

    int numOfLessValueSize = maxValue + 1;

    int * numOfLessValue = (int *)calloc(numOfLessValueSize, sizeof *numOfLessValue);
    if (numOfLessValue == NULL)
    {
        fprintf(stderr, "calloc error : %s\n", strerror(errno));
        return;
    }

    int * resultArray = (int *)calloc(size, sizeof *resultArray);
    if (resultArray == NULL)
    {
        fprintf(stderr, "calloc error : %s\n", strerror(errno));
        return;
    }

    int i = 0;
    // init numOfLessValue, count each value
    for (i = 0; i < size; ++i)
        numOfLessValue[arr[i]]++;

    // init numOfLessValue, accumulate values
    for (i = 0; i < maxValue; ++i)
        numOfLessValue[i + 1] += numOfLessValue[i];

    // use numOfLessValue to countingSort
    for (i = size - 1; i >= 0; --i)
    {
        int inputIndex = numOfLessValue[arr[i]]--;
        resultArray[--inputIndex] = arr[i];
    }

    for (i = 0; i < size; ++i)
        arr[i] = resultArray[i];

    free(numOfLessValue);
    free(resultArray);
}

void testCountingSort()
{
    int randomArray[SIZE] = {1,8,3,4,6,8,2,16};
    int ascendantArray[SIZE] = {1,2,3,4,5,6,7,8};
    int descendantArray[SIZE] = {8,7,6,5,4,3,2,1};
    int sameValueArray[SIZE] = {1,1,1,1,1,1,1,1};
    int maxValue = 0;

    printf("random case\n");
    printf("before : "); printArray(randomArray, SIZE);
    maxValue = getMaxValue(randomArray, SIZE);
    countingSort(randomArray, SIZE, maxValue);
    printf("after : "); printArray(randomArray, SIZE);
 
    printf("\nascendant order\n");
    printf("before : "); printArray(ascendantArray, SIZE);
    maxValue = getMaxValue(ascendantArray, SIZE);
    countingSort(ascendantArray, SIZE, maxValue);
    printf("after : "); printArray(ascendantArray, SIZE);

    printf("\ndescendant order\n");
    printf("before : "); printArray(descendantArray, SIZE);
    maxValue = getMaxValue(descendantArray, SIZE);
    countingSort(descendantArray, SIZE, maxValue);
    printf("after : "); printArray(descendantArray, SIZE);
  
    printf("\nsame value\n");
    printf("before : "); printArray(sameValueArray, SIZE);
    maxValue = getMaxValue(sameValueArray, SIZE);
    countingSort(sameValueArray, SIZE, maxValue);
    printf("after : "); printArray(sameValueArray, SIZE);
}

void printArray(int *arr, int size)
{
    if (arr == NULL || size < 0)
    {
        fprintf(stderr, "%s\n", "printArray() invalid arguments");
        return;
    }

    int i = 0;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
