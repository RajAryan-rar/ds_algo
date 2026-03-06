#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int m,n;
    vector<vector<int>> h;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    vector<vector<bool>> bfs(queue<pair<int,int>>& q) {
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        while(!q.empty()) {
            auto cell = q.front();
            q.pop();

            int x = cell.first;
            int y = cell.second;
            visited[x][y] = true;

            for(auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx<0 || ny<0 || nx>=m || ny>=n || h[nx][ny]<h[x][y]
                || visited[nx][ny] == true) continue;

                q.push({nx,ny});
            }
        }
        return visited;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        h = heights;
        m = h.size(), n = h[0].size();

        queue<pair<int,int>> pacificBfs;
        queue<pair<int,int>> atlanticBfs;

        for(int i=0; i<m; i++) {
            pacificBfs.push({i,0});
            atlanticBfs.push({i,n-1});
        }
        for(int j=1; j<n; j++) {
            pacificBfs.push({0,j});
        }
        for(int j=0; j<n-1; j++) {
            atlanticBfs.push({m-1,j});
        }

        vector<vector<bool>> pacific = bfs(pacificBfs);
        vector<vector<bool>> atlantic = bfs(atlanticBfs);

        vector<vector<int>> result;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i,j});
            }
        }
        return result;
    }
};

int main() {
    int m,n;
    cin>>m>>n;
    
    vector<vector<int>> heights(m, vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>heights[i][j];
        }
    }
    Solution s;
    heights = s.pacificAtlantic(heights);

    for(auto v : heights) {
        for(auto ele : v) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}