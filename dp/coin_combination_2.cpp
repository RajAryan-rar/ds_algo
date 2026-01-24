#include<iostream>
#include<vector>
using namespace std;

#define mod 1000000007

vector<int> coins;
vector<int> dp;

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
    dp.resize(target+1,0);
    cout<<f_bu(target);

    return 0;
}