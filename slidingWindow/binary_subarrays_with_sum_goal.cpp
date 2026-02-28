#include<iostream>
#include<vector>
using namespace std;

class Solution {
public: 
    int f(vector<int> &nums, int goal) {
        if(goal < 0) return 0;
        int sum = 0, count = 0, l = 0, r = 0;

        while(r < nums.size()) {
            sum += nums[r];
            while(sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int> &nums, int goal) {
        return f(nums,goal) - f(nums,goal-1);
    }
};

int main() {
    int n,goal;
    cin>>n>>goal;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    Solution s;
    cout<<s.numSubarraysWithSum(nums,goal);


    return 0;
}