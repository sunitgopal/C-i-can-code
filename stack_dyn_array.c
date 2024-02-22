#include "stack_dyn_array.h"

int main(){

    STACK* st = (STACK*) malloc (sizeof(STACK));
    int cap;
    int popped_val;

    printf("Enter the desired Stack capacity\n");
    scanf("%d", &cap);

    Create (st, cap);
    
    Pop(st, &popped_val);
    Push(st, 9);
    Push(st, 77);
    Pop(st, &popped_val);
    Push(st, 88);

    print(st);
    return 0;
}


void Create (STACK* stk, int capacity){

    stk->array = (int*) malloc (capacity * sizeof(int));
    
    if (NULL == stk->array){

        printf("Create() unsuccessful due to malloc failure\n");
        return;
    }

    stk->stack_capacity = capacity;
    stk->top_index = 0;

    print(stk);
    return;    
}

void Push (STACK* stk, int val){

    if (stk->top_index == ((stk->stack_capacity)-1)){

        printf("Array full. Reallocating..\n");
        stk->array = (int*) realloc (stk->array, (2 * stk->stack_capacity * sizeof(int)));      
    }
    stk->array[stk->top_index++] = val;

    print(stk);
    return;
}

void Pop (STACK* stk, int* ret_val){

    if (stk->top_index == 0){

        printf("Nothing to pop. Empty stack\n");
        return;                                  
    }
    *ret_val = stk->array[--stk->top_index];
    printf("Popped %d from the stack\n", *ret_val);
    print (stk);
    return;
}

void print(STACK* stk){                             // for debug purposes

    if (stk->top_index == 0){

        printf("Nothing to print. Empty stack\n");
        return;                                  
    }
    printf("Stack:\n ");
    for (int i=(stk->top_index-1); i>=0; i--){

        printf("%d\n", stk->array[i]);
    }
    return;
}
