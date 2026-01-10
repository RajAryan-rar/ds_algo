#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
//memoization / top-down
int f(vector<int>& nums, int i) { //[1,11,9,5,10] -> 21
    if(i >= nums.size()) return 0;

    return max(nums[i] + f(nums,i+2), f(nums,i+1));
}

//tabulation just lc submission
int g(vector<int>& nums, int i) {
    if(nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0],nums[1]);
        vector<int> dp(nums.size()+1);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[nums.size()-1];
}

int main() {
    dp.clear();
    dp.resize(105,-1);

    vector<int> arr = {1,11,9,5,10};
    cout<<f(arr,0);

    return 0;
}