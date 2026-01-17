#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    vector<int> arr;
    vector<int> dp;
    int f(int i) {
        if(i < 2) return 0;
        if(arr[i] - arr[i-1] != arr[i-1] - arr[i-2]) return 0;
        if(dp[i] != INT_MIN) return dp[i];
        return dp[i] =  1 + f(i-1);
    }
    int f_bu() {
        dp.clear();
        dp.resize(arr.size(),0);
        int count = 0;
        for(int i=2; i<arr.size(); i++) {
            if(arr[i] - arr[i-1] != arr[i-1] - arr[i-2]) dp[i] = 0;
            else dp[i] = 1 + dp[i-1];
            count += dp[i];
        }
        return count;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        arr = nums;
        dp.clear();
        dp.resize(5005, INT_MIN);
        int ans = 0;
        for(int i=2; i<nums.size(); i++) {
            ans += f(i);
        }
        return ans;

        //return f_bu();
    }
};

int main() {
    

    return 0;
}