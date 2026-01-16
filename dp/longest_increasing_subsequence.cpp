#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> dp;

int f(vector<int> &nums, int i) {
    if (i == nums.size()) return INT_MIN;
    if (dp[i] != -1) return dp[i];

    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
            dp[i] = ans = max(ans, 1 + f(nums, j));
        }
    }
    return dp[i] = ans;
}

int f_bu(vector<int>& nums) {
    dp[0] = 1;

    for(int i=1; i<nums.size(); i++) {
        int ans = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                ans = max(ans, 1 + dp[j]);
            }
        }
        dp[i] = ans;
    }
    
    int mx = INT_MIN;
    for(int i=0; i<dp.size(); i++) {
        mx = max(mx, dp[i]);
    }
    return mx;
}

int lengthOfLIS(vector<int> &nums) {
    dp.clear();
    dp.resize(nums.size() + 1, -1);
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        ans = max(ans, f(nums, i));
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        v[i] = x;
    }

    cout<<lengthOfLIS(v);

    return 0;
}