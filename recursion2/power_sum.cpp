#include<iostream>
#include<cmath>
using namespace std;


//Not working ???
int count = 0;
void f(int x, int n, int i) {
    int p = (int)pow(i,n);
    if(x == 0) {
        count++;
        return;
    }
    if(i*i > x || p > x) return;
    // if(x < 0) return;

    f(x-p,n,i+1);
    f(x,n,i+1);
}

int main() {
    int x,n;
    cin>>x>>n;

    f(x,n,1);
    cout<<count;

    return 0;
}