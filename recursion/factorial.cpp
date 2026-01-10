#include<iostream>
using namespace std;

int f(int n) {
    return (n == 1) ? 1 : n * f(n-1) ;
}

int main() {
    cout<<f(4)<<endl;

    return 0;
}