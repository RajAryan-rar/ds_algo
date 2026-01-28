#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ngi(n);

        stack<int> st;
        ngi[n-1] = 0;

        st.push(n-1);

        for(int i=n-2; i>=0; i--) {
            while(st.size()>0 && arr[st.top()] <= arr[i]) st.pop();

            if(st.size() == 0) ngi[i] = 0;
            else {
                ngi[i] = st.top();
            }
            st.push(i);
        }

        for(int i=0; i<n; i++) {
            if(ngi[i] == 0) continue;
            else ngi[i] = ngi[i] - i;
        }

        return ngi;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    Solution s;
    vector<int> ans = s.dailyTemperatures(arr);

    for(auto ele : ans) {
        cout<<ele<<" ";
    }

    return 0;
}