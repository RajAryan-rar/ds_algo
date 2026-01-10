#include<iostream>
using namespace std;

int f(int a, int b) {
    if(b == 0) return 1;
    return a * f(a, b-1);
} // return (b == 0) ? 1 : a * f(a,b-1);


//method-2 optimized log b
int f2(int a, int b) {
    if(b == 0) return 1;
    
    int value = f(a,b/2);

    if(b%2 == 0) {
        return value*value;
    } else {
        return (a * value * value);
    }
}

int main() {
    cout<<f2(2,3);

    return 0;
}