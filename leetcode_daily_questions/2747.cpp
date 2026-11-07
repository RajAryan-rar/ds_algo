#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    
    vector<int> countServers(int t, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();

        int n = queries.size();

        vector<vector<int>> q(n, vector<int>(2,0));
        for(int i=0; i<n; i++) {
            q[i][0] = i;
            q[i][1] = queries[i];
        }

        sort(logs.begin(), logs.end(), cmp);
        sort(q.begin(), q.end(), cmp);

        int l=0, r=0;
        unordered_map<int,int> freq; // stores [server, frequency]

        vector<int> ans(n,0);
        for(int i=0; i<q.size(); i++) {
            int idx = q[i][0];
            int time = q[i][1];
            int s = time - x, e = time;

            // expansion
            while(r < m && logs[r][1] <= e) {
                freq[logs[r][0]]++;
                r++;
            }

            // shrinking
            while(l < r && logs[l][1] < s) {
                freq[logs[l][0]]--;
                if(freq[logs[l][0]] == 0) freq.erase(logs[l][0]);
                l++;
            }
            ans[idx] = t - freq.size();
        }

        return ans;
    }
    /*
    * TC : O(mlogm+nlogn)
    * SC : O(m+n)
    */
};

int main() {
    int t, x, m, n;
    cin>>t>>x>>m>>n;

    vector<vector<int>> logs(m, vector<int>(2,0));
    vector<int> queries(n);

    for(int i=0; i<m; i++) {
        cin>>logs[i][0]; //serverid input
        cin>>logs[i][1]; //time input
    }
    for(int i=0; i<n; i++) {
        cin>>queries[i];
    }

    Solution s;
    vector<int> ans = s.countServers(t,logs,x,queries);

    for(int ele : ans) cout<<ele<<" ";

    return 0;
}