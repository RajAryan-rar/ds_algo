#include<iostream>
#include<vector>
using namespace std;
/*
modulo arithmetic
(a+b)%c = (a%c + b%c)%c
(a-b)%c = (a%c - b%c + c)%c
(a*b)%c = (a%c * b%c)%c
*/
#define mod 1000000007

vector<int> dp;

int f(int n) {
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];

    int ans = 0;
    for(int i=1; i<=6; i++) {
        if(n-i < 0) break;
        dp[n] = ans  = (ans%mod + f(n-i)%mod)%mod;
    }
    return dp[n] = ans % mod;
}

int f_bu(int n) {
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=6; j++) {
            if(i-j < 0) break;
            dp[i] = (dp[i]%mod + dp[i-j]%mod)%mod;
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    dp.clear();
    dp.resize(1000005,0);
    cout<<f_bu(n);

    return 0;
}