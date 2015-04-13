/*
 * HW#2.C6 
 * radixSort.c
 * 
 * Created by Son Myeong Jun on 2015. 04. 11..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <math.h>

#define randomize() srand((unsigned)time(NULL))
#define SIZE 7 
#define DIGIT_NUM 3
#define MAX_VALUE (int)(pow(10, DIGIT_NUM));
#define NUMBER_SYSTEM 10 // 진법

int * makeRandomArray(int size);
void stableSort(int *arr, int size, int digitPos);
void radixSort(int *arr, int size, int digitNum);
void testRadixSort(void);
void printArray(int *arr, int size);

int main(void)
{
    randomize();
    testRadixSort();
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

void stableSort(int *arr, int size, int digitPos)
{
    if (arr == NULL || size < 0 || digitPos < 1)
    {
        fprintf(stderr, "%s\n", "countingSort() invalid arguments");
        return;
    }

    int i = 0;
    int tenthDigitValue = 0;
    int targetValue = 0;
    int numOfLessValueSize = NUMBER_SYSTEM;

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

    // init numOfLessValue, count each value
    for (i = 0; i < size; ++i)
    {
        tenthDigitValue = (int)(arr[i] / pow(NUMBER_SYSTEM, digitPos - 1));
        targetValue = tenthDigitValue % NUMBER_SYSTEM;
        numOfLessValue[targetValue]++;
    }

    // init numOfLessValue, accumulate values
    for (i = 0; i < NUMBER_SYSTEM - 1; ++i)
        numOfLessValue[i + 1] += numOfLessValue[i];

    // use numOfLessValue, to countingSort
    for (i = size - 1; i >= 0; --i)
    {
        tenthDigitValue = (int)(arr[i] / pow(NUMBER_SYSTEM, digitPos - 1));
        targetValue = tenthDigitValue % NUMBER_SYSTEM;
        int inputIndex = numOfLessValue[targetValue]--;
        resultArray[--inputIndex] = arr[i];
    }

    for (i = 0; i < size; ++i)
        arr[i] = resultArray[i];

    free(numOfLessValue);
    free(resultArray);
}

void radixSort(int *arr, int size, int digitNum)
{
    if (arr == NULL || size < 0 || digitNum < 1)
    {
        fprintf(stderr, "%s\n", "radixSort() invalid arguments");
        return;
    }

    int digitPos = 0;
    for (digitPos = 1; digitPos <= digitNum; ++digitPos)
        stableSort(arr, size, digitPos);
}

void testRadixSort(void)
{
    // init
    int * randomArray = makeRandomArray(SIZE); 
    int ascendantArray[SIZE] = {111, 112, 123, 125, 172, 639, 981};
    int descendantArray[SIZE] = {981, 639, 172, 125, 123, 112, 111};
    int sameValueArray[SIZE] = {111, 111, 111, 111, 111, 111, 111};

    // test
    printf("random case\n");
    printf("before : "); printArray(randomArray, SIZE);
    radixSort(randomArray, SIZE, DIGIT_NUM);
    printf("after : "); printArray(randomArray, SIZE);
 
    printf("\nascendant order\n");
    printf("before : "); printArray(ascendantArray, SIZE);
    radixSort(ascendantArray, SIZE, DIGIT_NUM);
    printf("after : "); printArray(ascendantArray, SIZE);

    printf("\ndescendant order\n");
    printf("before : "); printArray(descendantArray, SIZE);
    radixSort(descendantArray, SIZE, DIGIT_NUM);
    printf("after : "); printArray(descendantArray, SIZE);
  
    printf("\nsame value\n");
    printf("before : "); printArray(sameValueArray, SIZE);
    radixSort(sameValueArray, SIZE, DIGIT_NUM);
    printf("after : "); printArray(sameValueArray, SIZE);

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
