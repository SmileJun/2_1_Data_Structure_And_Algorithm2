/*
 * HW#1.C3
 * maximuxSubArray.c
 * Maximum Subarray 함수 구현  
 * O(n^2), O(nlogn) 알고리즘 구현
 * Find_max_crossing_subarray() 함수도 구현
 * 
 * Created by Son Myeong Jun on 2015. 03. 21..
 * Copyright 2015. Son Myeong Jun all rights reserved.
 */

#include <stdio.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0
#define ARRAY_MIN_VALUE -999 // 단순화를 위해 배열의 원소가 가질 수 있는 최소값을 지정해둠.

typedef struct indexAndSum {
    int low;
    int high;
    int sum;
} IndexAndSum;

IndexAndSum maxSumFromStartPos(int *arr, int low, int high);
IndexAndSum findMaxArrayNSquare(int *arr, int low, int high);
IndexAndSum findMaxArrayNLogN(int *arr, int low, int high);
IndexAndSum findMaxCrossingSubArray(int *arr, int low, int mid, int high);
void assertAllCases(void);

int main(void)
{
    int arr[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    IndexAndSum result = findMaxArrayNLogN(arr, 0, 15);
    printf("lowIdx : %d, highIdx : %d 인 배열을 선택하면 최대값 %d을 갖는다\n", result.low, result.high, result.sum);
    
    assertAllCases();
    return 0;
}

IndexAndSum maxSumFromStartPos(int *arr, int low, int high)
{
    if (arr == NULL || low > high)
    {
        perror("findMaxArrayNSquare() invalid arguments");
        IndexAndSum nullStruct;
        return nullStruct;
    }
 
    if (low == high)
    {
        IndexAndSum indexAndSum = {low, low, arr[low]};
        return indexAndSum;
    }

    int i;
    IndexAndSum maxIndexAndSum = {0};
    int maxSum = ARRAY_MIN_VALUE;
    int curSum = 0;
    int maxIndex = low;

    for (i = low; i <= high; ++i)
    {
        curSum += arr[i];
        if (curSum > maxSum)
        {
            maxIndex = i;
            maxSum = curSum;
        }
    }

    maxIndexAndSum.low = low;
    maxIndexAndSum.high = maxIndex;
    maxIndexAndSum.sum = maxSum;
    return maxIndexAndSum;
}

IndexAndSum findMaxArrayNSquare(int *arr, int low, int high)
{
    if (arr == NULL || low > high)
    {
        perror("findMaxArrayNSquare() invalid arguments");
        IndexAndSum nullStruct;
        return nullStruct;
    }

    if (low == high)
    {
        IndexAndSum indexAndSum = {low, low, arr[low]};
        return indexAndSum;
    }

    int i;
    IndexAndSum maxIndexAndSum = {0};
    int maxSum = ARRAY_MIN_VALUE;
    int maxLowIndex = low;
    int maxHighIndex = low;

    for (i = low; i <= high; ++i)
    {
        IndexAndSum curIndexAndSum = maxSumFromStartPos(arr, i, high);
        if (curIndexAndSum.sum > maxSum)
        {
            maxLowIndex = curIndexAndSum.low;
            maxHighIndex = curIndexAndSum.high;
            maxSum = curIndexAndSum.sum;
        }
    }
    
    maxIndexAndSum.low = maxLowIndex;
    maxIndexAndSum.high = maxHighIndex;
    maxIndexAndSum.sum = maxSum;

    return maxIndexAndSum;
}

IndexAndSum findMaxArrayNLogN(int *arr, int low, int high)
{
    if (arr == NULL || low > high)
    {
        perror("findMaxArrayNSquare() invalid arguments");
        IndexAndSum nullStruct;
        return nullStruct;
    }
 
    if (low == high)
    {
        IndexAndSum indexAndSum = {low, low, arr[low]};
        return indexAndSum;
    }

    int mid = low + (high - low) / 2;
    IndexAndSum leftIndexAndSum = findMaxArrayNLogN(arr, low, mid); 
    IndexAndSum rightIndexAndSum = findMaxArrayNLogN(arr, mid + 1, high);
    IndexAndSum crossingIndexAndSum = findMaxCrossingSubArray(arr, low, mid, high);

    if (leftIndexAndSum.sum >= rightIndexAndSum.sum && leftIndexAndSum.sum >= crossingIndexAndSum.sum)
        return leftIndexAndSum;
    else if (rightIndexAndSum.sum >= leftIndexAndSum.sum && rightIndexAndSum.sum >= crossingIndexAndSum.sum)
        return rightIndexAndSum;
    else
        return crossingIndexAndSum;
}

IndexAndSum findMaxCrossingSubArray(int *arr, int low, int mid, int high)
{
    if (arr == NULL || low > mid || mid > high)
    {
        perror("findMaxCrossingSubArray() invalid arguments");
        IndexAndSum nullStruct;
        return nullStruct;
    }
    
    if (low == high)
    {
        IndexAndSum indexAndSum = {low, low, arr[low]};
        return indexAndSum;
    }

    int i;
    int maxLeftIndex = mid;
    int maxRightIndex = mid + 1;
    int maxLeftSum = ARRAY_MIN_VALUE;
    int maxRightSum = ARRAY_MIN_VALUE;
    int leftCurSum = 0;
    int rightCurSum = 0;
    IndexAndSum maxIndexAndSum = {0};

    for (i = mid; i >= low; --i)
    {
        leftCurSum += arr[i];            
        if (leftCurSum > maxLeftSum)
        {
            maxLeftIndex = i;
            maxLeftSum = leftCurSum;
        }
    }

    for (i = mid + 1; i <= high; ++i)
    {
        rightCurSum += arr[i];
        if (rightCurSum > maxRightSum)
        {
            maxRightIndex = i;
            maxRightSum = rightCurSum;
        }
    }
    
    maxIndexAndSum.low = maxLeftIndex;
    maxIndexAndSum.high = maxRightIndex;
    maxIndexAndSum.sum = maxLeftSum + maxRightSum;

    return maxIndexAndSum;
}

void assertAllCases()
{
    // 원소의 값은 변동값을 의미
    int testWhenNoElement[0] = {};
    int testWhenOneElement[1] = {1};
    int testWhenTwoElement[2] = {-1,1};
    int testWhenFourElement[4] = {1,-5,3,4};
    int testWhenTwentyElement[20] = {-20,-19,-18,-17,-16,15,14,13,12,11,10,9,8,7,6,5,-4,-3,-2,-1};    

    IndexAndSum noElementResult = findMaxArrayNSquare(testWhenNoElement, 0, 0);
    IndexAndSum oneElementResult = findMaxArrayNSquare(testWhenOneElement, 0, 0);
    IndexAndSum twoElementResult = findMaxArrayNSquare(testWhenTwoElement, 0, 1);
    IndexAndSum fourElementResult = findMaxArrayNSquare(testWhenFourElement, 0, 3);
    IndexAndSum twentyElementResult = findMaxArrayNSquare(testWhenTwentyElement, 0, 19);
    
    IndexAndSum noElementResult2 = findMaxArrayNLogN(testWhenNoElement, 0, 0);
    IndexAndSum oneElementResult2 = findMaxArrayNLogN(testWhenOneElement, 0, 0);
    IndexAndSum twoElementResult2 = findMaxArrayNLogN(testWhenTwoElement, 0, 1);
    IndexAndSum fourElementResult2 = findMaxArrayNLogN(testWhenFourElement, 0, 3);
    IndexAndSum twentyElementResult2 = findMaxArrayNLogN(testWhenTwentyElement, 0, 19);
  
    assert(noElementResult.low == 0 && noElementResult.high == 0);
    assert(oneElementResult.low == 0 && oneElementResult.high == 0);
    assert(twoElementResult.low == 1 && twoElementResult.high == 1);
    assert(fourElementResult.low == 2 && fourElementResult.high == 3);
    assert(twentyElementResult.low == 5 && twentyElementResult.high == 15);

    assert(noElementResult2.low == 0 && noElementResult2.high == 0);
    assert(oneElementResult2.low == 0 && oneElementResult2.high == 0);
    assert(twoElementResult2.low == 1 && twoElementResult2.high == 1);
    assert(fourElementResult2.low == 2 && fourElementResult2.high == 3);
    assert(twentyElementResult2.low == 5 && twentyElementResult2.high == 15);
}
