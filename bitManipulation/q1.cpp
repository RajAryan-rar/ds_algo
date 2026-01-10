#include<iostream>
using namespace std;
//Calculate minimum bits required to flip
//in order to convert one number to another

//using brian kernighan's algorithm to count no of setbits
int count_set_bits(int n) {
    int count = 0;
    while(n > 0) {
        count++;
        n = n & n-1;
    }
    return count;
}

int minCount(int a, int b) {
    int n = a ^ b;
    return count_set_bits(n);
}

int main() {
    int a,b;
    cin>>a>>b;

    cout<<minCount(a,b);

    return 0;
}