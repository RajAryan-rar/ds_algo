#include<iostream>
#include<vector>
using namespace std;

void f(string s, int i, string str, vector<string> &v) {
    if(i == s.length()) {
        cout<<str<<endl;
        v.push_back(str); //also for storing
        return;
    }

    f(s,i+1,str,v);
    f(s,i+1,str+s[i],v);
}

int main() {
    vector<string> v;
    f("abc",0,"",v);

    for(int i=0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }

    return 0;
}