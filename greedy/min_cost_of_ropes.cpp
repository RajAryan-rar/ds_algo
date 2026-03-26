#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto ele : arr) pq.push(ele);
        int totalCost = 0;
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            totalCost += (a+b);
            pq.push(a+b);
        }
        return totalCost;
    }   
};

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    Solution s;
    cout<<s.minCost(arr)<<endl;

    return 0;
}