#include<iostream>
#include<vector>
using namespace std;

/*
    BRUTE FORCE WAY (Recursion)
*/
// int f(string &s, string &t, string res, int i) {
//     if(res == t) return 1;
//     if(i == s.length()) return 0;

//     return f(s,t,res+s[i],i+1) + f(s,t,res,i+1);
// }

vector<vector<int>> dp;

int f(string &s, string &t, int i, int j) {
    if(j == t.length()) return 1;
    if(i == s.length()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = f(s,t,i+1,j);

    if(s[i] == t[j]) ans += f(s,t,i+1,j+1);
    
    return dp[i][j] = ans;
}


int main() {
    string s,t;
    cin>>s>>t;

    dp.clear();
    dp.resize(s.length()+1, vector<int>(t.length()+1,-1));

    cout<<f(s,t,0,0);


    return 0;
}