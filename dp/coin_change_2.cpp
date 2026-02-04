#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> arr;

    vector<vector<int>> dp;

    int f(int i, int target) {
        if(target == 0) return 1;
        if(i >= arr.size() || target < 0) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        int ans = f(i+1,target); //not take
        if(arr[i] <= target) {
            ans += f(i, target-arr[i]);
        }
        return dp[i][target] = ans;
    }
    int change(int amount, vector<int>& coins) {
        arr = coins;
        dp.resize(coins.size()+1 ,vector<int>(5005,-1));
        return f(0,amount);
    }
};

int main() {
    int n,amount;
    cin>>n>>amount;

    vector<int> coins(n);

    for(int i=0; i<n; i++) {
        cin>>coins[i];
    }

    Solution s;
    cout<<s.change(amount,coins);

    return 0;
}