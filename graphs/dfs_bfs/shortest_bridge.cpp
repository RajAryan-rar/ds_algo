#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int m,n;
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0 || grid[i][j] == 2) return;

        grid[i][j] = 2;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        bool break_out = false;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i,j,grid);
                    break_out = true;
                    break;
                }
            }
            if(break_out) break;
        }

        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>> dist(m,vector<int>(n,0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) q.push({i,j});
            }
        }

        while(!q.empty()) {
            auto cell = q.front();
            q.pop();

            int x = cell.first;
            int y = cell.second;

            for(auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny] == 2) continue;
                dist[nx][ny] = 1 + dist[x][y];
                if(grid[nx][ny] == 1) return dist[nx][ny]-1; 
                grid[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
        return 1;
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
    cout<<s.shortestBridge(grid);

    return 0;
}