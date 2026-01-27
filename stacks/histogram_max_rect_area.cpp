#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nsi(n);
        vector<int> psi(n);
        
        stack<int> st;
        st.push(0);
        psi[0] = -1;
        for(int i=1; i<n; i++) {
            while(st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();
            if(st.size() == 0) psi[i] = -1;
            
            else {
                psi[i] = st.top();
            }
            st.push(i);
        }
        
        stack<int> stt;
        stt.push(n-1);
        nsi[n-1] = n;
        for(int i=n-2; i>=0; i--) {
            while(stt.size() > 0 && arr[stt.top()] >= arr[i]) stt.pop();
            if(stt.size() == 0) nsi[i] = n;
            
            else {
                nsi[i] = stt.top();
            }
            stt.push(i);
        }
        
        int maxArea = INT_MIN;
        for(int i=0; i<n; i++) {
            int height = arr[i];
            int width = abs(nsi[i] - psi[i] - 1);
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
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
    cout<<s.getMaxArea(arr);

    return 0;
}