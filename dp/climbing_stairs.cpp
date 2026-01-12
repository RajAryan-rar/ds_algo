#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int f(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;

    if(dp[n] != -1) return dp[n];

    return dp[n] = f(n-1) + f(n-2);
}

int f_bu(int n) {
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int climbStairs(int n) {
    dp.clear();
    dp.resize(50,-1);
    return f_bu(n);
}

int main() {
    int n;
    cin>>n;
    cout<<climbStairs(n);

    return 0;
}