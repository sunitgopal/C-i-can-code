#ifndef QUEUE_H
#define QUEUE_H

#include "LL_shared.h"
#include <stdio.h>

typedef NODE QUEUEMEMBER;                   // alias for NODE

typedef struct Queue{
    QUEUEMEMBER* first;
    QUEUEMEMBER* last;
} Queue_Type;


Queue_Type* create (Queue_Type*);
void Enqueue (Queue_Type*, int);
void Dequeue (Queue_Type*, int*);
void Peek (Queue_Type*);
void Print(Queue_Type*);                   // for debug purposes   

#endif              // QUEUE_H