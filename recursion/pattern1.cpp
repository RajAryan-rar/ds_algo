#include<iostream>
using namespace std;

// method -1
// void helper(int n) {
//     if(n<=0) return;
//     cout<<"* ";
//     helper(n-1);
// }

// void f(int n, int i) {
//     if(i >= n) return;
//     helper(n);
//     cout<<endl;
//     f(n,i+1);
// }

void f(int r, int c, int n) {
    if(r > n) return;
    if(c >= n-r) { // r -> sedha && n-r -> ulta triangle
        cout<<endl;
        f(r+1, 0, n);
        return; // imp to remove the stack frame of the above fxn call after its exec from stack
    }
    cout<<"* ";
    f(r,c+1,n);
}

/*
* * * *
* * * 
* * 
*
*/

int main() {
    f(0,0,9);

    return 0;
}
