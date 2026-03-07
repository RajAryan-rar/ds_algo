#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int m,n;
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0 || grid[i][j] == 2) return;
        grid[i][j] = 2; //2 --> we can walk off the boundary from this land cell
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }

    int bfs(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            if(grid[i][0] == 1) {
                grid[i][0] = 2;
                q.push({i,0});
            }
            if(grid[i][n-1] == 1) {
                grid[i][n-1] = 2;
                q.push({i,n-1});
            }
        }
        for(int j=1; j<n-1; j++) {
            if(grid[0][j] == 1) {
                grid[0][j] = 2;
                q.push({0,j});
            }
            if(grid[m-1][j] == 1) {
                grid[m-1][j] = 2;
                q.push({m-1,j});
            }
        }

        while(!q.empty()) {
            auto cell = q.front();
            q.pop();
            
            int x = cell.first;
            int y = cell.second;

            vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
            for(auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny] == 0 || grid[nx][ny] == 2) continue;

                grid[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
        int result = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) result++;
            }
        }
        return result;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        //METHOD - 1 : By DFS
        // for(int i=0; i<m; i++) {
        //     if(grid[i][0] == 1) dfs(i,0,grid);
        //     if(grid[i][n-1] == 1) dfs(i,n-1,grid);
        // }
        // for(int j=1; j<n-1; j++) {
        //     if(grid[0][j] == 1) dfs(0,j,grid);
        //     if(grid[m-1][j] == 1) dfs(m-1,j,grid);
        // }

        // int result = 0;
        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(grid[i][j] == 1) result++;
        //     }
        // }
        // return result;

        //METHOD - 2 : By BFS
        return bfs(grid);
    }
};

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid[i][j];
        }
    }

    Solution s;
    cout<<s.numEnclaves(grid);

    return 0;
}