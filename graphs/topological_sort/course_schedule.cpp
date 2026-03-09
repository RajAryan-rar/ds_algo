#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<list<int>> graph;
    int v;

    void add_edge(int a, int b, bool bi_dir = true) {
        graph[a].push_back(b);
        if(bi_dir) graph[b].push_back(a);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        v = numCourses;
        graph.resize(v);
        int e = prerequisites.size();

        for(int i=0; i<e; i++) {
            int a = prerequisites[i][1];
            int b = prerequisites[i][0];

            add_edge(a,b,false);
        }

        vector<int> indeg(v,0);
        for(int i=0; i<v; i++) {
            for(auto neighbor : graph[i]) {
                indeg[neighbor]++;
            }
        }

        queue<int> q;
        for(int i=0; i<v; i++) {
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> result;
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            result.push_back(curr);

            for(auto neighbor : graph[curr]) {
                indeg[neighbor]--;
                if(indeg[neighbor] == 0) q.push(neighbor);
            }
        }
        return (result.size() == v) ? result : vector<int>{};
    }
};

int main() {
    int numCourses;
    cin>>numCourses;
    
    int e;
    cin>>e;
    vector<vector<int>> prereqs(e, vector<int>(2));

    for(int i=0; i<e; i++) {
        cin>>prereqs[i][0]>>prereqs[i][1];
    }

    Solution s;
    vector<int> ans = s.findOrder(numCourses,prereqs);

    for(auto ele : ans) cout<<ele<<" ";

    return 0;
}