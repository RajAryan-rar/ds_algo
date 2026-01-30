#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        queue<int> q;
        for(int i=0; i<arr.size(); i++) q.push(i);

        int time = 0;

        while(arr[k] != 0) {
            int idx = q.front();
            if(arr[idx] == 0) {
                q.pop();
                continue;
            }
            arr[idx]--;
            time++;
            q.pop();
            q.push(idx);
        }
        return time;
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
    cout<<s.timeRequiredToBuy(arr,k);


    return 0;
}