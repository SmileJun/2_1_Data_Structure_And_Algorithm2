#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numOfVertex;
    int numOfEdge;
    List * adjList;
} ALGraph;

void graphInit(ALGraph * graph, int numOfVertex);
void graphDestroy(ALGraph * graph);
void addEdge(ALGraph * graph, int fromVertex, int toVertex);
void showGraphEdgeInfo(ALGraph * graph);

#endif
