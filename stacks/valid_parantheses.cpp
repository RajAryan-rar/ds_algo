#include<iostream>
#include<stack>
using namespace std;

bool check(char ch1, char ch2) {
    if(ch1 == '(' && ch2 == ')') return true;
    if(ch1 == '{' && ch2 == '}') return true;
    if(ch1 == '[' && ch2 == ']') return true;
    else return false;
}

bool isValid(string s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if(st.size()==0 || check(st.top(), s[i]) == false) return false;
            else {
                if(st.empty() == true) return false;
                st.pop();
            }
        }
    }    
    return (st.size() != 0) ? false : true;
}

int main() {
    string s;
    cin>>s;

    cout<<isValid(s);

    return 0;
}