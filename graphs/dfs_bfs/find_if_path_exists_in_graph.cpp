#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<list<int>> graph;
    unordered_set<int> visited;

    void add_edge(int src, int dest, bool bi_dir = true) {
        graph[src].push_back(dest);
        if(bi_dir) graph[dest].push_back(src);
    }

    bool dfs(int start, int end) {
        if(start == end) return true;
        visited.insert(start);
        for(auto neighbor : graph[start]) {
            if(visited.count(neighbor) == 0) {
                bool result = dfs(neighbor,end);
                if(result) return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        graph.clear();
        graph.resize(n, list<int>());
        for(auto edge : edges) {
            add_edge(edge[0], edge[1]);
        }
        return dfs(source, destination);
    }
};

int main() {
    int n,e;
    cin>>n>>e;
    
    vector<vector<int>> edges(e, vector<int>(2));
    for(int i=0; i<e; i++) {
        cin>>edges[i][0]>>edges[i][1];
    }
    int source, destination;
    cin>>source>>destination;

    Solution s;
    if(s.validPath(n,edges,source,destination)) cout<<"true";
    else cout<<"false";


    return 0;
}