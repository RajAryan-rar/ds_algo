#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

class Solution {
public :
    string minWindow(string s, string t) {
        int m = t.length();
        int n = s.length();
        int l = 0, r = 0, count = 0, minLen = INT_MAX, startIdx = -1;

        unordered_map<char,int> mp;

        for(int i=0; i<m; i++) mp[t[i]]++; //pre insertion

        while(r < n) {
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;
            while(count == m) {
                if(r-l+1 < minLen) {
                    startIdx = l;
                    minLen = r-l+1;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        return (startIdx == -1) ? "" : s.substr(startIdx,minLen);
    }
};

int main() {
    string s,t;
    cin>>s>>t;

    Solution sol;
    cout<<sol.minWindow(s,t);

    return 0;
}