#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> arr;
    vector<vector<int>> dp;

    int f(int i, int j) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MIN;
        for(int k=i; k<=j; k++) {
            ans = max(ans, f(i,k-1) + f(k+1,j) + arr[i-1]*arr[k]*arr[j+1]);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        arr = nums;
        arr.insert(arr.begin(),1);
        arr.push_back(1);

        dp.clear();
        dp.resize(arr.size()+1, vector<int>(arr.size()+1, -1));
        return f(1,arr.size()-2);

    }
};

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];

    Solution s;
    cout<<s.maxCoins(nums);


    return 0;
}