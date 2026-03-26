#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);

        int count = 1;
        int prevEnd = points[0][1];

        for(int i=1; i<points.size(); i++) {
            if(points[i][0] <= prevEnd) {
                continue;
            } else {
                count++;
                prevEnd = points[i][1];
            }
        }
        return count;
    }
};

int main() {
    int n;
    cin>>n;
    vector<vector<int>> points(n, vector<int>(2));
    
    for(int i=0; i<n; i++) {
        cin>>points[i][0]>>points[i][1];
    }
    Solution s;
    cout<<s.findMinArrowShots(points)<<"\n";

    return 0;
}