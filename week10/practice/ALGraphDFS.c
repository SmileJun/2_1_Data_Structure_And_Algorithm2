#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int whoIsPrecede(int data1, int data2);

void graphInit(ALGraph * graph, int numOfVertex)
{
    int i;

    graph->adjList = (List*)malloc(sizeof(List)*numOfVertex);
    graph->visitInfo = (int *)calloc(numOfVertex, sizeof(int));
    graph->numOfVertex = numOfVertex;
    graph->numOfEdge = 0;

    for (i = 0; i < numOfVertex; ++i)
    {
        listInit(&(graph->adjList[i]));
        setSortRule(&(graph->adjList[i]), whoIsPrecede);
    }
}

void graphDestroy(ALGraph * graph)
{
    if (graph->adjList != NULL)
        free(graph->adjList);

    if (graph->visitInfo != NULL)
        free(graph->visitInfo);
}

void addEdge(ALGraph * graph, int fromVertex, int toVertex)
{
    LInsert(&(graph->adjList[fromVertex]), toVertex);
    LInsert(&(graph->adjList[toVertex]), fromVertex);
    graph->numOfEdge += 1;
}

void showGraphEdgeInfo(ALGraph * graph)
{
    int i;
    int vertex;

    for (i = 0; i < graph->numOfVertex; ++i)
    {
        printf("%c와 연결된 정점: ", i + 65);
        
        if (LFirst(&(graph->adjList[i]), &vertex))
        {
            printf("%c ", vertex + 65);

            while (LNext(&(graph->adjList[i]), &vertex))
                printf("%c ", vertex + 65);
        }
        printf("\n");
    }
}

int whoIsPrecede(int data1, int data2)
{
    if (data1 < data2)
        return 0;
    else
        return 1;
}
