#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> res;

        for(int i=0; i<k; i++) {
            while(!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(arr[dq.front()]);
        for(int i=k; i<arr.size(); i++) {
            int curr = arr[i];
            if(dq.front() == i-k) dq.pop_front();
            while(!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(arr[dq.front()]);
        }
        return res;
    }
};

int main() {
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    Solution s;

    vector<int> ans = s.maxSlidingWindow(arr,k);
    for(auto ele : ans) {
        cout<<ele<<" ";
    }


    return 0;
}