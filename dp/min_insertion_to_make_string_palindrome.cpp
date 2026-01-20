#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int f(string& s, int i, int j) {
        if(i >= s.length() || j < 0 || j < i) return 0;
        if(i == j && s[i] == s[j]) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) {
            return 2 + f(s,i+1,j-1);
        }
        return dp[i][j] = max(f(s,i+1,j), f(s,i,j-1));
    }

    int longestPalindromeSubseq(string s) {
        dp.clear();
        dp.resize(1005, vector<int>(1005,-1));
        return f(s,0,s.length()-1);
    }
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};

int main() {
    string s;
    cin>>s;

    Solution sol;
    cout<<sol.minInsertions(s);

    return 0;
}