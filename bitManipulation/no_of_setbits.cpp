#include<iostream>
using namespace std;

//setbits in a number --> ones present in the binary presentation of the number

int countSetBits(int n) {
    //Method -1 : using built in function
    return __builtin_popcount(n);
}

/*
Brian Kernighan's algorithm : an efficient method used to count the number of set bits (1s)
                              in the binary representation of an integer.
The algorithm is optimized to run in a number of iterations equal to the 
number of set bits, which is faster than checking every single bit
if the number of set bits is small. 

Observation : 
x and x-1 has exactly two parts same and flipped
the flipped portion starts from the last set bit of x :)
so its bitwiseAnd with x-1 will eliminate one set bit.
*/
int count_set_bits(int n) {
    int count = 0;
    while(n>0) {
        count++;
        n = n & n-1;
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    cout<<countSetBits(n);

    return 0;
}