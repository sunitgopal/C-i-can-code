#ifndef STACK_LLST_H
#define STACK_LLST_H

#include "llst.h"

typedef NODE STACKITEM;

/* Function Declarations */

void Push(STACKITEM**, int);
void Print(STACKITEM*);
void Pop(STACKITEM**, int*);
void Peek(STACKITEM**, int*);

#endif              // STACK_LLST_H