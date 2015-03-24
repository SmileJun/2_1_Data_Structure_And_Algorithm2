/*
 * HW#2.C1
 * maxHeapify.c
 * heapify  관련 함수 구현  
 * 
 * Created by Son Myeong Jun on 2015. 03. 24..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define HEAP_SIZE 10 
#define HEAP_ELEMENT_SIZE (HEAP_SIZE + 1) // +1 for dummy node element[0] 
#define randomize() srand((unsigned)time(NULL))
#define MAX_VALUE 20

typedef struct heap
{
    int size; 
    int *element;
} heap_t;

void maxHeapify(heap_t *heap, int pos);
void testHeapify(void);
heap_t * makeSampleHeap(void);
int isMaxHeap(heap_t *heap, int pos);
void printHeap(heap_t *heap);

int main(void)
{
    testHeapify();
    return 0;
}


void testHeapify(void)
{
    // init
    randomize();
    heap_t * heap = makeSampleHeap();
   
    // test
    printf("maxHeapify() 호출 전 : ");
    printHeap(heap);
    printf("maxHeapify() 호출 후 : ");
    maxHeapify(heap, 1);
    printHeap(heap);

    // termination
    free(heap->element);
    free(heap);
}

void maxHeapify(heap_t *heap, int pos)
{
    if (heap == NULL || heap->size <= 0 || heap->element == NULL || pos < 1)
    {
        perror("maxHeapify() invalid arguments");
        return;
    }

    int posValue = heap->element[pos];
    int leftValue = heap->element[pos * 2];
    int rightValue = heap->element[pos * 2 + 1];

    
}

heap_t * makeSampleHeap(void)
{
    heap_t * heap = (heap_t *)malloc(sizeof(heap_t) * 1); 
    heap->size = HEAP_SIZE;
    heap->element = (int *)malloc(sizeof(int) * HEAP_ELEMENT_SIZE); 
    
    int i;
    for (i = 1; i < HEAP_ELEMENT_SIZE; ++i)
        heap->element[i] = rand() % MAX_VALUE; 

    return heap;
}

int isMaxHeap(heap_t *heap, int pos)
{
    if (heap == NULL || heap->size <= 0 || heap->element == NULL)
    {
        perror("isMaxHeap() invalid arguments");
        return -1;
    }
    
    int leftChildPos = 2 * pos;
    int rightChildPos = 2 * pos + 1;

    // current pos check
    if ((heap->size == leftChildPos) && (heap->element[leftChildPos] > heap->element[pos]))
        return FALSE;
    if ((heap->size >= rightChildPos) && (heap->element[leftChildPos] > heap->element[pos] || heap->element[rightChildPos] > heap->element[pos]))
        return FALSE;

    // recursive check
    if ((heap->size == leftChildPos) && (isMaxHeap(heap, leftChildPos) == FALSE))
        return FALSE;
    if ((heap->size >= rightChildPos) && (isMaxHeap(heap, leftChildPos) == FALSE || isMaxHeap(heap, rightChildPos) == FALSE))
        return FALSE;
   
    return TRUE;
}

void printHeap(heap_t *heap)
{
    if (heap == NULL || heap->size <= 0 || heap->element == NULL)
    {
        perror("printHeap() invalid arguments");
        return;
    }

    int i;
    for (i = 1; i <= heap->size; ++i)
    {
        printf("%d, ", heap->element[i]); 
    }
    printf("\n");
}
