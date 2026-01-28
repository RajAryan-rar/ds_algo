#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /*
        Brute Force
        TC: O(n*n) 
    */
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i<n; i++) {
            int smallest = nums[i];
            int largest = nums[i];
            for(int j=i+1; j<n; j++) {
                smallest = min(smallest,nums[j]);
                largest = max(largest,nums[j]);
                sum += (largest - smallest);
            }
        }
        return sum;
    }

    /*
        Optimized Approach
        TC: O(4*n) i.e O(n)

        // return sum_of_subarray_max - sum_of_subarray_min
    */
    

};

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    Solution s;
    cout<<s.subArrayRanges(arr);

    return 0;
}