#include<iostream>
#include<vector>
using namespace std;

#define mod 12345
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int size = m * n;

        vector<long long> prefix(size,1), suffix(size,1);

        for(int i=1; i<size; i++) {
            int r = (i-1)/n;
            int c = (i-1)%n;
            prefix[i] = (prefix[i-1]%mod * grid[r][c]%mod)%mod;
        }
        for(int i=size-2; i>=0; i--) {
            int r = (i+1)/n;
            int c = (i+1)%n;
            suffix[i] = (suffix[i+1]%mod * grid[r][c]%mod)%mod;
        }

        vector<vector<int>> result(m, vector<int>(n));
        for(int i=0; i<size; i++) {
            int r = i/n;
            int c = i%n;
            result[r][c] = (prefix[i]%mod * suffix[i]%mod)%mod;
        }
        return result;
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
    grid = s.constructProductMatrix(grid);

    for(auto v : grid) {
        for(auto ele : v) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}