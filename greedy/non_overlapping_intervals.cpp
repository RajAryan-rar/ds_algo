#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();

        int count = 0;
        int prevEnd = intervals[0][1];

        for(int i=1; i<n; i++) {
            if(intervals[i][0] < prevEnd) {
                count++;
            } else {
                prevEnd = max(prevEnd,intervals[i][1]);
            }
        }
        return count;
    }
};

int main() {
    int n;
    cin>>n;
    
    vector<vector<int>> intervals(n);
    for(int i=0; i<n; i++) {
        cin>>intervals[i][0]>>intervals[i][1];
    }

    Solution s;
    cout<<s.eraseOverlapIntervals(intervals);

    for(auto v : intervals) {
        for(auto ele : v) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}