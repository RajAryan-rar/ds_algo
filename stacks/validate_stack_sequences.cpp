#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;

        for(int ele : pushed) {
            st.push(ele);

            while(st.size() > 0 && popped[j] == st.top()) {
                st.pop();
                j++;
            }
        }
        return st.size() == 0;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> pushed(n);
    vector<int> popped(m);

    for(int i=0; i<n; i++) cin>>pushed[i];
    for(int i=0; i<m; i++) cin>>popped[i];

    Solution s;
    cout<<s.validateStackSequences(pushed,popped);

    return 0;
}