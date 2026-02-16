#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int dp[105][105][105];

int f(int i, int j, int k, string &s1, string &s2) {
    if(k == 0) return 0;
    if(i >= s1.size() || j >= s2.size()) return -1000000000;
    if(dp[i][j][k] != -1) return dp[i][j][k];

    if(s1[i] == s2[j]) {
        return dp[i][j][k] = max(int(s1[i]) + f(i+1,j+1,k-1,s1,s2), max(f(i+1,j,k,s1,s2), f(i,j+1,k,s1,s2)));
    }
    else {
        return dp[i][j][k] = max(f(i+1,j,k,s1,s2), f(i,j+1,k,s1,s2));
    }
}

int main() {
    int t;
    cin>>t;
    
    vector<int> ans;

    while(t--) {
        string s1,s2;
        int k;
        cin>>s1>>s2>>k;
        memset(dp, -1, sizeof(dp));
        int res = f(0,0,k,s1,s2);
        if(res < 0) res = 0;
        ans.push_back(res);

    }

    for(auto ele : ans) {
        cout<<ele<<endl;
    }

    return 0;
}