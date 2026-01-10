#include<iostream>
using namespace std;

//decreasing order
void f(int n) {
    if(n == 0) return;
    cout<<n<<" ";
    f(n-1);
}

//increasing order
void f2(int n) {
    if(n == 0) return;
    f2(n-1);
    cout<<n<<" ";
}

int main() {
    f2(5);    

    return 0;
}