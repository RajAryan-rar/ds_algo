#include<iostream>
using namespace std;

int f(int n) {
    return (n <= 1) ? n : f(n-1)+f(n-2);
}

int main() {
    cout<<f(8);

    return 0;
}