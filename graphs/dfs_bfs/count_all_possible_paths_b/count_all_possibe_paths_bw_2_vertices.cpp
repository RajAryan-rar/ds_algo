#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    
    int count = 0;
    vector<bool> visited;
    
    void dfs(int start, int end, vector<int> adj[]) {
        if(start == end) {
            count++;
            return;
        }
        visited[start] = true;
        for(auto neighbor : adj[start]) {
            if(!visited[neighbor]) {
                dfs(neighbor,end,adj);
            }
        }
        visited[start] = false;
    }
    
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        visited.clear();
        visited.resize(V,false);
        dfs(source, destination, adj);
        return count;
        
    }
};

int main() {
    int v,e;
    cin>>v>>e;

    vector<int> adj[v];

    for(int i=0; i<e; i++) {
        int u,w;
        cin>>u>>w;
        adj[u].push_back(w);
    }
    int source, destination;
    cin>>source>>destination;

    Solution s;
    cout<<s.countPaths(v,adj,source,destination);

    return 0;
}