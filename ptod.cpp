#include<iostream>
using namespace std;
#include<vector>

#define mod 1000000007
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0; i<queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];

            while(l <= r) {
                nums[l] = (nums[l]%mod * v%mod)%mod;
                l += k;
            }
        }

        int ans = 0;

        for(int ele : nums) ans ^= ele;
        return ans;
    }
};

int main() {
    

    return 0;
}