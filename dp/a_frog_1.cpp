#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define ll long long int

vector<ll> dp;

ll f(int i, int n, vector<int>& arr) {
    if(i == arr.size() - 1) return 0;
    if(i == arr.size() - 2)  return dp[i] = abs(arr[i] - arr[i+1]);
    
    if(dp[i] != -1) return dp[i];
    
    return dp[i] = min(f(i+1,n,arr) + abs(arr[i]-arr[i+1]), 
               f(i+2,n,arr) + abs(arr[i]-arr[i+2]));
}

ll f_bu(int n, vector<int>& h) {
    dp[0] = 0;
    dp[1] = abs(dp[1] - dp[0]);

    for(int i=2; i<n; i++) {
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]));
    }

    return dp[n-1];
}

int main() {
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    dp.clear();
    dp.resize(100005,-1);
    // cout<<f(0,n,arr);

    cout<<f_bu(n,arr);

    return 0;
}