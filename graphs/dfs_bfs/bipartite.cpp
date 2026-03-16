#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<bool> visited(v, false);
        vector<int> color(v,-1);
        queue<int> q;
        
        for(int i=0; i<v; i++) {
            if(visited[i]) continue;
            q.push(i);
            visited[i] = true;
            color[i] = 0;

            while(!q.empty()) {
                int curr = q.front();
                q.pop();

                for(auto neighbor : graph[curr]) {
                    if(visited[neighbor]) {
                        if(color[curr] == color[neighbor]) return false;
                        else continue;
                    }
                    if(color[curr] == 0) color[neighbor] = 1;
                    else color[neighbor] = 0;
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return true;
    }
};

int main() {
    int v;
    cin>>v;

    vector<vector<int>> graph(v);

    for(int i=0; i<v; i++) {
        int e;
        cin>>e;
        while(e--) {
            int x;
            cin>>x;
            graph[i].push_back(x);
        }
    }

    Solution s;
    if(s.isBipartite(graph)) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}