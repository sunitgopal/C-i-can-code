#include "queue.h"


int main(){

    Queue_Type* q1 = create(q1);
    Peek(q1);
    Enqueue(q1, 7);
    Peek(q1);

    int dequeued_val;
    Dequeue(q1, &dequeued_val);
    Peek(q1);

    Dequeue(q1, &dequeued_val);
    Enqueue(q1, 2);
    Enqueue(q1, 4);
    Peek(q1);
    Dequeue(q1, &dequeued_val);

    return 0;
}

Queue_Type* create(Queue_Type* q){

    q = (Queue_Type*) malloc (sizeof(Queue_Type));
    
    if (NULL == q){

        printf("create() unsuccessful due to malloc failure\n");
        return NULL;
    }
    q->first = NULL;
    q->last = NULL;
    return q;
}

void Enqueue (Queue_Type* q, int val){

    QUEUEMEMBER* qmember = (QUEUEMEMBER*) malloc (sizeof(QUEUEMEMBER));

    if (NULL == qmember){

        printf ("Enqueue() unsuccessful due to malloc failure.\n");
        return;
    }

    qmember->data = val;
    qmember->ptr = NULL;
    
    if (NULL == q->first){
        
        q->first = qmember;
    }
    if (NULL == q->last){

        q->last = q->first;
    }
    else{

        q->last->ptr = qmember;
        q->last = qmember;
    }

    printf("Queue after Enqueue():\n");
    Print(q);
    return;
}

void Dequeue (Queue_Type* q, int* dqd_val){

    if (NULL == q->first){

        printf ("Empty Queue. Nothing to Dequeue\n");
        return;
    }

    QUEUEMEMBER* temp = q->first;

    if (q->first == q->last){             // when there's only one item in Queue

        q->last = NULL;
    }
    
    q->first = q->first->ptr;

    *dqd_val = temp->data;

    free(temp);

    printf("Queue after Dequeue():\n");
    Print(q);
    return;
}

void Peek(Queue_Type* q){

    if (NULL == q->first){
        printf("Empty Queue. Nothing to peek\n");
        return;
    }

    printf("First item in Queue = %d\nLast item in Queue = %d\n", q->first->data, q->last->data);

    return;
}

void Print(Queue_Type* q){

    if (NULL == q->first){
        printf("Empty Queue. Nothing to print\n");
        return;
    }

    QUEUEMEMBER* iter = q->first;

    while(iter->ptr != NULL){

        printf("%d, ", iter->data);
        iter = iter->ptr;
    }
    printf("%d\n", iter->data);

    return;
}