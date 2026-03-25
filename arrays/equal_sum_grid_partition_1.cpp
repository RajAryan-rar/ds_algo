#include<iostream>
#include<vector>
using namespace std;

#define ll long long int
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<ll> rowSum(m,0);
        vector<ll> colSum(n,0);
        ll totalSum = 0;

        for(int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                totalSum += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        long long rSum = 0, cSum = 0;
        for(int i=0; i<m; i++) {
            rSum += rowSum[i];
            if(rSum == totalSum-rSum) return true;
        }
        for(int j=0; j<n; j++) {
            cSum += colSum[j];
            if(cSum == totalSum-cSum) return true;
        }
        return false;
    }
};

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<int>> grid(m, vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid[i][j];
        }
    }
    Solution s;
    if(s.canPartitionGrid(grid)) cout<<"True"<<"\n";
    else cout<<"False"<<"\n";

    return 0;
}