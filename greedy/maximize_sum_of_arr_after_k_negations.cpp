#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations_method_1(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0; i<n && k>0; i++) {
            if(nums[i] < 0) {
                nums[i] *= -1;
                k--;
            }
        }
        sort(nums.begin(),nums.end());
        if(k%2 == 1) nums[0] *= -1;

        int sum = 0;
        for(auto ele : nums) sum += ele;
        return sum;
    }  

    int largestSumAfterKNegations_method_2(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
        }

        while(k > 0) {
            int ele = pq.top();
            pq.pop();
            ele *= -1;
            k--;
            pq.push(ele);
        }
        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }  
};

int main() {
    int n, k;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    Solution s;
    cout<<s.largestSumAfterKNegations_method_1(nums,k)<<endl;
    cout<<s.largestSumAfterKNegations_method_2(nums,k)<<endl;

    return 0;
}