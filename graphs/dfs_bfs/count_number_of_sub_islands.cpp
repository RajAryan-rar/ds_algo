#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c) {
        if(r<0 || c<0 || r>=grid2.size() || c>=grid2[0].size() || grid2[r][c] != 1) return true;

        grid2[r][c] = -1;

        bool isSubIsland = true;
        if(grid1[r][c] != 1) isSubIsland = false;

        bool d1 = dfs(grid1,grid2,r+1,c);
        bool d2 = dfs(grid1,grid2,r-1,c);
        bool d3 = dfs(grid1,grid2,r,c+1);
        bool d4 = dfs(grid1,grid2,r,c-1);

        return isSubIsland && d1 && d2 && d3 && d4;

    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();

        int count = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid2[i][j] == 1) {
                    if(dfs(grid1,grid2,i,j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<int>> grid1(m,vector<int>(n));
    vector<vector<int>> grid2(m,vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid1[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid1[i][j];
        }
    }
    Solution s;
    cout<<s.countSubIslands(grid1,grid2);

    return 0;
}