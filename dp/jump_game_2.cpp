#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define inf INT_MAX
class Solution {
public:
    vector<int> arr;
    vector<int> dp;
    int f(int i) {
        if(i >= arr.size()-1) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = inf;
        for(int j=1; j<=arr[i]; j++) {
            if(i+j < arr.size()) {
                int next = f(i+j);
                if(next != inf) {
                    mini = min(mini, 1+next);
                }
            }
            
        }
        return dp[i] = mini;
    }

    int jump(vector<int>& nums) {
        arr = nums;
        dp.resize(nums.size()+1,-1);
        return f(0);
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];

    Solution s;
    cout<<s.jump(nums)<<endl;

    return 0;
}