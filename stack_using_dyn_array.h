#ifndef STACK_USING_DYN_ARRAY_H
#define STACK_USING_DYN_ARRAY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {

    int* array;
    int stack_capacity;
    int top_index;
}STACK;

void Create (STACK*, int);
void Push (STACK*, int);
void Pop (STACK*, int*);
void print(STACK*);

#endif      // STACK_USING_DYN_ARRAY_H