#include<iostream>
#include<vector>
using namespace std;

void f(int n, int open, int close, string s, vector<string> &result) {
    if(open == n && close == n) {
        result.push_back(s);
        return;
    }
    if(open<n) f(n,open+1,close,s+"(",result);
    if(close<n && close<open) f(n,open,close+1,s+")",result);
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    f(n,0,0,"",result);
    return result;
}

int main() {
    vector<string> ans = generateParenthesis(4);

    for(auto ele : ans) {
        cout<<ele<<endl;
    }

    return 0;
}