#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

#define inf INT_MAX
/**
 * Solved using 0-1 BFS
 */
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dist[m][n];

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                dist[i][j] = inf;
            }
        }

        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        dist[0][0] = 0;
                //   R L D U
        int dx[4] = {0,0,1,-1}; //this ordering matters in my implementation
        int dy[4] = {1,-1,0,0};

        while(!dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();
            int x = curr.first;
            int y = curr.second;

            int dir = grid[x][y];

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                int edgeWt = 1;
                if(i+1 == dir) edgeWt = 0;

                if(nx>=0 && ny>=0 && nx<m && ny<n) {
                    if(dist[nx][ny] > dist[x][y] + edgeWt) {
                        dist[nx][ny] = dist[x][y] + edgeWt;
                        if(edgeWt == 1) dq.push_back({nx,ny});
                        else dq.push_front({nx,ny});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};

int main() {
    int m,n;
    vector<vector<int>> grid(m, vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid[i][j];
        }
    }

    Solution s;
    cout<<s.minCost(grid)<<endl;

    return 0;
}