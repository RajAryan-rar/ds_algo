#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        stack<int> st;
        while(n > 0) {
            int currBit = n & 1;
            if(st.size() > 0) {
                if(st.top() == currBit) return false;
            }
            st.push(currBit);
            n >>= 1;
        }
        return true;
    }
};

int main() {
    int n;
    cin>>n;

    Solution s;
    if(s.hasAlternatingBits(n)) cout<<"true";
    else cout<<"false";

    return 0;
}