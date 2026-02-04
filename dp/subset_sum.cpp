#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> arr;
    vector<vector<int>> dp;
    bool f(int i, int target) {
        if(target == 0) return true;
        if(i >= arr.size() || target < 0) return false;
        if(dp[i][target] != -1) return dp[i][target];
        
        bool not_take = f(i+1,target);
        bool take = false;
        if(arr[i] <= target) {
            take = f(i+1,target-arr[i]);
        }
        
        return dp[i][target] = take || not_take;
        
    }
    bool isSubsetSum(vector<int>& v, int sum) {
        arr = v;
        dp.clear();
        dp.resize(205, vector<int>(10005,-1));
        return f(0,sum);
        
    }
};

int main() {
    int sum,n;
    cin>>sum>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    Solution s;
    bool ans = s.isSubsetSum(arr,sum);

    if(ans) cout<<"true";
    else cout<<"false";

    return 0;
}