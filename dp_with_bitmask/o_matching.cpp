#include<iostream>
#include<vector>
using namespace std;

#define mod 1000000007

vector<vector<int>> compat;
vector<vector<int>> dp;

int f(int i, int mask) {
    if(mask == 0) return 1;
    if(i == (int)compat.size()) return 0;
    if(dp[i][mask] != -1) return dp[i][mask];

    int ans = 0;
    for(int j=0; j<(int)compat[i].size(); j++) {
        if(compat[i][j] == 1 && (mask & (1 << j))) {
            ans = (ans + f(i+1, mask ^ (1 << j))) % mod;
        }
    }
    return dp[i][mask] = ans % mod;
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }
    compat = arr;
    dp.resize(n, vector<int>(1<<n, -1));
    
    cout<<f(0, (1 << n)-1);

    return 0;
}