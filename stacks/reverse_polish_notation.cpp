#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<int> st;

        int ans = 0;

        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/") {
               int b = st.top();
               st.pop();
               int a = st.top();
               st.pop();

               if(arr[i] == "+") {
                int val = a + b;
                st.push(val);
               } else if(arr[i] == "-") {
                int val = a-b;
                st.push(val);
               } else if(arr[i] == "*") {
                int val = a*b;
                st.push(val);
               } else {
                int val = a/b;
                st.push(val);
               }
               
            } else{
                int num = stoi(arr[i]);
                st.push(num);
            }
        }
        return st.top();

    }
};

int main() {
    int n;
    cin>>n;
    vector<string> arr;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    Solution s;
    cout<<s.evalRPN(arr);

    return 0;
}