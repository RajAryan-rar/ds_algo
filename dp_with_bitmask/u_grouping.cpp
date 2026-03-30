#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define ll long long int

vector<ll> dp(1<<16, LLONG_MIN);
vector<ll> sum((1<<16),0);

// calculating score of group "mask"
ll calc(vector<vector<int>>& compat, int mask) {
    ll ans = 0;
    for(int i=0; i<16; i++) {
        for(int j=i+1; j<16; j++) {
            if(((mask & (1 << i)) != 0) && ((mask & (1 << j)) != 0)) {
                ans += compat[i][j];
            } 
        }
    }
    return ans;
}

//                                        n: no of rabbits
void precompute(vector<vector<int>>& compat, int n) {
    for(int mask = 1; mask <=((1 << n)-1); mask++) {
        sum[mask] = calc(compat,mask);
    }
}

ll f(vector<vector<int>>& compat, int mask) {
    if(mask == 0) return 0;
    if(dp[mask] != LLONG_MIN) return dp[mask];

    ll ans = 0;

    for(int g = mask; g != 0; g = ((g-1)&mask)) {
        ans = max(ans, sum[g] + f(compat, mask ^ g));
    }
    return dp[mask] = ans;
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> compat(n,vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>compat[i][j];
        }
    }
    precompute(compat,n);
    cout<<f(compat, ((1<<n)-1));

    return 0;
}