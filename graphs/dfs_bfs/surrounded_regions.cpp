#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    // vector<vector<bool>> visited;
    int m,n;

    void dfs(int i, int j, vector<vector<char>>& board) {
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] == '1' || board[i][j] == 'X') return;
        board[i][j] = '1';
        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }

    void bfs(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O') {
                q.push({i,0});
                board[i][0] = '1';
            }
            if(board[i][n-1] == 'O') {
                q.push({i,n-1});
                board[i][n-1] = '1';
            }
        }
        for(int j=1; j<n-1; j++) {
            if(board[0][j] == 'O') {
                q.push({0,j});
                board[0][j] = '1';
            }
            if(board[m-1][j] == 'O') {
                q.push({m-1,j});
                board[m-1][j] = '1';
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
                if(nx<0 || nx>=m || ny<0 || ny>=n || board[nx][ny] == '1' || board[nx][ny] == 'X') continue;

                board[nx][ny] = '1';
                q.push({nx,ny});
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        // visited.resize(m, vector<bool>(n,false));

        //METHOD - 1 : (By DFS)

        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O') dfs(i,0,board);
            if(board[i][n-1] == 'O') dfs(i,n-1,board);
        }
        for(int j=1; j<n-1; j++) {
            if(board[0][j] == 'O') dfs(0,j,board);
            if(board[m-1][j] == 'O') dfs(m-1,j,board);
        }

        // bfs(board);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '1') board[i][j] = 'O';
            }
        }
        return;
    }
};

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<char>> board(m,vector<char>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>board[i][j];
        }
    }

    Solution s;
    s.solve(board);

    for(auto v : board) {
        for(auto ele : v) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}