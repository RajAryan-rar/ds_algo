#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0, minEle = nums[0];
        for(int ele : nums) minEle = min(minEle, ele);
        for(int i=0; i<nums.size(); i++) {
            moves += (nums[i] - minEle);
        }      
        return moves;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0; i<n; i++) cin>>nums[i];

    Solution s;
    cout<<s.minMoves(nums);


    return 0;
}