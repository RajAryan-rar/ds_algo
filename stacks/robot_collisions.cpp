#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        for(int i=0; i<n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st;

        for(int i : idx) {
            if(directions[i] == 'R') st.push(i);
            else {
                while(!st.empty() && healths[i] != 0) {
                    int j = st.top();
                    st.pop();

                    if(healths[j] > healths[i]) {
                        healths[j]--;
                        healths[i] = 0;
                        st.push(j);
                    } else if(healths[j] < healths[i]) {
                        healths[i]--;
                        healths[j] = 0;
                    } else {
                        healths[i] = healths[j] = 0;
                    }
                }
            }
        }
        vector<int> result;
        for(int i=0; i<n; i++) {
            if(healths[i] > 0) result.push_back(healths[i]);
        }
        return result;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> healths(n), positions(n);
    string directions;

    for(int i=0; i<n; i++) cin>>positions[i];
    for(int i=0; i<n; i++) cin>>healths[i];
    cin>>directions;

    Solution s;

    vector<int> ans = s.survivedRobotsHealths(positions,healths,directions);
    for(int ele : ans) cout<<ele<<" ";

    return 0;
}