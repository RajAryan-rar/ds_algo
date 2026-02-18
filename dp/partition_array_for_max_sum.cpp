#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public :
    vector<int> arr;
    int K;
    vector<int> dp;

    int f(int i) {
        int n = arr.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = INT_MIN, maxEle = INT_MIN, len = 0;

        for(int j=i; j<min(n,i+K); j++) {
            len++;
            maxEle = max(maxEle, arr[j]);
            int sum = maxEle * len + f(j+1);
            ans = max(ans, sum);
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        arr = nums;
        K = k;
        dp.clear();
        dp.resize(arr.size()+1, -1);

        return f(0);
    }
};

int main() {
    int n,k;
    cin>>n>>k;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];

    Solution s;
    cout<<s.maxSumAfterPartitioning(nums,k);

    return 0;
}