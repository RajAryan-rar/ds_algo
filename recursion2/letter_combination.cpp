#include<iostream>
#include<vector>
using namespace std;

vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> result;

void f(string &s, int i, string output) {
    if(i == s.length()) {
        result.push_back(output);
        return;
    }
    int digit = s[i] - '0';
    string charsOfMapping = mapping[digit];
    for(int j=0; j<charsOfMapping.length(); j++) {
        f(s,i+1,output+charsOfMapping[j]);
    }
}

vector<string> letterCombinations(string digits) {
    f(digits,0,"");
    return result;
}

int main() {
    vector<string> ans = letterCombinations("23");
    for(auto ele : ans) {
        cout<<ele<<endl;
    }

    return 0;
}