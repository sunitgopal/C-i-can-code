#ifndef LLST_H
#define LLST_H

#include <stdlib.h> //malloc

/* Declaring global struct with tag Node, and alias Node */
typedef struct Node
{
    int data;
    struct Node* ptr;
} NODE;

/* Globally declaring two Node pointers, head and tail */
NODE* head = NULL;          
NODE* tail = NULL;
// Global pointers would anyway get initialized to NULL


/* Function Declarations */

void create (int head_data);   
void print (void);                      // MODIFYLATER to take head pointer ITCO multiple lists
void append (int node_data);
void insert (int node_data, int pos);   // pos takes index values, not count values
void prepend (int head_data);
void takeout (int pos);                 // couldn't use the name "remove" BCZ it is already used in stdio.h
void reverse (void);                    // MODIFYLATER to take head pointer ITCO multiple lists
void sortAscndg (void);

#endif      // LLST_H