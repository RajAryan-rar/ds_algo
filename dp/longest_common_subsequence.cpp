#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp;

int f(string &s1, string &s2, int i, int j) {
    if(i >= s1.length() || j >= s2.length()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return 1 + f(s1,s2,i+1,j+1);
    return dp[i][j] = max(f(s1,s2,i+1,j), f(s1,s2,i,j+1));
}

int f_bu(string &s1, string &s2) {
    dp.clear();
    dp.resize(1005, vector<int>(1005,0));
    for(int i=s1.length()-1; i>=0; i--) {
        for(int j=s2.length()-1; j>=0; j--) {
            if(s1[i] == s2[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2) {
    dp.clear();
    dp.resize(1005, vector<int>(1005,-1));
    // return f(text1,text2,0,0);
    return f_bu(text1,text2);
}

int main() {
    string text1, text2;
    cin>>text1>>text2;

    cout<<longestCommonSubsequence(text1,text2);

    return 0;
}