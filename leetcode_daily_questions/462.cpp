#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int n = nums.size();
        auto mid_it = nums.begin() + n/2;
        nth_element(nums.begin(), mid_it, nums.end());

        int moves = 0;
        for(int i=0; i<n/2; i++) {
            moves += abs(nums[i] - *mid_it);
            moves += abs(nums[n-i-1] - *mid_it);
        }

        return moves;
    }
    /**
    * TC : O(n)
    * SC : O(1)
    */

    // also can sort the whole array and iterate the whole array -> simpler approach {TC -> O(nlogn)}
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution s;
    cout<<s.minMoves2(arr);

    return 0;
}