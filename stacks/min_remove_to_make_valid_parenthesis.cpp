#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> rem;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                if(st.size() == 0) rem.insert(i);
                else st.pop();
            }
        }
        while(!st.empty()) {
            rem.insert(st.top());
            st.pop();
        }
        string result = "";
        for(int i=0; i<s.length(); i++) {
            if(rem.count(i) == 0) result += s[i];
        }
        return result;
    }
};

int main() {
    string str;
    cin>>str;

    Solution s;
    cout<<s.minRemoveToMakeValid(str)<<endl;

    return 0;
}