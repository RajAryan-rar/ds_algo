#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            bool flag = false;
            for(int j=0; j<nums[i]; j++) {
                if((j | j+1) == nums[i]) {
                    result.push_back(j);
                    flag = true;
                    break;
                }
            }
            if(!flag) result.push_back(-1);
        }
        return result;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        v[i] = x;
    }

    Solution s;
    vector<int> ans = s.minBitwiseArray(v);

    for(auto ele : ans) cout<<ele<<" ";

    return 0;
}