#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define ll long long int

vector<int> c;
vector<ll> dp;
int f(int amount) {
    if(amount < 0) return INT_MAX;
    if(amount == 0) return 0;
    if(dp[amount] != -1) return dp[amount];

    ll ans = INT_MAX;
    for(int i=0; i<c.size(); i++) {
        if(c[i] <= amount) 
        dp[amount] = ans = min(ans, (ll)(f(amount - c[i])));
    }
    if(ans == INT_MAX) return INT_MAX;
    return dp[amount] = 1 + ans;
}

int coinChange(vector<int>& coins, int amount) {
    c = coins;
    dp.clear();
    dp.resize(10005,-1);
    return (f(amount) == INT_MAX) ? -1 : f(amount);
}

int main() {
    int n,amount;
    cin>>n>>amount;
    vector<int> coins(n);

    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        coins[i] = x;
    }

    int result = coinChange(coins, amount);
    cout<<result;

    return 0;
}