#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, maxScore = 0, score = 0;
        unordered_map<int,int> mp;

        while(r < nums.size()) {
            mp[nums[r]]++;
            score += nums[r];
            while(mp[nums[r]] > 1) {
                score -= nums[l];
                mp[nums[l]]--;
                l++;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
            }
            maxScore = max(maxScore, score);
            r++;
        }
        return maxScore;
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
    cout<<s.maximumUniqueSubarray(nums);

    return 0;
}
