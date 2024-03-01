#include "queue.h"



int main(){

    Peek();
    Enqueue(7);
    Peek();

    int dequeued_val;
    Dequeue(&dequeued_val);
    Peek();

    Dequeue(&dequeued_val);
    Enqueue(2);
    Enqueue(4);
    Peek();

    return 0;
}

void Enqueue (int val){

    QUEUEMEMBER* qmember = (QUEUEMEMBER*) malloc (sizeof(QUEUEMEMBER));

    if (NULL == qmember){

        printf ("Enqueue unsuccessful due to malloc() failure.\n");
        return;
    }

    qmember->data = val;
    qmember->ptr = NULL;
    
    if (NULL == first){
        
        first = qmember;
    }
    if (NULL == last){

        last = first;
    }
    else{

        last->ptr = qmember;
        last = qmember;
    }

    printf("Queue after Enqueue():\n");
    Print(first);
    return;
}

void Dequeue (int* dqd_val){

    if (NULL == first){

        printf ("Empty Queue. Nothing to Dequeue\n");
        return;
    }

    QUEUEMEMBER* temp = first;

    if (first == last){             // when there's only one item in Queue

        last = NULL;
    }
    
    first = first->ptr;

    *dqd_val = temp->data;

    free(temp);

    printf("Queue after Dequeue():\n");
    Print(first);
    return;
}

void Peek(){

    if (NULL == first){
        printf("Empty Queue. Nothing to peek\n");
        return;
    }

    printf("First item in Queue = %d\nLast item in Queue = %d\n", first->data, last->data);

    return;
}

void Print(QUEUEMEMBER* beg){

    if (NULL == beg){
        printf("Empty Queue. Nothing to print\n");
        return;
    }

    QUEUEMEMBER* iter = beg;

    while(iter->ptr != NULL){

        printf("%d, ", iter->data);
        iter = iter->ptr;
    }
    printf("%d\n", iter->data);

    return;
}