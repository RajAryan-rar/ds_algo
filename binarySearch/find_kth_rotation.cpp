#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int lo = 0, hi = arr.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] > arr[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};


int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    Solution s;
    cout<<s.findKRotation(arr);

    return 0;
}