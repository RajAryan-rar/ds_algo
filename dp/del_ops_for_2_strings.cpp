#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp;

int f(string& s1, string& s2, int i, int j) {
    if(i >= s1.length() || j >= s2.length()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) {
        return 1 + f(s1,s2,i+1,j+1);
    } else {
        return dp[i][j] = max(f(s1,s2,i+1,j), f(s1,s2,i,j+1));
    }
}

int minDistance(string word1, string word2) {
    dp.clear();
    dp.resize(505, vector<int>(505,-1));

    int len_of_lcs = f(word1,word2,0,0);
    return word1.length()-len_of_lcs + word2.length()-len_of_lcs;
}




int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout<<minDistance(s1,s2);

    return 0;
}