#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define mod 1000000007

vector<int> arr;

int dp[1000005];

int f(int x) {
    if(x == 0) return 1;

    if(x < 0) return 0;
    if(dp[x] != -1) return dp[x];

    int ans = 0;
    for(int i=0; i<arr.size(); i++) {
        if(x - arr[i] < 0) continue;
        ans = (ans%mod + f(x-arr[i])%mod)%mod;
    }
    return dp[x] = ans;

}

//To be fixed!!!
int f_bu(int target) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int x = 1; x <= target; x++) {
        for (int coin : arr) {
            if (x - coin < 0) continue;
            
            dp[x] = (dp[x]%mod + dp[x-coin]%mod) % mod;
            
        }
    }
    return dp[target];
}

int main() {
    int n,x;
    cin>>n>>x;

    arr.resize(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<f(x);
    

    return 0;
}