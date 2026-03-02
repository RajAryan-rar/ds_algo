#include<iostream>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = 0, cost = 0, maxLen = 0;
        
        while(r < s.size()) {
            cost += abs(s[r] - t[r]);
            while(cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

int main() {
	string s,t;
	int maxCost;
	cin>>s>>t>>maxCost;

	Solution sol;
	cout<<sol.equalSubstring(s,t,maxCost);

	return 0;
}
