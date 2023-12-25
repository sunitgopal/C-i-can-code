#include <stdio.h>

int isOdd(unsigned int x){      // Returns 1 if Odd, 0 if even    // printf("%s", isOdd(a) ? "Odd" : "Even");
    
    if(x & 1u){
        return 1;
    }
    return 0;
}

/*****************************************************************************************************/

int areOppSigns(int x, int y){  // Returns 1 if Opp, 0 if Same


    if ((x ^ y) < 0){              // Opp sign
        return 1;
    }
    return 0;
}

/*****************************************************************************************************/

/********** Add 1 to an integer ***************/

// Use the fact that 2's complement of a number (how -number is stored) is (1+inv(number))
// -x = ~x + 1;
// -~x = 1+x

int addOne(int x){              // Returns result

    int ans;                     
    ans = -(~x);                
    return ans;
}

/*****************************************************************************************************/

/******** Swap two numbers w/o third variable **********/

// x ^ x = 0
// x ^ 0 = x

void Swap(int * x, int * y){

    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;

    return;
}

/*****************************************************************************************************/

/******* Turn off kth bit in a number ***************/

// make a MACRO that takes in the position k, and makes a MASK for that position

#define MASK(k) (1u << (k))

int kthOff (int x, int k){

    int ans;
    ans = x & (~(MASK(k)));
    
    return ans;
}

/*****************************************************************************************************/

/******* Turn on kth bit in a number ***************/

//#ifndef MASK(k)                   // ifndef doesn't work on MACROFUNCTION ?
//#define MASK(k) (1u << k)

//#endif

// using the same MACROFUNCTION created above

void kthOn (int* x, int k){

    *x |= MASK(k);

    return; 
}

/*****************************************************************************************************/

/******* Check if kth bit is set in a number ***************/

// using the same MACROFUNCTION created above

int iskthSet(int x, int k){

    return (x & MASK(k));
}

/*****************************************************************************************************/

/******* Toggle the kth bit ***************/

// using the same MACROFUNCTION created above

void togglekth(int* x, int k){

    *x ^= MASK(k);
}

/*****************************************************************************************************/

/******* Unset the righmost-set bit ***************/

// performing n & (n-1) unsets the rightmost-set-bit in n
// (n-1) has all the bits AFTER the rightmost-set-bit flipped w.r.t n

int unsetrightmostset (int x){         // Returns result

    return (x & (x-1));
}

/*****************************************************************************************************/

/******* Check if number is a power of 2 ***************/

// put the righmost-set-bit concept to use
// pwr of 2 will only have one bit set in total
// so, if pwrof2, then unsetting that bit should yield 0

int ispwroftwo (int x){                 // Returns 1 if true, 0 false
    
    //(x & (x-1)) ? return (0) : return (1);        //error: expected expression before return

    if(x&(x-1))
        return 0;
    else
        return 1;
}

/*****************************************************************************************************/

/******* Find position of the righmost-set-bit ***************/

// AGAIN put the righmost-set-bit concept to use
// unset the rmost-set-bit ; then XOR the result with the origl number --> only that bit will be set

int rmostsetpos (int x){

    int y = x;
    int pos = -1;                       // BCZ I want rmost-bit as pos = 0
    x &= x-1;
    y ^= x;

    while(y){
        y = y >> 1;
        pos++;
    }
    return pos;

}

/*****************************************************************************************************/


/******* Uppercase to lowercase, vice-versa, and Toggle***************/

// A is 0100 0001, a is 0110 0001
// Space character (' ') is 0x20
// Hence, simply Bitwise-OR A with ' ' to get a
// And, a to A by Bitwise-AND a with Underscore character('_')

// And to toggle b/n Uppcase and Lowcase, simply XOR with ' '


/*****************************************************************************************************/

/******* Count the number of set-bits ***************/

// unset rmost-set-bit until 0 set bits left ?

int countsetbits (int x){

    int count = 0;
    while (x){
        x &= x-1;                   // this unsets the rmost-set-bit
        count++;
    }
    return count;
}

/*****************************************************************************************************/

/******* Swap endianness using bmpln ***************/

unsigned int swEndn (unsigned int x){        // 0x 1234abcd ---> 0x cdab3412

    x = (x >> 16) | (x << 16);      // 0x abcd1234
    x = ((x & (0xff00ff00)) >> 8) | ((x & (0x00ff00ff)) << 8);

    return x;
}

/*****************************************************************************************************/

/******* Generate an array with number of set-bits in each index value ***************/

// for any value n, generate an array that is n elements long

void genarr (int n){

    unsigned int arr[n];

    for (int i=0; i<n; i++){

        arr[i] = countsetbits(i);
    }
    for (int i=0; i<n; i++){

        printf("%d, ", arr[i]);
    }

    return;
}

int main(){
    
    int n = 5;
        
    genarr(n);

    return 0;
}

