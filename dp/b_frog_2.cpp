#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define ll long long int

vector<ll> dp;

ll f(int n, int k, vector<int>& h) {
    if(n == 1) return 0;
    if(n == 2) return abs(h[2] - h[1]);

    if(dp[n] != -1) return dp[n];

    ll minCost = LLONG_MAX;

    for(int i=1; i<=k && n-i>=1; i++) {
        dp[n] = minCost = min(minCost,f(n-i,k,h) + abs(h[n]-h[n-i]));
    }
    return minCost;
}
/*
--Not working debug!!!
ll f_bu(int n, int k, vector<int>& h) {
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    
    ll minCost = LLONG_MAX;
    
    for(int i=n; i>=3; i--) {
        for(int j=1; j<=k && i-j>=1; j++) {
            dp[i] = minCost = min(minCost, dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    return minCost;
}
*/

int main() {
    int n,k;
    cin>>n>>k;

    vector<int> h(n+1,0);

    for(int i=1; i<=n; i++) {
        int x;
        cin>>x;
        h[i] = x;
    }
    dp.clear();
    dp.resize(100005,-1);
    cout<<f(n,k,h);

    return 0;
}