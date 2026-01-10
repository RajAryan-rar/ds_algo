#include<iostream>
#include<vector>
using namespace std;

void f(int n, string s, vector<string>& result) {
    if(s.length() == n) {
        result.push_back(s);
        return;
    }

    f(n, s+"0", result);
    if(s[s.length()-1] != '1') f(n, s+"1", result);
}

vector<string> generate_binary_strings(int n) {
    vector<string> result;
    f(n, "", result);
    return result;
}

int main() {
    int n;
    cin>>n;

    vector<string> ans = generate_binary_strings(n);

    for(auto ele : ans) cout<<ele<<" ";

    return 0;
}