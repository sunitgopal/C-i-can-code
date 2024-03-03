#ifndef LL_H
#define LL_H

#include "LL_shared.h"
#include <stdio.h>   

/* Function Declarations */

void create (int head_data);   
void print (NODE*);                      
void append (int node_data);
void insert (int node_data, int pos);   // pos takes index values, not count values
void prepend (int head_data);
void takeout (int pos);                 // couldn't use the name "remove" BCZ it is already used in stdio.h
void reverse (void);                    // MODIFYLATER to take head pointer to cover the case of multiple lists
void sortAscndg (void);

#endif      // LL_H