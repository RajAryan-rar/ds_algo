#include<iostream>
#include<string>
using namespace std;

//remove all occurences of a char from the string

// Method - 1
// void f(string s, int idx, char x) {
//     if(idx >= s.length()) return;
//     if(s.at(idx) != x) {
//         cout<<s[idx];
//     }
//     f(s, idx+1, x);
// }

void f(string s, int idx, char x, string output) {
    if(idx >= s.length()) {
        cout<<output<<endl;
        return;
    }

    if(s[idx] != x) f(s, idx+1, x, output+=s[idx]);
    else f(s, idx+1, x, output);
}


int main() {
    f("abcdxabcxxac", 0, 'x', "");

    return 0;
}