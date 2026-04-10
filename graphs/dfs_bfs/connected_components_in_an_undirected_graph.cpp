#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    vector<vector<int>> graph;
    void add_edge(int src, int dest, bool un_dir = true) {
        graph[src].push_back(dest);
        if(un_dir) graph[dest].push_back(src);
    }
    void dfs(int src, vector<bool>& visited, vector<int>& cc) {
        visited[src] = true;
        cc.push_back(src);
        
        for(auto neighbor : graph[src]) {
            if(!visited[neighbor]) {
                dfs(neighbor,visited,cc);
            }
        }
    } 
    vector<int> bfs(int src, vector<bool>& visited) {
        vector<int> cc;
        
        queue<int> q;
        q.push(src);
        visited[src] = true;
        cc.push_back(src);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for(auto neighbor : graph[curr]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    cc.push_back(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return cc;
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        graph.resize(V);
        
        for(auto edge : edges) 
            add_edge(edge[0],edge[1]);
        
        vector<bool> visited(V,false);
        
        vector<vector<int>> result;
        //BFS Implementation :-
        // for(int i=0; i<V; i++) {
        //     if(!visited[i]) {
        //         result.push_back(bfs(i,visited));
        //     }
        // }
        
        //DFS Implementation :-
        for(int i=0; i<V; i++) {
            vector<int> cc;
            if(!visited[i]) {
                dfs(i,visited,cc);
                result.push_back(cc);
            }
        }
        
        return result;
    }
};


int main() {
    int v,e;
    cin>>v>>e;

    vector<vector<int>> edges(e, vector<int>(2));

    for(int i=0; i<e; i++) {
        cin>>edges[i][0]>>edges[i][1];
    }    

    Solution s;
    edges = s.getComponents(v,edges);

    for(auto v : edges) {
        for (int ele : v) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}