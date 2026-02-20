#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int f(string &s, int i) {
        if(i < 0) return 1;
        if(dp[i] != -1) return dp[i];

        int ans = 0;

        if(s[i] != '0') {
            ans += f(s,i-1);
        }
        if(i > 0) {
            int x = ((s[i-1] - '0') * 10 + (s[i] - '0'));
            if(x >= 10 && x <= 26) {
                ans += f(s, i-2);
            }
        }
        return dp[i] = ans;
    }

    int fbu(string s) {
        dp.clear();
        dp.resize(s.length()+1, 0);

        dp[0] = (s[0] != '0');
        if(s.size() > 1) {
            if(s[1] != '0') dp[1] += dp[0];
            if(s[1-1] - '0' > 0 && (s[0] - '0')*10 + (s[1] - '0') <= 26) dp[1]++;
        }
        for(int i=2; i<s.length(); i++) { // i:2 -> s.len-1, 2 ==> len 3
            int ans = 0;

            if(s[i] != '0') {
                ans += dp[i-1];
            }
            if(s[i-1] - '0' > 0 && (s[i-1] - '0') * 10 + (s[i] - '0') <= 26) {
                ans += dp[i-2];
            }
            dp[i] = ans;
        }
        return dp[s.length()-1];
    }

    int f2(string &s, int i) {
        if(i >= s.length()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        int ans = f2(s,i+1);
        if(i < s.length()-1) {
            int x = (s[i] - '0')*10 + (s[i+1] - '0');
            if(x >= 10 && x <= 26) {
                ans += f2(s,i+2);
            }
        }
        return dp[i] = ans;
    }

    int numDecodings(string s) {
        int n = s.length();
        dp.clear();
        dp.resize(n+1,-1);
        return f(s,n-1);
        // return f2(s,0);
    }
};

int main() {
    string s;
    cin>>s;

    Solution sol;
    cout<<sol.numDecodings(s);

    return 0;
}