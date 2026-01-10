#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

//instead of power function use bit manipulation
// i.e, use left shift : 1 << (n-1)  --> 2^(n-1)
char f(char root, int n, int k) {
    if(n == 1) {
        return root;
    }
    long long int value =  (1L << (n-1)) / 2;
    if(k <= value) {
        return f(root,n-1,k);
    } 
    else {
        char new_root = (root == 'M') ? 'F' : 'M';
        return f(new_root,n-1,k-value);
    }
}

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        long long int k;
        cin>>n>>k;
        
        char ch = f('M',n,k);
        if(ch == 'M') cout<<"Male"<<endl;
        else cout<<"Female"<<endl;
    }

    return 0;
}