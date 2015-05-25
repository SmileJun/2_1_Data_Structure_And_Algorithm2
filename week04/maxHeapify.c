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
#define HEAP_SIZE 11 
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
    printf("maxHeapify 호출 전 : ");
    printHeap(heap);
    if (isMaxHeap(heap, 1))
        printf("maxHeap이 맞습니다.\n");
    else
        printf("maxHeap이 아닙니다.\n");

    maxHeapify(heap, 1);

    printf("maxHeapify 호출 후 : ");
    printHeap(heap);
    if (isMaxHeap(heap, 1))
        printf("maxHeap이 맞습니다.\n");
    else
        printf("maxHeap이 아닙니다.\n");

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

    int leftChildPos = 2 * pos;
    int rightChildPos = 2 * pos + 1;
    int leftChildValue = heap->element[leftChildPos];
    int rightChildValue = heap->element[rightChildPos];
    int maxPos = 0;
    
    if (heap->size >= leftChildPos && leftChildValue > heap->element[pos])
        maxPos = leftChildPos;
    else
        maxPos = pos;
        
    if (heap->size >= rightChildPos && rightChildValue > heap->element[maxPos])
        maxPos = rightChildPos;

    if (maxPos != pos)
    {
        int temp = heap->element[pos];
        heap->element[pos] = heap->element[maxPos];
        heap->element[maxPos] = temp;
        
        maxHeapify(heap, maxPos);
    }
}

heap_t * makeSampleHeap(void)
{
    heap_t * heap = (heap_t *)malloc(sizeof(heap_t) * 1); 
    heap->size = HEAP_SIZE; 
    heap->element = (int *)malloc(sizeof(int) * HEAP_ELEMENT_SIZE); 
    
    if (heap == NULL || heap->element == NULL)
    {
        perror("malloc() error");
        return NULL;
    }

    // new root
    heap->element[1] = 4; 

    // subtree들은 maxHeap이다.
    heap->element[2] = 16;
    heap->element[3] = 10;
    heap->element[4] = 14;
    heap->element[5] = 7;
    heap->element[6] = 9;
    heap->element[7] = 3;
    heap->element[8] = 2;
    heap->element[9] = 8;
    heap->element[10] = 1;
    heap->element[11] = 2;
    
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

    // heap->size == leftChildPos : heap의 child가 왼쪽에만 있을 경우
    // heap->size >= rightChildPos : heap의 child가 양쪽에 다 있을 경우
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

    int i = 0;
    for (i = 1; i <= heap->size; ++i)
    {
        printf("%d, ", heap->element[i]); 
    }
    printf("\n");
}
