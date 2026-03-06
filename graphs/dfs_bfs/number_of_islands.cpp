#include<iostream>
#include<vector>
#include<queue>
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

    int bfs(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cc = 0;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    cc++;
                    grid[i][j] = '0';
                    queue<pair<int,int>> q;
                    q.push({i,j});

                    while(!q.empty()) {
                        auto cell = q.front();
                        q.pop();

                        int x = cell.first;
                        int y = cell.second;

                        for(auto d : dir) {
                            int nx = x + d[0];
                            int ny = y + d[1];

                            if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny] == '0') continue;
                            grid[nx][ny] = '0';
                            q.push({nx,ny}); 
                        }
                    }
                }
            }
        }
        return cc;
    }

    int numIslands(vector<vector<char>>& grid) {
        // int count = 0;

        // for(int i=0; i<grid.size(); i++) {
        //     for(int j=0; j<grid[0].size(); j++) {
        //         if(grid[i][j] == '1') {
        //             dfs(grid,i,j);
        //             count++;
        //         }
        //     }
        // }
        // return count;
        return bfs(grid);
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