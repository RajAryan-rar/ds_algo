#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n);

        unordered_map<int,int> mp;

        stack<int> st;
        mp[nums2[m-1]] = -1;
        st.push(nums2[m-1]);

        for(int i=m-2; i>=0; i--) {
            //pop
            while(st.size() > 0 && st.top() < nums2[i]) st.pop();

            if(st.size() == 0) mp[nums2[i]] = -1;
            else {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++) {
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};

int main() {
    

    return 0;
}