#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> dp;

int f_bu(string &s1, string &s2) {
    dp.clear();
    dp.resize(s1.length()+1, vector<int>(s2.length()+1,0));
    for(int i=1; i<=s1.length(); i++) {
        for(int j=1; j<=s2.length(); j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[s1.length()][s2.length()];
}

pair<int,string> longestCommonSubsequence(string text1, string text2) {
    
    // return f(text1,text2,0,0);
    int length = f_bu(text1,text2);

    int i = text1.length();
    int j = text2.length();

    string res = "";

    while(i > 0 && j > 0) {
        if(text1[i-1] == text2[j-1]) {
            res += text1[i-1];
            i--;
            j--;
        } else if(dp[i-1][j] >= dp[i][j-1]){
            i--;
        } else j--;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;

    return {length, res};

}

int main() {
    string text1, text2;
    cin>>text1>>text2;

    pair<int, string> ans = longestCommonSubsequence(text1,text2); 

    // for(auto v : dp) {
    //     for(auto ele : v) {
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=0; i<dp.size(); i++) {
    //     for(int j=0; j<dp[0].size(); j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    cout << ans.first << " " << ans.second;

    return 0;
}