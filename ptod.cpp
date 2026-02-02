#include<iostream>
using namespace std;
#include<vector>

#define ll long long int

vector<int> weight;
vector<int> value;

vector<vector<ll>> dp;

ll f(int i, int cap) {
    if(i == weight.size()) return 0;
    if(dp[i][cap] != -1) return dp[i][cap];

    ll ans = f(i+1,cap);
    if(weight[i] <= cap) {
        ans = max(ans, (ll)(value[i] + f(i+1, cap-weight[i])));
    }

    return dp[i][cap] = ans;
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

    dp.resize(105, vector<ll>(100005,-1));

    cout<<f(0,cap);

    return 0;
}