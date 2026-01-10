#include<iostream>
using namespace std;

/*
TC : log(min(a,b)) to the base golden ratio
*/
int gcd(int a, int b) {
    if(b == 0 || b == 1) return a;
    return gcd(b, a%b);
}

int main() {
    int a, b;
    cin>>a>>b;
    cout<<gcd(a,b);

    return 0;
}