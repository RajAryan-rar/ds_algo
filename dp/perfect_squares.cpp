#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> c;
vector<int> dp;

int f(int n) {
    if(n == 0) return 0;
    if(n < 0) return INT_MAX;
    if(dp[n] != -1) return dp[n];

    int ans = INT_MAX;
    for(int i=0; i<c.size(); i++) {
        if(c[i] > n) break;
        if(n >= c[i]) dp[n] = ans = min(ans, f(n-c[i]));
    }

    return dp[n] = 1 + ans;
}

int numSquares(int n) {
    vector<int> v;
    for(int i=1; i*i<=10000; i++) {
        v.push_back(i*i);
    }
    c = v;
    dp.clear();
    dp.resize(10005,-1);

    return f(n);
}

int main() {
    int n;
    cin>>n;

    cout<<numSquares(n);

    return 0;
}