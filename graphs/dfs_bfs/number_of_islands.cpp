#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == '0' || grid[i][j] == '2') return;

        grid[i][j] = '2';
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<char>> grid(m, vector<char>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid[i][j];
        }
    }
    Solution s;
    cout<<s.numIslands(grid);

    return 0;
}