#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] > result[result.size()-1][1]) {
                result.push_back(intervals[i]);
            } else {
                result[result.size()-1][1] = max(result[result.size()-1][1],intervals[i][1]);
            }
        }
        return result;
    }
};

int main() {
    int n;
    cin>>n;
    vector<vector<int>> intervals(n, vector<int>(2));

    for(int i=0; i<n; i++) cin>>intervals[i][0]>>intervals[i][1];

    vector<int> newInterval(2);
    cin>>newInterval[0]>>newInterval[1];

    Solution s;
    intervals = s.insert(intervals,newInterval);

    for(auto v : intervals) {
        for(auto ele : v) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}