#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int> dp;

vector<int> getDigits(int n) {
    vector<int> digits;
    while(n>0) {
        int ld = n%10;
        if(ld != 0) digits.push_back(ld);
        n /= 10;
    }
    return digits;
}

int f(int n) {
    if(n<10) return 1;
    if(dp[n] != -1) return dp[n];
    vector<int> d = getDigits(n);

    int ans = INT_MAX;

    for(int i=0; i<d.size(); i++) {
        
        dp[n] = ans = min(ans, 1+f(n-d[i]));
    }
    return dp[n] = ans;
}

int main() {
    int n;
    cin>>n;

    dp.clear();
    dp.resize(1000005,-1);
    cout<<f(n);

    return 0;
}