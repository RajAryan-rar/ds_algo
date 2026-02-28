#include<iostream>
#include<vector>
using namespace std;

class Solution {
public :
    int f(vector<int> &nums, int k) {
        if(k < 0) return 0;
        int sum = 0, count = 0, l = 0, r = 0;

        while(r < nums.size()) {
            if(nums[r] % 2 != 0) count++;
            while(count > k) {
                if(nums[l] % 2 == 0) l++;
                else {
                    count--;
                    l++;
                }
            }
            sum += (r-l+1);
            r++;
        }
        return sum;
    }

    int numberOfSubarrays(vector<int> &nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};

int main() {
    int n,k;
    cin>>n>>k;

    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    Solution s;
    cout<<s.numberOfSubarrays(nums,k);


    return 0;
}