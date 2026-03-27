#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(),pairs.end(),cmp);
        int chainLen = 1, prevEnd = 0;
        prevEnd = pairs[0][1];
        for(int i=1; i<n; i++) {
            if(pairs[i][0] <= prevEnd) {
                continue;
            } else {
                prevEnd = pairs[i][1];
                chainLen++;
            }
        }
        return chainLen;
    }
};

int main() {
    int n;
    cin>>n;
    vector<vector<int>> pairs(n, vector<int> (2));

    for(int i=0; i<n; i++) {
        cin>>pairs[i][0]>>pairs[i][1];
    }

    Solution s;
    cout<<s.findLongestChain(pairs)<<endl;

    return 0;
}