#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> heights(m,vector<int>(n,-1));

        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isWater[i][j] == 1) { // 1 --> water
                    q.push({i,j});
                    heights[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            auto cell = q.front();
            q.pop();

            int x = cell.first;
            int y = cell.second;

            for(auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx<0 || nx>=m || ny<0 || ny>=n || heights[nx][ny] == 0|| heights[nx][ny] != -1) continue;

                heights[nx][ny] = 1 + heights[x][y];
                q.push({nx,ny});
            }
        }   
        return heights;

    }
};

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> isWater(m, vector<int>(n));    

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>isWater[i][j];
        }
    }

    Solution s;
    isWater = s.highestPeak(isWater);

    for(auto v : isWater) {
        for(auto ele : v) {
            cout<<ele<<" "; 
        }
        cout<<endl;
    }

    return 0;
}