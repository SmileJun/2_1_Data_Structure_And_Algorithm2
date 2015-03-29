/*
 * HW#2.C2
 * maxHeap.c
 * heap 관련 함수 구현  
 * buildMaxHeap() - 실습 주제 3
 * heapSort() - 실습 주제 4
 * extractMax() - 실습 주제 5
 * maxHeapInsert() - 실습 주제 6
 * 
 * Created by Son Myeong Jun on 2015. 03. 26..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define TEST_HEAP_SIZE 7 // test함수에 사용되는 값.  heap 원소 개수를 변경하며 test 가능  
#define randomize() srand((unsigned)time(NULL))
#define MAX_VALUE 100

typedef struct heap
{
    int size; 
    int length;
    int *element;
} heap_t;

heap_t * makeRandomHeap(int heapSize);
void maxHeapify(heap_t *heap, int pos);
void buildMaxHeap(heap_t *heap);
void testBuildMaxHeap(void);
void heapSort(heap_t *heap);
void testHeapSort(void);
int extractMax(heap_t *heap, int *maxValue);
void testExtractMax(void);
void heapChangeKey(heap_t *heap, int i, int key);
void maxHeapInsert(heap_t *heap, int key);
void testMaxHeapInsert(void);

int isSortedHeap(heap_t *heap);
int isMaxHeap(heap_t *heap, int pos);
void printHeapInfo(heap_t *heap);

int main(void)
{
    printf("---------------------------------------------------------\n");
    printf("testBuildMaxHeap()\n");
    printf("---------------------------------------------------------\n");
    testBuildMaxHeap();

    printf("---------------------------------------------------------\n");
    printf("testHeapSort()\n");
    printf("---------------------------------------------------------\n");
    testHeapSort();

    printf("---------------------------------------------------------\n");
    printf("testExtractMax()\n");
    printf("---------------------------------------------------------\n");
    testExtractMax();

    printf("---------------------------------------------------------\n");
    printf("testMaxHeapInsert()\n");
    printf("---------------------------------------------------------\n");
    testMaxHeapInsert();
    return 0;
}

heap_t * makeRandomHeap(int heapSize)
{
    if (heapSize < 1)
    {
        perror("makeRandomHeap() invalid arguments");
        heap_t * nullStruct;
        return nullStruct;
    }

    int i;
    int heapElementSize = heapSize + 1;
    heap_t * heap = (heap_t *)malloc(sizeof(heap_t) * 1); 
    heap->size = heapSize; 
    heap->length = heapSize;
    heap->element = (int *)malloc(sizeof(int) * heapElementSize); 
    
    if (heap == NULL || heap->element == NULL)
    {
        perror("malloc() error");
        return NULL;
    }
    
    for (i = 1; i < heapElementSize; ++i)
        heap->element[i] = rand() % MAX_VALUE; 
    
    return heap;
}

void maxHeapify(heap_t *heap, int pos)
{
    if (heap == NULL || heap->length <= 0 || heap->element == NULL || pos < 1)
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

void buildMaxHeap(heap_t *heap)
{
    if (heap == NULL || heap->length <= 0 || heap->element == NULL)
    {
        perror("buildMaxHeap() invalid arguments");
        return;
    }

    int i; 
    for (i = heap->size / 2; i >= 1; --i)
        maxHeapify(heap, i);
}

void testBuildMaxHeap(void)
{
    // init
    randomize();
    heap_t * heap = makeRandomHeap(TEST_HEAP_SIZE);

    // test
    printf("buildMaxHeap() 호출 전\n");
    printHeapInfo(heap);

    buildMaxHeap(heap);
    printf("\n");
    printf("buildMaxHeap() 호출 후\n");
    printHeapInfo(heap);
   
    // termination
    free(heap->element);
    free(heap);
}

void heapSort(heap_t *heap)
{
    if (heap == NULL || heap->length <= 0 || heap->element == NULL)
    {
        perror("heapSort() invalid arguments");
        return;
    }
    
    int temp = 0;
    int i = 0;
    for (i = heap->length; i >= 2; --i)
    {
        temp = heap->element[1];
        heap->element[1] = heap->element[i];
        heap->element[i] = temp;
        
        heap->size--;
        maxHeapify(heap, 1);
    }
}

void testHeapSort(void)
{
    // init
    randomize();
    heap_t * heap = makeRandomHeap(TEST_HEAP_SIZE);
    buildMaxHeap(heap);

    // test
    printf("heapSort() 호출 전\n");
    printHeapInfo(heap);

    heapSort(heap);
    printf("\n");
    printf("heapSort() 호출 후\n");
    printHeapInfo(heap);
    if (isSortedHeap(heap))
    {
        printf("sort되었습니다.\n");
        printf("######all elements : ");
        int i = 0;
        for (i = 1; i <= heap->length; ++i)
            printf("%d, ", heap->element[i]);
        printf("\n");
    }
    else
        printf("sort되지 않았습니다.\n");

    // termination
    free(heap->element);
    free(heap);
}


/*
 * maxValue는 heap에서 추출된 max값을 저장하는 곳
 * return 값 : 함수가 정상 동작했을 경우 TRUE를, 그렇지 않으면 FALSE를 리턴한다
 */
