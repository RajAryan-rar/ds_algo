#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int& p) {
        if(r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0 || grid[r][c] == 0) {
            p++;
            return;
        } 
        if(grid[r][c] == -1) return;
        grid[r][c] = -1;
        dfs(grid,r+1,c,p);
        dfs(grid,r-1,c,p);
        dfs(grid,r,c+1,p);
        dfs(grid,r,c-1,p);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    dfs(grid,i,j,perimeter);
                }
            }
        }
        return perimeter;
        
    }
};

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<int>> grid(m,vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid[i][j];
        }
    }
    Solution s;
    cout<<s.islandPerimeter(grid);

    return 0;
}