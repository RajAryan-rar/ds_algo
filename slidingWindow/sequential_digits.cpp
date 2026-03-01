#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int n = high, maxLen = 0;
        while(n > 0) {
            maxLen++;
            n /= 10;
        }

        vector<int> result;
        for(int len=2; len<=maxLen; len++) {
            int i=0, j=len-1;
            while(j < s.length()) {
                string str = s.substr(i,len);
                int num = stoi(str);
                if(num > high) break;
                if(num >= low) result.push_back(num);
                i++;
                j++;
            }
        }
        return result;
    }
};

int main() {
    int low, high;
    cin>>low>>high;

    Solution s;

    vector<int> ans = s.sequentialDigits(low,high);
    for(auto ele : ans) cout<<ele;

    return 0;
}