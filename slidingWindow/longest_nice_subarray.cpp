#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 1, maxLen = 1, usedBits = nums[0];

        while(r < nums.size()) {
            while((usedBits & nums[r]) != 0) {
                usedBits ^= nums[l];
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            usedBits |= nums[r];
            r++;
        }
        return maxLen;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    Solution s;
    cout<<s.longestNiceSubarray(nums);

    return 0;
}