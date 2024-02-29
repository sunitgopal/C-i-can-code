/* Stack using LL */

#include <stdio.h>
#include "stack_using_LL.h"

static STACKITEM* top = NULL;                                               // Would have anyway got initialized to NULL

int main(){

    Push(&top, 77);
    Push(&top, 99);
    int whatsPoppin, whatsPeekin;
    Pop(&top, &whatsPoppin);
    Push(&top, 44);
    Peek(&top, &whatsPeekin);
    
    return 0;
}

void Push(STACKITEM** ptr2top, int val){

    STACKITEM* newSTACKITEM = (STACKITEM*) malloc (sizeof(STACKITEM));

    if (newSTACKITEM == NULL){

        printf("Malloc error\nPush was unsuccessful\n");
        return;
    }
    newSTACKITEM->data = val;
    newSTACKITEM->ptr = NULL;

    if (*ptr2top != NULL){

        newSTACKITEM->ptr = *ptr2top;                                  // Pushing to the llst's Head position
    }
    *ptr2top = newSTACKITEM;                                           // notice how top doesn't point to next position in Stack
            
    Print(*ptr2top);

    return;           
}

void Print(STACKITEM* localtop){                                      // For debug purposes

    STACKITEM* temp = localtop;
    if (NULL == temp){

        printf("Empty Stack. Nothing to print\n");
        return;
    }
    printf("Stack: \n");
    while (temp != NULL){

        printf("%d \n", temp->data);
        temp = temp->ptr;
    }
    return;
}

void Pop (STACKITEM** ptr2top, int* ptr2poppeditem){

    if (NULL == *ptr2top){

        printf("Empty stack. Nothing to pop\n");
        return;
    }
    STACKITEM* temp = *ptr2top;
    *ptr2poppeditem = (temp)->data;
    printf("Popped item = %d\n", *ptr2poppeditem);
    
    *ptr2top = temp->ptr;
    
    free(temp);

    Print(*ptr2top);

    return;
}

void Peek(STACKITEM** ptr2top, int* ptr2topitem){

    if (NULL == *ptr2top){

        printf("Empty stack. Nothing to peek\n");
        return;
    }
    *ptr2topitem = (*ptr2top)->data;
    printf("Result of Peek = %d\n", *ptr2topitem);

    return;
}