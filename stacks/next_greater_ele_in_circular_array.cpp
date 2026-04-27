#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> v(2*n);
        for(int i=0; i<2*n; i++) {
            v[i] = arr[i%n];
        }
        
        vector<int> nge(2*n);
        nge[2*n-1] = -1;
        stack<int> st;
        st.push(2*n-1);
        
        for(int i=2*n-2; i>=0; i--) {
            //pop
            while(!st.empty() && v[st.top()] <= v[i]) st.pop();
            
            //ans
            if(st.size() == 0) nge[i] = -1;
            else nge[i] = v[st.top()];
            
            //push
            st.push(i);
        }
        vector<int> result(n);
        for(int i=0; i<n; i++) result[i] = nge[i];
        return result;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    Solution s;
    arr = s.nextGreater(arr);

    for(int ele : arr) cout<<ele<<" ";

    return 0;
}