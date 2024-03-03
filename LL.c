#include "LL.h"

/* For visualization:  4 --> 10 --> 7 --> 5 --> 16 */

/* Globally declaring two static NODE pointers, head and tail */
static NODE* head = NULL;          
static NODE* tail = NULL;
// Global/static pointers would anyway get initialized to NULL if left uninitialized


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

    reverse();

    sortAscndg();

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
    
    printf("LL after create(%d): \n", head_data);
    print(head);
    return;
}


void print (NODE* head){

    NODE* iter = head;

    if (NULL == iter){
        printf ("Empty list. Nothing to print.\n");
        return;
    }
    while (iter->ptr != NULL){                                                  // exits once iter points at Tail node

        printf ("%d --> ", iter->data);
        iter = iter->ptr;
    }
    printf ("%d \n", iter->data);                                               // BEAUTIFICATION: to avoid printing an arrow after Tail node
    return;
} 


void append (int node_data){

    /* ITCO presence of Tail pointer */
/*
    if (head == NULL){
        printf("Empty list. Call create() first\n");
        return;
    }
    NODE* temp = (NODE*) malloc (sizeof(NODE));
    temp->data = node_data;
    temp->ptr = NULL;
    tail->ptr = temp;
    tail = temp;
    temp = NULL;                                                                // to avoid misuse of temp pointer
    return;
*/
    
    /* ITCO absence of Tail pointer */

    if (head == NULL){
        printf("Empty list. Call create() first\n");
        return;
    }
    NODE* temp = (NODE*) malloc (sizeof(NODE));
    temp->data = node_data;
    temp->ptr = NULL;
    
    // Define iter NODE ptr to get to the end of LL
    NODE* iter = head;
    while (iter->ptr != NULL){                                                  // exits when iter points to Tail node

        iter = iter->ptr;
    }
    iter->ptr = temp;

    printf("LL after append(%d): \n", node_data);
    print(head);
    return;
}


void insert (int node_data, int pos){


    if (0 == pos){                                                              // to cover the case of pos == 0

        printf("Consider using prepend(%d) instead, but sure\n", node_data);
        prepend(node_data);

        return;
    }
    
    // else if                                                                  // MODIFYLATER to cover pos > Tail node pos

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

        printf("LL after insert(%d, %d): \n", node_data, pos);
        print(head);

        return;
    }

    else if (temp->ptr == NULL){                           //  If reached the end of the LL 
        printf("No such index, thus appending \n");
        append (node_data);

        printf("LL after insert(%d, %d): \n", node_data, pos);
        print(head);

        return;
    }

    
}


void prepend (int hnode_data){

    NODE* newnode = (NODE*) malloc (sizeof(NODE));
    newnode->data = hnode_data;
    newnode->ptr = head;                   
    head = newnode;

    printf("LL after prepend(%d): \n", hnode_data);
    print(head);
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

        printf("LL after takeout(%d): \n", pos);
        print(head);
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

    printf("LL after takeout(%d): \n", pos);
    print(head);
    return;
}


void reverse (void){

    NODE* iter = head;

    if (NULL == iter){

        printf("Empty list. Nothng to reverse\n");
        return;
    }

    NODE* iterp = NULL;
    NODE* iterf = iter->ptr;

    while (iter->ptr != NULL){

        iter->ptr = iterp;
        iterp = iter;
        iter = iterf;
        iterf = iterf->ptr;
    }

    iter->ptr = iterp;
    head = iter;

    printf("LL after reverse(): \n");
    print(head);

    return;
}

void sortAscndg (void){

    // Using Selection Sort

    NODE* iter = head;
    if (NULL == iter){

        printf("Empty list. Nothng to sort\n");
        return;
    }
    NODE* iter2 = NULL;

    while (iter->ptr != NULL){                  

        iter2 = iter->ptr;
        
        while (iter2 != NULL){

            if (iter2->data < iter->data)
            {
                int tmp = iter->data;
                iter->data = iter2->data;
                iter2->data = tmp;
            }
            iter2 = iter2->ptr;
        }
        iter = iter->ptr; 
    }

    printf("LL after sortAscndg(): \n");
    print(head);

    return;
}