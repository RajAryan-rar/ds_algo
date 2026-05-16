#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosestBrute(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = INT_MAX;
        int result = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(abs(target-sum ) < diff) {
                        result = sum;
                        diff = abs(target-sum);
                    }
                }
            }
        }
        return result;
    }
    
    int threeSumClosestOptimal(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int closest = nums[0]+nums[1]+nums[2];

        for(int i=0; i<n; i++) {

            int j = i+1;
            int k = n-1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-target) < abs(closest-target)) {
                    closest = sum;
                }
                if(sum < target) {
                    j++;
                } else if(sum > target) {
                    k--;
                } else return sum;
            }
        }
        return closest;
    }
};

int main() {
    int n,target;
    cin>>n>>target;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];

    Solution s;
    cout<<s.threeSumClosestOptimal(nums,target);

    return 0;
}