#include<iostream>
using namespace std;

//sol : make all setbits 0 except the MSB setbit

int max_pow_of_2(int n) {
    //considering max 32 bits number
    if(n == 0) return 0;
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);

    return (n+1)>>1;
}

int main() {
    int n;
    cin>>n;

    //Brian Kernighan algorithm
    /*
    int temp = 0;
    while(n > 0) {
        n = n & n-1;
        if(n!=0) temp = n;
    }
    cout<<temp;
    */

    cout<<max_pow_of_2(n);

    return 0;
}