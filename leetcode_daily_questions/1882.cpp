#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define P pair<int,int>
#define T tuple<long long, int, int>
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<
            P, 
            vector<P>, 
            greater<P>
        > freeServer; //{weight, index}

        priority_queue<
            T,
            vector<T>,
            greater<T>
        > busyServer; // [finishTime, weight, index]

        int n = servers.size(), m = tasks.size();
        for(int i=0; i<n; i++) {
            freeServer.push({servers[i],i});
        }        

        vector<int> result(m);

        for(int i=0; i<m; i++) {
            //move the available servers from bs to fs if they are free by the ith time
            while(!busyServer.empty() && get<0>(busyServer.top()) <= i) {
                auto [ft, weight, idx] = busyServer.top();
                
                busyServer.pop();
                freeServer.push({weight,idx});
            }

            //if all the servers are busy
            if(freeServer.empty()) {
                auto[finishTime, weight, idx] = busyServer.top();
                busyServer.pop();
                result[i] = idx;
                busyServer.push({finishTime+tasks[i],weight,idx});
            } else { // free servers available
                auto [weight, idx] = freeServer.top();
                result[i] = idx;
                freeServer.pop();
                busyServer.push({i+tasks[i], weight, idx});
            }
        }
        return result;
    }
    /**
    *TC : O(mlogn)
    *SC : O(m+n)
    */
};

int main() {
    int n, m;
    cin>>n>>m;

    vector<int> servers(n), tasks(m);

    for(int i=0; i<n; i++) cin>>servers[i];
    for(int i=0; i<m; i++) cin>>tasks[i];

    Solution s;

    tasks = s.assignTasks(servers, tasks);

    for(int ele : tasks) cout<<ele<<", ";

    return 0;
}