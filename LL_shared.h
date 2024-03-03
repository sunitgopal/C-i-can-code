#ifndef LL_SHARED_H
#define LL_SHARED_H


#include <stdlib.h> //malloc

/* Declaring global struct of tag/type Node, and alias NODE */
typedef struct Node
{
    int data;
    struct Node* ptr;
} NODE;


#endif      // LL_SHARED_H