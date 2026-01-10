#include<iostream>
#include<vector>
using namespace std;
//Tabulation -> bottom up -> iterative
//Memoization -> top down -> recursive
vector<int> dp;

int ftd(int n) {
    if(dp[n] != -1) return dp[n];
    if(n <= 1) return n;

    return dp[n] = ftd(n-1) + ftd(n-2);
}

int fbu(int n) {
    for(int i=0; i<n+1; i++) {
        if(i == 0 || i == 1) dp[i] = i;
        else dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);

    cout<<fbu(n);

    return 0;
}