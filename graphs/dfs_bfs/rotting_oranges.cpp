#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fo = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) fo++;
                else if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});

        int mins = 0;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            auto cell = q.front();
            q.pop();

            int x = cell.first;
            int y = cell.second;

            if(x == -1 && y == -1) {
                mins++;
                if(q.size() > 0) {
                    q.push({-1,-1});
                }
            }
            else {
                for(auto d : dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 0 || grid[nx][ny] == 2) continue;
                    fo--;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }   
        }
        return (fo == 0) ? mins-1 : -1;
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
    cout<<s.orangesRotting(grid);

    return 0;
}