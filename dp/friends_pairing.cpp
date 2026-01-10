#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
//memoization / recursive
int f(int n) {
    // return (n <= 2) ? n : (ftd(n-1) + (n-1)*ftd(n-2)); 
    // if(dp[n] != -1) return dp[n];
    // else if(n <= 2) return dp[n] = n;
    // else return dp[n] = f(n-1) + (n-1) * f(n-2);

    return (dp[n] != -1) ? dp[n] : ((n <= 2) ? dp[n] = n : (dp[n] = f(n-1) + (n-1)*f(n-2)));
}

int main() {
    int n;
    cin>>n;
    dp.clear();
    dp.resize(10005,-1);
    
    cout<<f(n);

    return 0;
}