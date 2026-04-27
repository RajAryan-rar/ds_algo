#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:

    bool check(char ch1, char ch2) {
        if(ch1 == '(' && ch2 == ')') return true;
        if(ch1 == '{' && ch2 == '}') return true;
        if(ch1 == '[' && ch2 == ']') return true;
        else return false;
    }

    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else {
                if(st.size() == 0) return false;
                if(check(st.top(),s[i])) st.pop();
                else return false;
            }
        }    
        return st.size() == 0;
    }
};
int main() {
    string s;
    cin>>s;

    Solution sol;

    cout<<sol.isValid(s);

    return 0;
}