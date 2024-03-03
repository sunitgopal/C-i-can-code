#ifndef STACK_USING_LL_H
#define STACK_USING_LL_H

#include "LL_shared.h"

typedef NODE STACKITEM;

/* Function Declarations */

void Push(STACKITEM**, int);
void Print(STACKITEM*);
void Pop(STACKITEM**, int*);
void Peek(STACKITEM**, int*);

#endif              // STACK_USING_LL_H