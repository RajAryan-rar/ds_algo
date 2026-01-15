#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    vector<int> arr;
    int f(int x) {
        if(x < 0) return 0;
        if(x == 0) return 1;
        if(dp[x] != -1) return dp[x];

        int ans = 0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] > x) continue;
            else dp[x] = ans += f(x-arr[i]); 
        }
        return dp[x] = ans;
    }

    int f_bu(int givenTarget) {
        for(int target=0; target<=givenTarget; target++) {
            if(target == 0) dp[target] = 1;
            
            else {
                long long int ans = 0;
                for(int i=0; i<arr.size(); i++) {
                    if(arr[i] > target) continue;
                    ans += dp[target-arr[i]]; 
                }
                dp[target] = (int)ans;
            }
        }
        return dp[givenTarget];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        arr = nums;
        dp.clear();
        dp.resize(1005, -1);
        return f(target);
    }
};

int main() {
    

    return 0;
}