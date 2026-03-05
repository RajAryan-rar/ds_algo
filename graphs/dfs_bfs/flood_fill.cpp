#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int m,n;
    void dfs(int i, int j, int initialColor, int color ,vector<vector<int>> &arr) {
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(initialColor != arr[i][j]) return;

        arr[i][j] = color;

        dfs(i+1,j,initialColor,color,arr);
        dfs(i-1,j,initialColor,color,arr);
        dfs(i,j+1,initialColor,color,arr);
        dfs(i,j-1,initialColor,color,arr);
    }

    vector<vector<int>> bfs(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        int originalColor = image[sr][sc];
        
        if(originalColor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            for(auto dir : directions) {
                int nx = curr.first + dir[0];
                int ny = curr.second + dir[1];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(image[nx][ny] != originalColor) continue;

                image[nx][ny] = color;
                q.push({nx,ny});
            }
        }
        return image;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        if(image[sr][sc] == color) return image;
        // dfs(sr,sc,image[sr][sc],color,image);
        return bfs(image,sr,sc,color);
    }
};

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<int>> image(m, vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>image[i][j];
        }
    }
    int sr,sc,color;
    cin>>sr>>sc>>color;

    Solution s;
    image = s.floodFill(image,sr,sc,color);

    for(auto v : image) {
        for(auto ele : v) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}