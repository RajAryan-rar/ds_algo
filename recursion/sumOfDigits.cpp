#include<iostream>
using namespace std;

int f(int n) {
    if(n == 0) return 0;
    return n%10 + f(n/10);

    //return (n == 0) ? 0 : n%10 + f(n/10);
}

int main() {
    cout<<f(1234);

    return 0;
}