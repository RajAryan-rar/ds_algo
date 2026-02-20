#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> dp;

int f(string s, int i) {
    if(i < 0) return 1;
    if(i == 0) return (s[i] != '0') ? 1 : 0;
    if(dp[i] != -1) return dp[i];

    int ans = 0;

    if(s[i] != '0') {
        ans += f(s,i-1);
    }
    if(i > 0) {
        int x = (s[i-1] - '0') * 10 + (s[i] - '0');
        if(x >= 10 && x <= 26) {
            ans += f(s,i-2);
        }
    }

    return dp[i] = ans;
}

int main() {
    string s;

    while (cin >> s && s != "0") {
        int len = s.length();
        dp.assign(len, -1);
        
        cout << f(s, len - 1) << "\n";
    }

    return 0;
}