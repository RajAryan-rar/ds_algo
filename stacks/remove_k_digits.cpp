#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (k >= n) return "0";

        string res = "";

        for (char c : num) {
            while (k > 0 && !res.empty() && res.back() > c) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }

        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }

        int start = 0;
        while (start < res.length() && res[start] == '0') {
            start++;
        }

        string final_res = res.substr(start);

        return final_res.empty() ? "0" : final_res;
    }
};

int main() {
    string num;
    cin>>num;
    int k;
    cin>>k;
    Solution s;
    cout<<s.removeKdigits(num,k);

    return 0;
}