#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> x(m,vector<int>(n));
        vector<vector<int>> y(m,vector<int>(n));
        
        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                char ch = grid[i][j];

                x[i][j] = (ch == 'X');
                y[i][j] = (ch == 'Y');

                if(i > 0) {
                    x[i][j] += x[i-1][j];
                    y[i][j] += y[i-1][j];
                } 
                if(j > 0) {
                    x[i][j] += x[i][j-1];
                    y[i][j] += y[i][j-1];
                } 
                if(i > 0 && j > 0) {
                    x[i][j] -= x[i-1][j-1];
                    y[i][j] -= y[i-1][j-1];
                } 
                if(x[i][j] > 0 && x[i][j] == y[i][j]) ans++;
            }
        }
        return ans;
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
    cout<<s.numberOfSubmatrices(grid);

    return 0;
}