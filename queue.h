#ifndef QUEUE_H
#define QUEUE_H

#include "LL.h"
#include <stdio.h>

typedef NODE QUEUEMEMBER;       // alias for NODE

static QUEUEMEMBER* first = NULL;       // first is the LL head node pointer
static QUEUEMEMBER* last  = NULL;       // last is the LL tail node pointer

void Enqueue (int);
void Dequeue (int*);
void Peek (void);
void Print(QUEUEMEMBER*);                   // for debug purposes   // expects first pointer

#endif              // QUEUE_H