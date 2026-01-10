#include<iostream>
using namespace std;

void f(int i, int n) {
    if(i > n) return;
    if(i <= n && i != 0) {
        cout<<i<<" ";
    }

    for(int k=0; k<=9; k++) {
        if(i == 0 && k == 0) continue;
        f(10*i+k, n);
    }
}

int main() {
    f(0,13);

    return 0;
}