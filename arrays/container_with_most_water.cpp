#include<iostream>
#include<vector>
using namespace std;

class Solution {
public :
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int maxArea = 0;

        while(i < j) {
            int l = min(height[i], height[j]);
            int b = j-i;
            int currArea = l * b;
            maxArea = max(maxArea, currArea);

            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> height(n);
    for(int i=0; i<n; i++) cin>>height[i];
    
    Solution s;
    cout<<s.maxArea(height);

    return 0;
}