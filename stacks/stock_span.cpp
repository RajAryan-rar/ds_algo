#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> pgi(n);
        
        stack<int> st;
        
        pgi[0] = -1;
        st.push(0);
        
        for(int i=1; i<n; i++) {
            while(st.size() > 0 && arr[st.top()] <= arr[i]) st.pop();
            if(st.size() == 0) pgi[i] = -1;
            
            else {
                pgi[i] = st.top();
            }
            st.push(i);
        }
        
        for(int i=0; i<n; i++) {
            if(pgi[i] == -1) pgi[i] = i+1;
            else pgi[i] = i - pgi[i];
        }
        return pgi;
    }
};

int main() {
    

    return 0;
}