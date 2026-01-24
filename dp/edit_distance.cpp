#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp;
int f(string &s1, string &s2, int i, int j) {
    if(i == 0) return j;
    if(j == 0) return i;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = f(s1,s2,i-1,j-1);

    else return dp[i][j] =1 + min(f(s1,s2,i-1,j-1), min(f(s1,s2,i,j-1),f(s1,s2,i-1,j)));
} 

int f_bu(string &s1, string &s2, int m, int n) {
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1];

            else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
    }
    return dp[m][n];
}

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    if(m == 0 && n == 0) return 0;

    dp.clear();
    dp.resize(5005, vector<int>(5005,-1));

    string s1 = " ";
    string s2 = " ";
    s1 += word1;
    s2 += word2;

    return f(s1,s2,m,n);
}

int main() {
    string word1;
    cin>>word1;
    string word2;
    cin>>word2;

    cout<<minDistance(word1,word2);

    return 0;
}