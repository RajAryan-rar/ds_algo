#include<iostream>
using namespace std;

/**
 * Reverse bits of a given 32 bits signed integer.
 */
int reverse_bits(int n) {
    int res = 0;
    for(int i=0; i<32; i++) {
        res <<= 1;
        res |= (n&1);
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin>>n;

    //Method -1 :
    // __builtin_bitreverse32(n);

    cout<<reverse_bits(n);

    return 0;
}