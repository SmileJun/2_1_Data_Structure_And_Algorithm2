#ifndef __NODE_H__
#define __NODE_H__

typedef struct node {
    node * leftChild;
    node * rightChild;
    int value;
} Node;

#endif
