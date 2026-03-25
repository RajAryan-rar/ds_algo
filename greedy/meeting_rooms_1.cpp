#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        int n = arr.size();
        vector<int> start(n), end(n);
        
        for(int i=0; i<n; i++) {
            start[i] = arr[i][0];
            end[i] = arr[i][1];
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i=0, j=0;
        int overlap = 0, counter = 0;
        
        while(i < start.size()) {
            if(start[i] < end[j]) {
                counter++;
                overlap = max(overlap,counter);
                if(overlap > 1) return false;
                i++;
            } else {
                counter--;
                j++;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cin>>n;
    
    vector<vector<int>> arr(n, vector<int>(2));

    for(int i=0; i<n; i++) {
        cin>>arr[i][0]>>arr[i][1];
    }
    Solution s;
    if(s.canAttend(arr)) cout<<"True\n";
    else cout<<"False\n";

    return 0;
}