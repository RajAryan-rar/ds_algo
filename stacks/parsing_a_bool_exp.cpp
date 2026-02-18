#include<iostream>
#include<stack>
using namespace std;

bool parseBoolExpr(string expression) {
    int n = expression.length();
    stack<char> st;

    for(int i=0; i<n; i++) {
        char ch = expression[i];
        if(ch == ',') continue;
        if(ch != ')') {
            st.push(ch);
        }
        else {
            bool hasTrue = false;
            bool hasFalse = false;

            while(st.top() != '!' && st.top() != '&' && st.top() != '|') {
                char val = st.top();
                st.pop();
                if(val == 't') hasTrue = true;
                if(val == 'f') hasFalse = true;
            }
            char op = st.top();
            st.pop();

            if(op == '!') {
                st.push(hasTrue ? 'f' : 't');
            } else if(op == '&') {
                st.push(hasFalse ? 'f' : 't');
            } else if(op == '|') {
                st.push(hasTrue ? 't' : 'f');
            }
        }
    }
    return st.top() == 't';
}

int main() {
    string s;
    cin>>s;

    if(parseBoolExpr(s)) cout<<"true";
    else cout<<"false";

    return 0;
}