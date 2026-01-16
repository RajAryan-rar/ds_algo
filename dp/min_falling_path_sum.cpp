#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define ll long long int 

class Solution {
public:
    vector<vector<int>> arr;
    vector<vector<ll>> dp;
    ll f(int i, int j) {
        if(i >= arr.size() || j >= arr.size() || j < 0) return INT_MAX;
        if(i == arr.size()-1) return arr[i][j];
        if(dp[i][j] != INT_MIN) return dp[i][j];

        return dp[i][j] = arr[i][j] + min(f(i+1,j-1), min(f(i+1,j),f(i+1,j+1)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        arr = matrix;
        dp.clear();
        dp.resize(105, vector<ll>(105,INT_MIN));
        ll ans = INT_MAX;
        for(int j=0; j<matrix.size(); j++) {
            ans = min(ans,f(0,j));
        }
        return ans;
    }
};

int main() {
    

    return 0;
}