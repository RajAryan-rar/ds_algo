#include<iostream>
#include<vector>
using namespace std;

#define mod 1000000007

vector<vector<int>> dp;

int f(int i, int j) {
    if(j == 0) return 1;
    if(i <= 0 || j<= 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int pick = 0;
    if(j >= i) pick = f(i-1,j-i);
    int notPick = f(i-1,j);

    return dp[i][j] = (pick+ notPick)%mod;
}

int main() {
    int n;
    cin>>n;

    int sum = (n * (n+1)) / 2;
    if(sum % 2 != 0) {
        cout<<"0";
        return 0;
    }

    dp.resize(505, vector<int>(100000,-1));
    int target = sum/2 - n;
    cout<<f(n-1,target);

    return 0;
}