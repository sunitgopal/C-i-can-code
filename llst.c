#include <stdio.h>
#include "llst.h"

/* For visualization:  4 --> 10 --> 7 --> 5 --> 16 */

int main(){

    int hdata;
    printf ("Enter desired head-node data\n");
    scanf("%d", &hdata);

    create (hdata);

    append(9);
    create (99);
    
    insert(8, 0);
    
    prepend(7);

    insert (11, 3);
    
    takeout(0);
    append(7);

    return 0;
}


void create (int head_data){

    if (head != NULL){
        printf ("List already exists. Consider using append(%d) or insert(%d) instead\n", head_data, head_data);
        return;
    }
    head = (NODE*) malloc (sizeof(NODE));
    head->data = head_data;
    head->ptr = NULL;
    tail = head;
    
    print();
    return;
}


void print (void){

    NODE* iter = NULL;
    iter = head;
    if (iter == NULL){
        printf ("Empty list. Nothing to print.\n");
        return;
    }
    while (iter->ptr != NULL){           // exits when temp points at Tail node

        printf ("%d --> ", iter->data);
        iter = iter->ptr;
    }
    printf ("%d \n", iter->data);         // BEAUTFCTN: to avoid printing an arrow after Tail node
    return;
} 


void append (int NODE_data){
/*
    if (head == NULL){
        printf("Empty list. Call create() first\n");
        return;
    }
    NODE* temp = (NODE*) malloc (sizeof(NODE));
    temp->data = NODE_data;
    temp->ptr = NULL;
    tail->ptr = temp;
    tail = temp;
    return;
*/
    
    /* ITCO absence of Tail ptr */

    if (head == NULL){
        printf("Empty list. Call create() first\n");
        return;
    }
    NODE* temp = (NODE*) malloc (sizeof(NODE));
    temp->data = NODE_data;
    temp->ptr = NULL;
    
    // Define iter NODE ptr to get to the end of LL
    NODE* iter = head;
    while (iter->ptr != NULL){             // exits when iter points to Tail node

        iter = iter->ptr;
    }
    iter->ptr = temp;

    print();
    return;
}


void insert (int node_data, int pos){


    if (0 == pos){                                          // to cover the case of pos == 0

        printf("Consider using prepend(%d) instead, but sure\n", node_data);
        prepend(node_data);

        return;
    }
    
    // else if                                              // MODIFYLATER to cover pos > Tail node pos

    NODE* newnode = (NODE*) malloc (sizeof(NODE));
    newnode->data = node_data;
    newnode->ptr = NULL;                                    // to avoid indeterminacy
    
    NODE* temp = head;
    int count = 0;

    while((temp->ptr != NULL) && (count != (pos-1))){       //  Traverse till (pos-1)  
        temp = temp->ptr;
        count++;
    }

    if (count == (pos-1)){                                //  If reached the right index/pos   
        newnode->ptr = temp->ptr;
        temp->ptr = newnode;
        print();

        return;
    }

    else if (temp->ptr == NULL){                           //  If reached the end of the LL 
        printf("No such index, thus appending \n");
        append (node_data);
        print();
        
        return;
    }

    
}


void prepend (int hNODE_data){

    NODE* newnode = (NODE*) malloc (sizeof(NODE));
    newnode->data = hNODE_data;
    newnode->ptr = head;                   
    head = newnode;

    print();
    return;
}

void takeout (int pos){

    // if pos == 0 --> handle separately
    // iter till pos-1
    // iter->ptr = iter->ptr->ptr
    // print taken out NODE data
    // deallocate takenout NODE
    // MODIFYLATER to cover pos == Tail NODE, as well as > Tail NODE

    if (0 == pos){

        NODE* temp = head; 
        head = head->ptr;
        printf ("Takenout NODE data = %d\n", temp->data);
        free(temp);

        print();
        return;
    }
    NODE* iter = head;
    int count = 0;
    
    NODE* temp = NULL;
    while (count != (pos-1)){                  // exits when iter is at pos-1
        
        iter = iter->ptr;
        count++;
    }
    temp = iter->ptr;
    iter->ptr = temp->ptr;
    printf ("Takenout NODE data = %d\n", temp->data);
    free(temp);

    print();
    return;
}


void reverse (void){

    NODE* iterp = NULL;
    NODE* iter = NULL;
    NODE* iterf = NULL;

    iter = head;
    while (iter->ptr != NULL){

        iterf = iter->ptr;
        iter->ptr = iterp;
        iterp = iter;
        iter = iterf;
    }
    head = iter;
    head->ptr = iterp;

    print();
    return;
}