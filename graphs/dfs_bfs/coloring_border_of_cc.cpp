#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m,n;
    vector<pair<int,int>> internals;
    void dfs(int i, int j, int initialColor, int color, vector<vector<int>>& grid) {
        if(i<0 || i>=m || j<0 || j>=n || initialColor != grid[i][j]) return;

        grid [i][j] = -color;
        dfs(i+1,j,initialColor,color,grid);
        dfs(i-1,j,initialColor,color,grid);
        dfs(i,j+1,initialColor,color,grid);
        dfs(i,j-1,initialColor,color,grid);

        if(!(i == 0 || j == 0 || i == m-1 || j == n-1 || grid[i+1][j] != -color || grid[i-1][j] != -color || grid[i][j+1] != -color || grid[i][j-1] != -color)) internals.push_back({i,j});
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        if(grid[row][col] == color) return grid;
        int initialColor = grid[row][col];

        dfs(row,col,initialColor,color,grid);

        for(auto p : internals) {
            int x = p.first;
            int y = p.second;

            grid[x][y] = initialColor;
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] < 0) grid[i][j] *= -1;
            }
        }
        
        return grid;
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
    int row, col, color;
    cin>>row>>col>>color;

    Solution s;
    grid = s.colorBorder(grid,row,col,color);

    for(auto v : grid) {
        for(auto ele : v) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}