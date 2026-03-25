#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        sort(s.begin(),s.end());
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }

        priority_queue<pair<char,int>> pq;
        for(auto p : mp) {
            pq.push({p.first,p.second});
        }

        string result = "";
        while(!pq.empty()) {
            auto largest = pq.top();
            pq.pop();
            int len = min(largest.second, repeatLimit);

            for(int i=0; i<len; i++) result += largest.first;

            if(largest.second - len > 0) {
                pair<char,int> secondLargest;
                if(!pq.empty()) {
                    secondLargest = pq.top();
                    pq.pop();
                    result += secondLargest.first;
                } else {
                    return result;
                }
                if(secondLargest.second - 1 > 0) {
                    pq.push({secondLargest.first,secondLargest.second-1});
                }
                pq.push({largest.first, largest.second-len});

            } 
        }
        return result;

    }
};

int main() {
    string s;
    cin>>s;
    
    int repeatLimit;
    cin>>repeatLimit;
    
    Solution sol;
    cout<<sol.repeatLimitedString(s,repeatLimit);

    return 0;
}