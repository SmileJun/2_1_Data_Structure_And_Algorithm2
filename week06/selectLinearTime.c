/*
 * HW#2.C7 
 * selectLinearTime.c
 * 
 * Created by Son Myeong Jun on 2015. 04. 12..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define randomize() srand((unsigned)time(NULL))
#define SIZE 10
#define MAX_VALUE 100

int * makeRandomArray(int size);
int getRandomIndex(int start, int end);
void exchangeElement(int *arr, int posA, int posB); 
int randomizedPartition(int *arr, int start, int end);
int partition(int *arr, int start, int end);

void printArray(int *arr, int size);
int randomizedSelect(int *arr, int fisrt, int last, int kth);
void testRandomizedSelect(void);

int main(void)
{
    randomize();
    testRandomizedSelect();
    return 0;
}

int * makeRandomArray(int size)
{
    if (size < 0)
        return NULL;

    int * arr = (int *)calloc(size, sizeof *arr);
    if (arr == NULL)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return NULL;
    }

    int i = 0;
    for (i = 0; i < size; ++i)
        arr[i] = rand() % MAX_VALUE;

    return arr;
}

int getRandomIndex(int start, int end)
{
    if (start < 0 || end < 0 || start > end)
    {
        fprintf(stderr, "%s\n", "getRandomIndex() invalid arguments");
        return -1;
    }

    int randomIndex = 0;
    do {
        randomIndex = rand() % (end + 1);
    } while (randomIndex < start || randomIndex > end);

    return randomIndex;
}

void exchangeElement(int *arr, int posA, int posB)
{
    if (arr == NULL || posA < 0 || posB < 0)
    {
        fprintf(stderr, "%s\n", "changeElement() invalid arguments");
        return;
    }

    if (posA == posB)
        return;

    int temp = arr[posA];
    arr[posA] = arr[posB];
    arr[posB] = temp;
}

int randomizedPartition(int *arr, int start, int end)
{
    if (arr == NULL || start < 0 || end < 0 || start > end)
    {
        fprintf(stderr, "%s\n", "randomizedPartition() invalid arguments");
        return -1;
    }

    int randomIndex = getRandomIndex(start, end);
    exchangeElement(arr, randomIndex, end);
    return partition(arr, start, end);
}

int partition(int *arr, int start, int end)
{
    if (arr == NULL || start < 0 || end < 0 || start > end)
    {
        fprintf(stderr, "%s\n", "partition() invalid arguments");
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

/*
 * ranomizedSelect
 * return value
 * - when error, it returns -1
 * - when normal, it returns array's kth large value 
 */
int randomizedSelect(int *arr, int first, int last, int kth)
{
    if (arr == NULL || first < 0 || last < 0 || kth < 1) 
    {
        fprintf(stderr, "%s\n", "randomizedSelect() invalid arguments");
        return -1;
    }

    if (first > last)
    {
        printf("cannot find kth value\n");
        return -1;
    }

    int pivotIndex = randomizedPartition(arr, first, last);
    int pivotInOrder = pivotIndex + 1;

    if (kth == pivotInOrder)
        return arr[pivotIndex]; 
    else if (kth < pivotInOrder)
        return randomizedSelect(arr, first, pivotIndex - 1, kth);
    else
        return randomizedSelect(arr, pivotIndex + 1, last, kth);
}

void testRandomizedSelect(void)
{
    // init
    int * randomArray = makeRandomArray(SIZE);
    int ascendantArray[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int descendantArray[SIZE] = {10,9,8,7,6,5,4,3,2,1};
    int sameValueArray[SIZE] = {1,1,1,1,1,1,1,1,1,1};
    int kthValue = 0;
    int kth = 5;

    // test 
    printf("random case\n");
    printArray(randomArray, SIZE);
    kthValue = randomizedSelect(randomArray, 0, SIZE - 1, kth); 
    printf("%d 번째로 큰 원소값 : %d\n", kth, kthValue);

    printf("\nascendant order\n");
    printArray(ascendantArray, SIZE);
    kthValue = randomizedSelect(ascendantArray, 0, SIZE - 1, kth); 
    printf("%d 번째로 큰 원소값 : %d\n", kth, kthValue);

    printf("\ndescendant order\n");
    printArray(descendantArray, SIZE);
    kthValue = randomizedSelect(descendantArray, 0, SIZE - 1, kth); 
    printf("%d 번째로 큰 원소값 : %d\n", kth, kthValue);

    printf("\nsame value\n");
    printArray(sameValueArray, SIZE);
    kthValue = randomizedSelect(sameValueArray, 0, SIZE - 1, kth); 
    printf("%d 번째로 큰 원소값 : %d\n", kth, kthValue);

    // termination
    free(randomArray);
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
