#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<vector<int>>& arr, int i, int j) {
        if(i >= arr.size() || j >= arr.size()) return 0;
        if(dp[i][j] != INT_MIN) return dp[i][j];

        return dp[i][j] = arr[i][j] +  min(f(arr,i+1,j+1), f(arr,i+1,j));
    }
    int f_bu(vector<vector<int>>& arr) {
        int m = arr.size();
        for(int j=0; j<arr[m-1].size(); j++) {
            dp[m-1][j] = arr[m-1][j];
        }

        for(int i=arr.size()-2; i>=0; i--) {
            for(int j=0; j<arr[i].size(); j++) {
                dp[i][j] = arr[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        dp.clear();
        dp.resize(205, vector<int>(205,INT_MIN));
        return f_bu(triangle);
    }
};

int main() {
    

    return 0;
}