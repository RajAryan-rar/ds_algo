#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int k) {
        if(k<=0) return 0;
        int count = 0, l = 0, r = 0;
        unordered_map<int,int> mp;

        while(r < nums.size()) {
            mp[nums[r]]++;
            while(mp.size() > k) {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k) {
        return f(nums,k) - f(nums,k-1);
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
    cout<<s.subarraysWithKDistinct(nums,k);

    return 0;
}