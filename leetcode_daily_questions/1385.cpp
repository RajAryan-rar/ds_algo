#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findTheDistanceValueBruteForce(vector<int>& arr1, vector<int>& arr2, int d) {
        /**
         * TC -> O(m*n)
         */
        int count = 0;
        for(int i=0; i<arr1.size(); i++) {
            int x = arr1[i];
            bool flag = true;
            for(int j=0; j<arr2.size(); j++) {
                int y = arr2[j];
                if(abs(x-y) <= d) {
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        /**
         * TC -> O(n+m) logm
         */
        int n = arr1.size(), m = arr2.size();

        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for (int i=0; i<n; i++) {
            int ele = arr1[i];

            int lo = 0, hi = m-1;
            bool flag = true;
            while(lo <= hi) {
                int mid = lo + (hi-lo) / 2;
                
                if(arr2[mid] > ele + d) hi = mid-1;
                else if(arr2[mid] < ele - d) lo = mid+1;
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }

};

int main() {
    int n, m, d;
    cin>>n>>m>>d;
    vector<int> arr1(n), arr2(m);

    for(int i=0; i<n; i++) cin>>arr1[i];
    for(int i=0; i<m; i++) cin>>arr2[i];

    Solution s;
    
    cout<<s.findTheDistanceValue(arr1, arr2, d);

    return 0;
}