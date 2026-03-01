#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";

        vector<int> result;
        for(int len=2; len<=s.length(); len++) {
            for(int sIdx=0; sIdx<=s.length()-len; sIdx++) {
                string str = s.substr(sIdx,len);
                int num = stoi(str);
                if(num >= low && num <= high) {
                    result.push_back(num);
                }
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