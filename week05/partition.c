/*
 * HW#2.C3
 * partition.c
 * 
 * Created by Son Myeong Jun on 2015. 03. 31..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define randomize() srand((unsigned)time(NULL))
#define MAX_ARRAY_LENGTH 32
#define MAX_VALUE 100

void exchangeElement(int *arr, int posA, int posB);
int partition(int *arr, int start, int end);
void testPartition(int *arr, int partitionedIndex, int length);
void testAllCases(void);
void makeRandomArray(int *arr, int length);
void printAllArrays(int **arr);
void printArray(int *arr, int length);

int main(void)
{
    testAllCases();
    return 0;
}

void exchangeElement(int *arr, int posA, int posB)
{
    if (arr == NULL || posA < 0 || posB < 0)
    {
        perror("changeElement() invalid arguments");
        return;
    }

    if (posA == posB)
        return;

    int temp = arr[posA];
    arr[posA] = arr[posB];
    arr[posB] = temp;
}

/*
 * return 값 : 정상 동작할 경우 pivot의 위치, 비정상 동작할 경우 -1
 */
int partition(int *arr, int start, int end)
{
    if (arr == NULL || start < 0 || end < 0 || start > end)
    {
        perror("partition() invalid arguments");
        return -1;
    }
    
    int pivotValue = arr[end];
    int endOfLowBlock = start - 1;
    int posToBeChecked = 0;

    for (posToBeChecked = start; posToBeChecked < end; ++posToBeChecked)
    {
        if (arr[posToBeChecked] <= pivotValue)
        {
            ++endOfLowBlock;
            exchangeElement(arr, endOfLowBlock, posToBeChecked);
        }
    }
    exchangeElement(arr, endOfLowBlock + 1, end);

    return endOfLowBlock + 1;
}

void testPartition(int *arr, int partitionedIndex, int length)
{
    if (arr == NULL || partitionedIndex < 0 || partitionedIndex >= length || length < 1)
    {  
        perror("testPartition() invalid arguments");
        return;
    }
   
    int isPartitioned = 0;
    int pivotValue = arr[partitionedIndex];

    int i = 0;
    for (i = 0; i < partitionedIndex; ++i)
    {
        if (arr[i] > pivotValue)
            isPartitioned = FALSE;
    }

    for (i = partitionedIndex + 1; i < length; ++i)
    {
        if (arr[i] < pivotValue)
            isPartitioned = FALSE;
    }
    isPartitioned = TRUE;

    if (isPartitioned)
        printf("%d element test success\n", length);
    else
        printf("%d element test falied\n", length);
}

void testAllCases(void)
{
    randomize();

    // init
    int ** arr = (int **)malloc(sizeof(int *) * MAX_ARRAY_LENGTH);
    int ascendArray[10] = {1,2,3,4,5,6,7,8,9,10};
    int descendArray[10] = {10,9,8,7,6,5,4,3,2,1};
    int i = 0;
    int j = 0;
    int arrayLength = 0;
    int partitionedIndex = 0;

    for (i = 0; i < MAX_ARRAY_LENGTH; ++i)
    {
        arrayLength = i + 1;
        arr[i] = (int *)malloc(sizeof(int) * arrayLength);
        makeRandomArray(arr[i], arrayLength);
    }

    // test
    printf("\n");
    printf("==========================\n");
    printf("1~%d element test\n", MAX_ARRAY_LENGTH);
    printf("==========================\n");
    for (i = 0; i < MAX_ARRAY_LENGTH; ++i)
    {
        arrayLength = i + 1;
        partitionedIndex = partition(arr[i], 0, i);
        testPartition(arr[i], partitionedIndex, arrayLength);
    }
    
    printf("\n");
    printf("==========================\n");
    printf("ascendArray test\n");
    printf("==========================\n");
    partitionedIndex = partition(ascendArray, 0, 9);
    testPartition(ascendArray, partitionedIndex, 10);

    printf("\n");
    printf("==========================\n");
    printf("descendArray test\n");
    printf("==========================\n");
    partitionedIndex = partition(descendArray, 0, 9);
    testPartition(descendArray, partitionedIndex, 10);
    printf("\n");

    // termination
    for (i = 0; i < MAX_ARRAY_LENGTH; ++i)
        free(arr[i]);
    free(arr);
}

void makeRandomArray(int *arr, int length)
{
    if (arr == NULL || length < 1)
    {
        perror("makeRandomArray() invalid arguments");
        return;
    }

    int i = 0;
    for (i = 0; i < length; ++i)
        arr[i] = rand() % MAX_VALUE; 
}

void printAllArrays(int **arr)
{
    if (arr == NULL)
    {
        perror("printAllArray() invalid arguments");
        return;
    }

    int i = 0;
    for (i = 0; i < MAX_ARRAY_LENGTH; ++i)
    {
        printf("%2d 번째 array : ", i + 1);
        printArray(arr[i], i + 1);
        printf("\n");
    }
}

void printArray(int *arr, int length)
{
    if (arr == NULL || length < 1)
    {
        perror("printArray() invalid arguments");
        return;
    }

    int i = 0;
    for (i = 0; i < length; ++i)
        printf("%3d", arr[i]);
}

