#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define mod 1000000007

vector<int> arr;

vector<int> dp;

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

int f_bu(int target) {
    
    dp[0] = 1;
    for(int x=1; x<=target; x++) {
        for(int j=0; j<arr.size(); j++) {
            if(arr[j] > x) continue;
            dp[x] = (dp[x] + dp[x-arr[j]])%mod;
        }
    }
    return dp[target]%mod;
}

int main() {
    int n,x;
    cin>>n>>x;

    arr.resize(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    // dp.resize(x+1, -1);
    dp.resize(x+1, 0);
    cout<<f_bu(x);
    

    return 0;
}