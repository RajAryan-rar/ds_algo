#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0, l = 0, r = 0, jumps = 0;

        while(r < n-1) {
            int farthest = 0;

            for(int i=l; i<=r && i<n; i++) {
                farthest = max(farthest, i+nums[i]);
            }
            jumps++;
            l = r+1;
            r = farthest;
        }
        return jumps;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=0; i<n ;i++) cin>>nums[i];

    Solution s;
    cout<<s.jump(nums);

    return 0;
}