#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m,n;
    void dfs(int i, int j, vector<vector<char>>& board) {
        if(i<0 || i>=m || j<0 || j>=n ||
        board[i][j] == '.' || board[i][j] == '0') return;
        board[i][j] = '0';
        dfs(i+1,j,board); 
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }

    int countBattleships(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        int result = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'X') {
                    result++;
                    dfs(i,j,board);
                }
            }
        }
        return result;
    }
};

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<char>> board(m, vector<char>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>board[i][j];
        }
    }
    Solution s;
    cout<<s.countBattleships(board);

    return 0;
}