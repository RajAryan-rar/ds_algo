#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define inf INT_MAX

vector<int> arr;
vector<vector<int>> dp;

int f(int i, int j) {
    if(i == j-1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = inf;
    for(int k=i+1; k<=j-1; k++) {
        ans = min(ans, f(i,k) + f(k,j) + arr[i]*arr[k]*arr[j]);
    }

    return dp[i][j] = ans;
}

int main() {
    int n;
    cin>>n;

    arr.resize(n+1);

    for(int i=1; i<n+1; i++) {
        cin>>arr[i];
    }
    dp.clear();
    // dp.resize(n+1, vector<int>(n+1,-1)); //for top down
    // cout<<f(1,n);


    //BOTTOM UP implementation :- 
    dp.resize(n+1, vector<int>(n+1,0));

    for(int len=3; len<=n; len++) {
        for(int i=1; i<=n-len+1; i++) {
            int j = i+len-1;
            dp[i][j] = inf;
            for(int k=i+1; k<=j-1; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    cout<<dp[1][n];

    return 0;
}