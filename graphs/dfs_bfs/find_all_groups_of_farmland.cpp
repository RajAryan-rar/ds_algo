#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& land, int r, int c, int& brx, int & bry) {
        int m = land.size();
        int n = land[0].size();
        if(r < 0 || c < 0 || r >= m || c >= n || land[r][c] == 0) return;
        land[r][c] = 0;
        brx = max(brx,r);
        bry = max(bry,c);

        dfs(land,r+1,c,brx,bry);
        dfs(land,r-1,c,brx,bry);
        dfs(land,r,c+1,brx,bry);
        dfs(land,r,c-1,brx,bry);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> result;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(land[i][j] == 1) {
                    int brx = -1, bry = -1;
                    dfs(land,i,j,brx,bry);
                    result.push_back({i,j,brx,bry});
                }
            }
        }
        return result;
    }
};

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<int>> grid(m,vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid[i][j];
        }
    }
    Solution s;
    grid = s.findFarmland(grid);

    for(auto v : grid) {
        for(auto ele : v) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }


    return 0;
}