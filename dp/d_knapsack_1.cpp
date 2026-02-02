#include<iostream>
#include<vector>
using namespace std;

#define ll long long int

vector<int> weight;
vector<int> value;

vector<vector<ll>> dp;

ll f(int i, int cap) {
    if(i >= weight.size()) return 0;
    if(dp[i][cap] != -1) return dp[i][cap];
    
    ll ans = f(i+1,cap);
    if(weight[i] <= cap) {
        ans = max(ans, value[i] + f(i+1,cap-weight[i]));
    }

    return dp[i][cap] = ans;
}

ll f_bu(int cap) {
    dp.resize(105, vector<ll>(100005,0));

    for(int i=value.size()-1; i>=0; i--) {
        for(int curr_cap=0; curr_cap<=cap; curr_cap++) {
                    dp[i][curr_cap] = max(dp[i+1][curr_cap], (weight[i] <= curr_cap) ? value[i] + dp[i+1][curr_cap-weight[i]] : 0);
        }
    }

    return dp[0][cap];
}

int main() {
    int n,cap;
    cin>>n>>cap;

    vector<int> wt(n);
    vector<int> val(n);

    for(int i=0; i<n; i++) {
        cin>>wt[i]>>val[i];
    }

    weight = wt;
    value = val;

    // dp.resize(105, vector<ll>(100005,-1));

    // cout<<f(0,cap);

    cout<<f_bu(cap);


    return 0;
}