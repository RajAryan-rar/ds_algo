#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int check(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'
                || ch == 'u') ? 1 : 0;
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxLen = 0, count = 0, l = 0, r = 0;

        for(int i=0; i<n; i++) {
            count += check(s[i]);
            if(i >= k) {
                count -= check(s[i-k]);
            }
            maxLen = max(maxLen, count);
        }
        return maxLen;
    }
};

int main() {
    int k;
    string s;
    cin>>k>>s;

    Solution sol;
    cout<<sol.maxVowels(s,k);

    return 0;
}