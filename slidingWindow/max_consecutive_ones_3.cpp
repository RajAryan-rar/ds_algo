#include<iostream>
#include<vector>
using namespace std;

class Solution {
public : 
    int longestOnes(vector<int> nums, int k) {
        int l = 0, r = 0, z = 0, maxLen = 0;

        while(r < nums.size()) {
            if(nums[r] == 0) z++;
            if(z <= k) maxLen = max(maxLen, r-l+1);

            else {
                while(nums[l] != 0) l++;
                l++;
                z--;
            }
            r++;
        }
        return maxLen;
    }
};

int main() {
    int n,k;
    cin>>n>>k;

    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    Solution s;
    cout<<s.longestOnes(nums,k);

    return 0;
}