#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<vector<int>> intervals(n, vector<int>(2));
        for(int i=0; i<n; i++) {
            intervals[i][0] = start[i];
            intervals[i][1] = end[i];
        }
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        int prevEnd = intervals[0][1];
        int ans = 1;
        
        for(int i=1; i<n; i++) {
            if(intervals[i][0] > prevEnd) {
                ans++;
                prevEnd = intervals[i][1];
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> start(n), end(n);

    for(int i=0; i<n; i++) cin>>start[i];
    for(int i=0; i<n; i++) cin>>end[i];

    Solution s;
    cout<<s.maxMeetings(start,end)<<endl;

    return 0;
}