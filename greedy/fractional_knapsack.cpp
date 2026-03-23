#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b) {
        double r1 = (double)a.first*1.0 / a.second;
        double r2 = (double)b.first*1.0 / b.second;
        return r1 > r2;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int cap) {
        vector<pair<int,int>> arr;
        for(int i=0; i<val.size(); i++) {
            pair<int,int> p = {val[i],wt[i]};
            arr.push_back(p);
        }
        double maxProfit = 0;
        sort(arr.begin(),arr.end(),cmp);
        for(int i=0; i<val.size(); i++) {
            pair<int,int> p = arr[i];
            int currVal = p.first;
            int currWt = p.second;
            if(currWt <= cap) {
                maxProfit += currVal;
                cap -= currWt;
            }
            else {
                double r = currVal / (currWt * 1.0);
                maxProfit += (r * cap);
                break;
            }
        }
        return maxProfit;
    }
};


int main() {
    int n,cap;
    cin>>n>>cap;
    vector<int> val(n), wt(n);

    for(int i=0; i<n; i++) {
        cin>>val[i];
    }
    for(int i=0; i<n; i++) {
        cin>>wt[i];
    }

    Solution s;
    cout<<s.fractionalKnapsack(val,wt,cap)<<endl;

    return 0;
}