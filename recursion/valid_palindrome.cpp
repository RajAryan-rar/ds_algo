#include<iostream>
using namespace std;

bool f(string &s, int i) {
    if(i >= s.length()/2) return true;
    if(s[i] != s[s.length() - i -1]) return false;
    return f(s,i+1);
}

bool isPalindrome(string s) {
    string str = "";
    for (char ch : s) {
        if (isalnum(ch)) {    
            str += tolower(ch);    
        }
    }
    return f(str,0);
}


int main() {
    string s;
    
    getline(cin, s);

    if(isPalindrome(s)) cout<<"true";
    else cout<<"false";

    return 0;
}