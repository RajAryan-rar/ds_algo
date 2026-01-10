#include<iostream>
using namespace std;

int maxPowerOf2(int n) {
    int temp = 0;
    while(n > 0) {
        if(n != 0) temp = n;
        n = n & n-1;
    }
    return temp;
}

int flip_bits(int n) {
    int mp = maxPowerOf2(n);
    mp = mp << 1;
    mp = mp - 1;

    return mp ^ n;
}

int main() {
    int n;
    cin>>n;

    cout<<flip_bits(100);

    return 0;
}