int extractMax(heap_t *heap, int *maxValue)
{
    if (heap == NULL || heap->length <= 0 || heap->element == NULL || maxValue == NULL || heap->size < 1)
        return FALSE;

    *maxValue = heap->element[1];
    heap->element[1] = heap->element[heap->size];
    heap->size--;
    maxHeapify(heap, 1);
    
    return TRUE;
}

void testExtractMax(void)
{
    // init
    int i = 0;
    int *maxValue = &i;

    randomize();
    heap_t * heap = makeRandomHeap(TEST_HEAP_SIZE);
    buildMaxHeap(heap);

    // test
    printf("extractMax() 호출 전\n");
    printHeapInfo(heap);

    printf("\n");
    printf("extractMax() 호출 후\n");
    if(extractMax(heap, maxValue))
        printf("추출된 maxvalue : %d\n", *maxValue); 
    printHeapInfo(heap);

    // termination
    free(heap->element);
    free(heap);
}

void heapChangeKey(heap_t *heap, int i, int key)
{
    if (heap == NULL || heap->length <= 0 || heap->element == NULL || i < 1 || i > heap->size)
    {
        perror("heapIncreaseKey() invalid arguments");
        return;
    }
    
    int parentIndex = i / 2;
    int temp = 0;
    heap->element[i] = key;      

    // 값이 줄어들고, leaf Node가 아닌 경우
    if (key < heap->element[i] && i <= (heap->size / 2))
    {
        buildMaxHeap(heap);
        return;
    }

    while (i > 1 && heap->element[parentIndex] < heap->element[i])
    {
        temp = heap->element[parentIndex];
        heap->element[parentIndex] = heap->element[i];
        heap->element[i] = temp;
        i = parentIndex;
        parentIndex = i / 2;
    }
}

void maxHeapInsert(heap_t *heap, int key)
{
    if (heap == NULL || heap->length <= 0 || heap->element == NULL)
    {
        perror("maxHeapInsert() invalid arguments");
        return;
    }

    int i = 0;
    int * newElement = (int *)malloc(sizeof(int) * (heap->size + 1)); 

    for (i = 1; i <= heap->size; ++i)
        newElement[i] = heap->element[i];
    free(heap->element);
    heap->element = newElement;

    if (heap->size == heap->length)
        heap->length++;

    heap->size++;
    heapChangeKey(heap, heap->size, key);
}

void testMaxHeapInsert(void)
{
    // init
    randomize();
    heap_t * heap = makeRandomHeap(TEST_HEAP_SIZE);
    buildMaxHeap(heap);

    // test
    printf("maxHeapInsert() 호출 전\n");
    printHeapInfo(heap);

    printf("\n");
    int key = rand() % MAX_VALUE;
    printf("%d를 추가합니다.\n", key);
    maxHeapInsert(heap, key);

    printf("\n");
    printf("maxHeapInsert() 호출 후\n");
    printHeapInfo(heap);

    // termination
    free(heap->element);
    free(heap);
}

int isSortedHeap(heap_t *heap)
{
    if (heap == NULL || heap->length <= 0 || heap->element == NULL)
    {
        perror("isSortedHeap() invalid arguments");
        return -1;
    }

    int i = 0;
    for (i = 1; i < heap->length; ++i)
    {
        if (heap->element[i] > heap->element[i + 1])
            return FALSE;
    }

    return TRUE;
}

int isMaxHeap(heap_t *heap, int pos)
{
    if (heap == NULL || heap->length <= 0 || heap->element == NULL)
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

void printHeapInfo(heap_t *heap)
{
    if (heap == NULL || heap->length <= 0 || heap->element == NULL)
    {
        perror("printHeap() invalid arguments");
        return;
    }

    if (isMaxHeap(heap, 1))
        printf("MaxHeap입니다.\n");
    else
        printf("MaxHeap이 아닙니다.\n");
    
    printf("heap : ");
    int i = 0;
    for (i = 1; i <= heap->size; ++i)
    {
        printf("%d, ", heap->element[i]); 
    }
    printf("\n");
}
