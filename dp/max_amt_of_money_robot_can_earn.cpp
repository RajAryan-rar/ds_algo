#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> arr;
    int dp[505][505][3];
    int f(int i, int j, int k) { //k --> no of neutralizations left
        if(i == arr.size()-1 && j == arr[0].size()-1) {
            if(arr[i][j] < 0 && k > 0) return 0;
            else return arr[i][j];
        }
        if(i >= arr.size() || j >= arr[0].size()) return -1e9;
        if(dp[i][j][k] != INT_MIN) return dp[i][j][k];
        int ans = -1e9;
        ans = arr[i][j] + max(f(i+1,j,k), f(i,j+1,k));
        if(arr[i][j] < 0 && k > 0) {
            ans = max(ans,max(f(i+1,j,k-1), f(i,j+1,k-1)));
        } 
        return dp[i][j][k] = ans;
        
    }
    int maximumAmount(vector<vector<int>>& coins) {
        arr = coins;
        for(int i=0;i<505;i++)
            for(int j=0;j<505;j++)
                for(int k=0;k<3;k++)
                    dp[i][j][k] = INT_MIN;

        return f(0,0,2);
    }
};

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> coins(m, vector<int>(n));

    Solution s;
    cout<<s.maximumAmount(coins)<<endl;

    return 0;
}