#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void listInit(List * list)
{
    list->head = (Node *)malloc(sizeof(Node));
    list->head->next = NULL;
    list->comp = NULL;
    list->numOfData = 0;
}

void FInsert(List * list, LData data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = list->head->next;
    list->head->next = newNode;

    (list->numOfData)++;
}

void SInsert(List * list, LData data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    Node * pred = list->head;
    newNode->data = data;

    while (pred->next != NULL && list->comp(data, pred->next->data) != 0)
    {
        pred = pred->next;
    }

    newNode->next = pred->next;
    pred->next = newNode;

    (list->numOfData)++;
}

void LInsert(List * list, LData data)
{
    if (list->comp == NULL)
        FInsert(list, data);
    else
        SInsert(list, data);
}

int LFirst(List * list, LData * data)
{
    if (list->head->next == NULL)
        return FALSE;

    list->before = list->head;
    list->cur = list->head->next;

    *data = list->cur->data;
    return TRUE;
}

int LNext(List * list, LData * data)
{
    if (list->cur->next == NULL)
        return FALSE;

    list->before = list->cur;
    list->cur = list->cur->next;

    *data = list->cur->data;
    return TRUE;
}

LData LRemove(List * list)
{
    Node * rpos = list->cur;
    LData rData = rpos->data;

    list->before->next = list->cur->next;
    list->cur = list->before;

    free(rpos);
    (list->numOfData)--;
    return rData;
}

int LCount(List * list)
{
    return list->numOfData;
}

void setSortRule(List * list, int (*comp)(LData d1, LData d2))
{
    list->comp = comp;    
}


