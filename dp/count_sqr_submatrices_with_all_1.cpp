#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));

        int count = 0;
        for(int j=0; j<n; j++) {
            dp[0][j] = arr[0][j];
            count += dp[0][j];
        }
        for(int i=1; i<m; i++) {
            dp[i][0] = arr[i][0];
            count += dp[i][0];
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(arr[i][j] == 0) dp[i][j] = 0;
                else {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<int>> matrix(m,vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>matrix[i][j];
        }
    }

    Solution s;
    cout<<s.countSquares(matrix);

    return 0;
}