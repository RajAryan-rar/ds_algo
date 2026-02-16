#include<iostream>
#include<vector>
#include<climits>

using namespace std;

#define ll long long int
#define inf LLONG_MAX

vector<ll> arr;
vector<vector<ll>> sum;

vector<vector<ll>> dp;

ll f(int i, int j) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    ll ans = inf;
    for(int k=i; k<j; k++) {
        ans = min(ans, f(i,k) + f(k+1,j) + sum[i][j]);
    }

    return dp[i][j] = ans;
}

int main() {
    int n;
    cin>>n;

    arr.clear();
    arr.resize(n+1);

    for(int i=1; i<=n; i++) {
        cin>>arr[i];
    }

    sum.resize(n+1, vector<ll>(n+1,0));

    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            sum[i][j] = arr[j] + ((i == j) ? 0 : sum[i][j-1]);
        }
    }
    dp.clear();
    dp.resize(n+1, vector<ll>(n+1,-1));
    cout<<f(1,n);

    return 0;
}