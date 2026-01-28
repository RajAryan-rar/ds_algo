#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int nsi[n];
        int psi[n];

        stack<int> st;
        st.push(n-1);
        nsi[n-1] = n;
        for(int i=n-2; i>=0; i--) {
            //pop
            while(st.size()>0 && arr[st.top()]>=arr[i]) st.pop();
            //mark ans
            if(st.size() == 0) nsi[i] = n;
            else nsi[i] = st.top();
            //push
            st.push(i);
        }

        //stack empty kra
        stack<int> gt;

        psi[0] = -1;
        gt.push(0);
        for(int i=1; i<n; i++) {
            //pop
            while(gt.size()>0 && arr[gt.top()]>=arr[i]) gt.pop();
            //mark ans
            if(gt.size() == 0) psi[i] = -1;
            else psi[i] = gt.top();
            //push
            gt.push(i);
        }

        int maxArea = 0;
        for(int i=0; i<n; i++) {
            int height = arr[i];
            int width = nsi[i] - psi[i] - 1;
            int area = height * width;
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m,n;
        m = matrix.size();
        n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0; 
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;

    }
};

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<char>> matrix(m, vector<char>(n));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>matrix[i][j];
        }
    }

    Solution s;
    cout<<s.maximalRectangle(matrix);

    return 0;
}