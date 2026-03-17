#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for(int i=1; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] > 0) matrix[i][j] += matrix[i-1][j];
            }
        }

        int maxArea = 0;
        for(int i=0; i<m; i++) {
            vector<int> heights = matrix[i];
            sort(heights.begin(), heights.end(), greater<int>());
            for(int j=0; j<n; j++) {
                int height = heights[j];
                int width = j+1;
                if(heights[j] == 0) break;
                maxArea = max(maxArea, height * width);
            }
        }
        return maxArea;
    }
};

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>matrix[i][j];
        }
    }

    Solution s;
    cout<<s.largestSubmatrix(matrix);

    return 0;
}