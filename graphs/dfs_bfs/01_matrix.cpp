#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> result(m, vector<int> (n,-1));
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    result[i][j] = 0;
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

                if(nx<0 || ny<0 || nx>=m || ny>=n || result[nx][ny] != -1) continue;
                result[nx][ny] = result[x][y] + 1;
                q.push({nx,ny});

            }
        }
        return result;
    }
};

int main() {
    int m,n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>mat[i][j];
        }
    }  

    Solution s;
    mat = s.updateMatrix(mat);

    for(auto v : mat) {
        for(auto ele : v) {
            cout<<ele<<" "; 
        }
        cout<<endl;
    }

    return 0;
}