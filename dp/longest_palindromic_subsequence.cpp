#include<iostream>
#include<vector>
using namespace std;

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

int f_bu(string& s) {
    // to be done till 20 jan 2026, 8 pm
}

int longestPalindromeSubseq(string s) {
    dp.clear();
    dp.resize(1005, vector<int>(1005,-1));
    return f(s,0,s.length()-1);
}

/*
there is another method to solve this problem
u can reverse the given string, let str = reverse(s)
now return lcs(s,str) --> answer :) 
*/

int main() {
    string s;
    cin>>s;
    cout<<longestPalindromeSubseq(s);

    return 0;
}