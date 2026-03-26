#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<vector<int>> intervals(n, vector<int>(2));
        
        for(int i=0; i<n; i++) {
            intervals[i][0] = start[i];
            intervals[i][1] = finish[i];
        }
        sort(intervals.begin(), intervals.end(), cmp);
        
        int count = 0;
        int prevEnd = intervals[0][1];
        
        for(int i=1; i<n; i++) {
            if(intervals[i][0] <= prevEnd) {
                count++;
            } else {
                prevEnd = intervals[i][1];
            }
        }
        return n-count;
    }
};

int main() {
    int n;
    cin>>n;
    
    vector<int> start(n), finish(n);
    for(int i=0; i<n; i++) cin>>start[i]>>finish[i];

    Solution s;
    cout<<s.activitySelection(start,finish);

    return 0;
}