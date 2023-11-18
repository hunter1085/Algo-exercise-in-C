/*A binary gap within a positive integer N is any maximal sequence of consecutive zeros 
that is surrounded by ones at both ends in the binary representation of N.
For example, number 9 has binary representation 1001 and contains a binary gap of 
length 2. The number 529 has binary representation 1000010001 and contains two binary
gaps: one of length 4 and one of length 3. The number 20 has binary representation 
10100 and contains one binary gap of length 1. The number 15 has binary representation
1111 and has no binary gaps. The number 32 has binary representation 100000 and has no
binary gaps.*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE  0x1
#define FALSE 0x0
#define MAX(a,b) a > b ? a : b

//find the max zeros between ones for an integer
int BinaryGap(int N){
    if(N == 0x0) {
        return 0;
    }
    
    int findOne = FALSE;
    int tmpZeros = 0, maxZeros = 0;
    for(; N > 0; N >>= 1) {
        if((N & 0x1) == 0) { // get zero
            tmpZeros++;
        }else{ //get one
            if(!findOne) { //if get zeros before find a one,then reset tmpZeros
                findOne = TRUE;
                tmpZeros = 0;
            }else{
                maxZeros = MAX(maxZeros,tmpZeros);
                tmpZeros = 0;
            }
        }
    }
    return maxZeros;
}
struct testN {
    int N;
    int maxZeros;
};
int main(){
    #define testArrayLen 7
    int i;
    struct testN items[testArrayLen] = {
        {0x238,3},  //0000 0010 0011 1000
        {0x1022,6}, //0001 0000 0010 0010
        {0x10,0},   //0000 0000 0001 0000
        {0x211,4},  //0000 0010 0001 0001
        {0xF,0},    //0000 0000 0000 1111
        {0x411,5}   //0000 0100 0001 0001
        
    };
    for(i = 0; i < testArrayLen;i++){
        char *result;
        int maxZeros = BinaryGap(items[i].N);
        if(maxZeros == items[i].maxZeros) {
            result = "pass";
        }else{
            result = "failed";
        }
        printf("max zeros for 0x%x is %d, expected zeros: %d, test result: [%s]\n",
        items[i].N,maxZeros,items[i].maxZeros,result);
    }
    return 0;
}
