#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(char ch : s) {
            st.push(ch);

            while(st.size() >= 2) {
                char a = st.top();
                st.pop();
                char b = st.top();
                st.pop();

                if(a != b) {
                    st.push(b);
                    st.push(a);
                    break;
                }
            }
        }
        string ans = "";
        while(st.size() > 0) {
            char ch = st.top();
            st.pop();
            ans = ch + ans;
        }
        return ans;
    }
};

int main() {
    string str;
    cin>>str;

    Solution s;
    cout<<s.removeDuplicates(str)<<endl;

    return 0;
}