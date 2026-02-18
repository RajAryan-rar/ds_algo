#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public: 
    string str;
    vector<int> dp;

    bool isPalindrome(int i, int j, string &s) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
            return true;
    }

    int f(int i) {
        if(i >= str.length()) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for(int j=i; j<str.length(); j++) {
            if(isPalindrome(i,j,str)) {
                int cost = 1 + f(j+1);
                ans = min(ans, cost);
            }
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        str = s;
        dp.clear();
        dp.resize(s.length()+1, -1);
        return f(0) - 1;
    }
};

int main() {
    string s;
    cin>>s;

    Solution sol;

    cout<<sol.minCut(s);

    return 0;
}