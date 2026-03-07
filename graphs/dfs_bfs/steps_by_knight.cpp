#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        vector<vector<int>> dist(n+1, vector<int>(n+1,-1));
        int x1 = knightPos[0], y1 = knightPos[1];
        int x2 = targetPos[0], y2 = targetPos[1];
        
        if(x1 == x2 && y1 == y2) return 0;
        
        queue<pair<int,int>> q;
        q.push({x1,y1});
        dist[x1][y1] = 0;
        
        vector<vector<int>> dir = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
        
        
        while(!q.empty()) {
            auto cell = q.front();
            q.pop();
            
            int x = cell.first;
            int y = cell.second;
            
            for(auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                
                if(nx<=0 || nx>n || ny<=0 || ny>n || dist[nx][ny] != -1) continue;
                dist[nx][ny] = 1 + dist[x][y];
                if(nx == x2 && ny == y2) return dist[nx][ny];
                q.push({nx,ny});
            }
        }
        return dist[x2][y2];
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> knightPos(2), targetPos(2);
    cin>>knightPos[0]>>knightPos[1]>>targetPos[0]>>targetPos[1];

    Solution s;
    cout<<s.minStepToReachTarget(knightPos,targetPos,n);

    return 0;
}