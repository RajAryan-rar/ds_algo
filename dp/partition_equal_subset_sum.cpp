#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> arr;
    vector<vector<int>> dp;
    bool f(int i, int sum, int target) {
        if(i == arr.size() || sum > target) return false;
        if(sum == target) return true;
        if(dp[i][sum] != -1) return dp[i][sum];

        else {
            return dp[i][sum] = f(i+1,sum+arr[i],target) || f(i+1,sum,target);
        }
    }

    bool canPartition(vector<int>& nums) {
        arr = nums;
        int totalSum = 0;
        for(auto ele : nums) totalSum += ele;
        if(totalSum % 2 != 0) return false;
        int target = totalSum/2;

        dp.clear();
        dp.resize(205, vector<int>(10005,-1));
        return f(0,0,target);

    }
};

int main() {
    int n;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    Solution s;
    cout<<s.canPartition(nums);

    return 0;
}