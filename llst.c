#include <stdio.h>
#include <stdlib.h> //malloc

struct Node
{
    int data;
    struct Node* link;
};

struct Node* createll ();
void printll (struct Node* h);
void reversell (struct Node* h);
void deletep (struct Node* h, int P);
void insertp (struct Node*, int, int);

int main()
{
    struct Node* head = NULL; //declared and initialized pointer to head node 
    
    //now, start inserting nodes to this ll 

    
    int p = 3;  //position to delete node
    int newdata = 55;
    struct Node* temp = NULL; //declared and initialized temp node pointer to add new nodes
    
    head = createll();
/*    
    head = (struct Node*) malloc (sizeof(struct Node));     //allocated heap memory for head node
    head->data = n;
    head->link = NULL;

    temp = (struct Node*) malloc (sizeof(struct Node));     //allocated heap memory for second node
    temp->data = ++n;
    temp->link = NULL;
    head->link = temp;

    temp = (struct Node*) malloc (sizeof(struct Node));     //allocated heap memory for third node
    temp->data = ++n;
    temp->link = NULL;
    (head->link)->link = temp;

    temp = (struct Node*) malloc (sizeof(struct Node));     //allocated heap memory for fourth node
    temp->data = ++n;
    temp->link = NULL;
    ((head->link)->link)->link = temp;
    
*/

    printll (head);

    //free(temp);   //free function frees the heap location pointed to by its argument, essentially, no more of that piece of heap memory now available for use
    //free(temp1);

    /* created a 3 ele list so far*/
    /* Now, reverse it and print it too*/

    //reversell (head);

    /* Now, delete pth node*/

    deletep(head, p);
    printll (head);

    insertp (head, p, newdata);
    printll (head);

    return 0;    
}

struct Node* createll()
{
    struct Node* h = NULL;
    struct Node* temp = NULL;
    int n = 3;  //for incrementing node data; first node starts with data = 3
    
    h = (struct Node*) malloc (sizeof(struct Node));
    h->data = n;
    h->link = NULL;

    temp = (struct Node*) malloc (sizeof(struct Node));     //allocated heap memory for second node
    temp->data = ++n;
    temp->link = NULL;
    h->link = temp;

    temp = (struct Node*) malloc (sizeof(struct Node));     //allocated heap memory for third node
    temp->data = ++n;
    temp->link = NULL;
    (h->link)->link = temp;

    temp = (struct Node*) malloc (sizeof(struct Node));     //allocated heap memory for fourth node
    temp->data = ++n;
    temp->link = NULL;
    ((h->link)->link)->link = temp;

    return h;
}

void printll (struct Node* h)
{
    struct Node* temp = NULL;
    for (temp = h; temp!=NULL; temp = temp->link)
    {
        printf("%d ", temp->data);
    }
    printf ("\n");
}

void reversell (struct Node* h)
{
    struct Node* prev = NULL;
    struct Node* curr = NULL;
    struct Node* next = NULL;
    curr = h;
    while (curr->link != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;

/*      Debugging stmnts:
        printf("prev points to %d\n", prev->data);
        printf("curr points to %d\n", curr->data);
        printf("next points to %d\n\n", next->data);    */
    }
    curr->link = prev;
    h = curr;
    printll (h);
}

void deletep (struct Node* h, int P)
{
    /*first check if there is a Pth node*/
    struct Node* temp = NULL;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int i;
    for (temp = h, i = 0; temp != NULL; temp = temp->link)
    {
       i++;
    }
    printf("i = %d\n", i);
    if (i < P)
    {
        printf("there is no pth node\n");
    }
    else
    {
        for (temp = h, i = 0; i < P; i++, temp = temp->link)
        {
            if (i == (P-1))
            {
                prev = temp;
                break;
            }
        }
        temp = temp->link;              //node to be deleted
        next = temp->link;
        prev->link = next;
        free(temp);
    }


}

void insertp (struct Node* h, int p, int nodedata)
{
    //check if there is a p-1th node at all

    int count = 0;
    struct Node* temp = NULL;
    struct Node* newnode = NULL;

    for (temp = h; temp != NULL; temp = temp->link)
    {
        count++;
    }
    printf("intermediateo/p count = %d\n", count);

    if(count < (p-1))   //no p-1 th node at all
    {
        printf("ll has < p-1 nodes\n");
        return;
    }
    else    //yes p-1 th node
    {
        newnode = (struct Node*) malloc (sizeof(struct Node));
        newnode->data = nodedata;
        newnode->link = NULL;

        int i;
        for (i = 1, temp = h; i<p-1; temp = temp->link, i++)
        {

        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
}   