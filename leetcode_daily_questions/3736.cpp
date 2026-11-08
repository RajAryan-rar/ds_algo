#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxEle = nums[0], sum = 0;

        for(int ele : nums) {
            maxEle = max(maxEle,ele);
            sum += ele;
        }

        return maxEle * n - sum;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0; i<n; i++) cin>>nums[i];

    Solution s;
    int ans = s.minMoves(nums);

    cout<<ans;

    return 0;
}