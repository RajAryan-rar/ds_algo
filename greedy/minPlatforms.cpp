#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int ans = 0, overlaps = 0;
        int i=0, j=0;
        while(i < n) {
            if(arr[i] <= dep[j]) {
                overlaps++;
                ans = max(ans,overlaps);
                i++;
            } else {
                overlaps--;
                j++;
            }
        }
        return ans;
        
    }
};


int main() {
    int n;
    cin>>n;
    vector<int> arr(n), dep(n);
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++) {
        cin>>dep[i];
    }

    Solution s;
    cout<<s.minPlatform(arr,dep)<<endl;

    return 0;
}