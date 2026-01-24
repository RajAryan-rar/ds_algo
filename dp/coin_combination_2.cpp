#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define mod 1000000007

vector<int> coins;
vector<int> dp;

/*
top-down is giving TLE!!!
To be fixed
Logic is correct

TLE :-  
    1. Function Call Overhead
        In C++, every time you call a function, the computer has to perform several operations:
        * Pushing arguments onto the stack.
        * Saving the return address.
        * Jumping to a new memory location.
        * Allocating a new stack frame.
*/
int fdp[1000005][105];
int f(int target, int i) {
    if(target == 0) return 1;
    if(i >= coins.size() || target < 0) return 0;

    if(fdp[target][i] != -1) return fdp[target][i];

    return fdp[target][i] = (f(target-coins[i], i) + f(target,i+1))%mod;
}

int f_bu(int target) {
    dp[0] = 1;
    for(int i=0; i<coins.size(); i++) {
        for(int x=1; x<=target; x++) {
            if(x - coins[i] < 0) continue;
            dp[x] = (dp[x] + dp[x-coins[i]])%mod;
        }
    }
    return dp[target];
}

int main() {
    int n,target;
    cin>>n>>target;
    coins.resize(n);

    for(int i=0; i<n; i++) {
        cin>>coins[i];
    }
    // dp.resize(target+1,0);
    // cout<<f_bu(target);
    memset(fdp, -1, sizeof(fdp));
    cout<<f(target,0);

    return 0;
}