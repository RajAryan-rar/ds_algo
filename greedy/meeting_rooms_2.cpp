#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int ans = 0, rooms = 0;
        int i = 0, j = 0;
        
        while(i<start.size()) {
            if(start[i] < end[j]) {
                rooms++;
                i++;
            } 
            else {
                rooms--;
                j++;
            }
            ans = max(ans,rooms);
        }
        return ans;
    }
};


int main() {
    int n;
    cin>>n;

    vector<int> start(n), end(n);
    for(int i=0; i<n; i++) {
        cin>>start[i]>>end[i];
    }

    Solution s;
    cout<<s.minMeetingRooms(start,end);

    return 0;
}