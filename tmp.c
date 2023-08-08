#include <stdio.h>
#include <string.h>

#define VARSIZE(var) ((char*)(&var+1) - (char*)(&var))      /*MTA: & operator returns a pointer to the variable. +1 takes you beyond the end of the variable. char* typecasting helps you count.*/

/* Write a macro to read from a HW register */

#define HWREG(addr) (*(volatile unsigned int*)(addr))

#define REGADDR 0xAB230000

/*
//to load the value, declare variable v

unsigned int v = HWREG(REGADDR);

//To store to this hw reg

HWREG(REGADDR) = value;
*/

/***********************************************************/

/*Reverse a number*/

int reversedigit(int num)
{
    int result = 0, count = 0;
    int tmp = num;              //in case original num is needed 
    while (num)
    {
        result = (result*10) + num%10;
        num /= 10;
    }
    return result;
}

/*************************************************************/

/* Check a num is prime or not */

int isprime(int num)
{
    if (num%2 == 1)
    {
        for(int i=2; i<num; i++)
        {
            if (num%i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

/****************************************************************/

/*Palindrome number*/

int isPalindrome(int num)
{
    int rev = 0;
    int num2 = num; //in case origl num is needed later
    while (num2)
    {
        rev = (rev*10) + (num2%10);
        num2 /= 10;
    }
    if (rev == num)
        return 1;
    else
        return 0;
}

/*****************************************************************/

/* reattempt: Palindrome number*/

int isnumberPal (int n)
{
    int m = n;
    int rev = 0;
    while (n > 0)
    {
        rev = rev*10 + n%10;
        n/=10;
    }
    printf ("rev = %d", rev);
    if (rev == m)
        return 1;
    else
        return 0;
}

/*Fibonacci recursion*/

int Fibonacci (int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return (Fibonacci(num-1) + Fibonacci(num-2));
}

/*******************************************************************/

/* Fibonacci iteratively*/

int Fibon (int n)
{
    int p = 0, q = 1, ans;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        for(int i = 2; i<= n; i++)
        {
            ans = p+q;
            p = q;
            q = ans;
        }
        return ans;
    }
}

/********************************************************************/

/*Factorial of a number RECURSIVELY*/

int Factorial (int num)
{
    if(num == 1)
        return 1;
    else if (num ==0)
        return 1;
    else
        return (num*Factorial(num-1));
}
/********************************************************************/

/* Factorial ITERATIVELY*/

int Fact (int n)
{
    int m = 1, ans;
    if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else
    {
        for (int i=2; i<=n; i++)
        {
            ans = i*m;
            m = ans;
        }
        return ans;
    }

}

/*******************************************************************/

/*Reverse a string*/

char* strrev (char* s, int size)
{
    char* ans = s;
    for (int i=0; i<size; i++)
    {
        ans[size-1-i] = s[i];
    }
    return ans;
}
/**********************************************************************/

/* Reverse a string w/o creating a new one*/

void revstr (char* s, int len)
{
    char temp;
    for (int i=0; i<len/2; i++)
    {
        temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;
    }
}

/*********************************************************************/

/*Find first duplicate element in Array*/

int FirstDup (int* a, int l)
{
    for (int i=0; i<l-1; i++)
    {
        for (int j=i+1; j<l; j++)
        {
            if (a[i] == a[j])
            {
                return a[i];
            }
        }
    }
    return -1;
    /*
    inside main:

    printf("Enter size\n");
    scanf("%d", &size);
    printf("Enter elements\n");
    for (int i=0; i<size; i++)
    {
        scanf("%d", &ar[i]);
    }
    
    */
}

/********************************************************************/

/* Remove consecutive characters of a string */

char* RmvChar (char* s, int l)
{
    char* ans;
    for(int i=0; i<l; i=i+2)
    {
        ans[i/2] = s[i];
    }
    ans[l/2] = '\0';
    return ans;
}

/*******************************************************************/

/*Bubble Sort*/

void bubsort (int* nums, int n)
{
    int temp;
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1; j++)
        {
            if(nums[j] > nums[j+1])
            {
                nums[j] = nums[j]^nums[j+1];
                nums[j+1] = nums[j]^nums[j+1];
                nums[j] = nums[j]^nums[j+1];
            }
        }
    }
}
/*******************************************************************/

/* BitMnpl: check whether ith bit set or not */

int isBitSet (char c)
{
    //checking if bit i is set
    //char mask
    char mask = 0x10;
    if(~(mask)^c)
        return 1;
    return 0;
}
/* *****************************************************************/

/* BitMnpl: Check if number is power of 4*/

//      Check if number is power of 2 AND mod 3 == 1

int isPwrof4 (int num)
{
    if ((num & (num-1)) == 0) //Power of 2
    {
        if (num%3 == 1)
            return 1;
    }
    else
        return 0;   //False
}

/*******************************************************************/

/* Check if given string is a Palindrome */

int isPal (char* s, int len)
{
    char* ss = s;
    for (int i=0; i<(len/2); i++)               //thought of reversing but there's no need
    {
        if(ss[i] != s[len-1-i])
            return 0;
        else
            return 1;
    }
}

/*********************************************************************/

/* Remove odd numbers from array */

int* rmvodds (int* ar, int* size)
{
    int count = 0;
    int sizeofar = *size;
    printf("sizeofar = %d\n", sizeofar);
    for (int i=0; i<*size; i++)
    {
        if (ar[i]%2 == 0)
        {
            count++;
        }
    }
    printf("count = %d\n", count);
    int* ans = (int*) malloc (count*sizeof(int));
    for (int i=0, j=0; i<*size; i++)
    {
        if (ar[i] %2 == 0)
        {
            ans[j] = ar[i];
            j++;
        }
    }
    *size = count;
    return ans;

    /*
    int main()
{
    int arr[] = {8,9,5,6,1,2,7,4,7};
    int size = sizeof(arr)/sizeof(int);
    //printf("size = %d\n", size);      //works
    int* arrout = NULL;
    arrout = rmvodds(arr, &size);
    printf("size = %d\n", size);
    for (int i=0; i<size; i++)
    {
        printf("%d ", arrout[i]);
    }
    //free(what?)       //find answer: what to free in this case of dynamic mem allocation
    return 0;
}
    */

/***************************************************************************/
}

int main()
{
    /*int n = 64;
    if (isPwrof4(n))
        printf("True");
    else
        printf("False");
    /*char* str = "String";
    n = strlen(str);
    char* result = strrev(str, n);
    printf("%s ", result);
    */

    int n;
    n = Fibon(4);
    printf("last term = %d", n);
    return 0;
}