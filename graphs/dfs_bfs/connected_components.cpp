#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

vector<list<int>> graph;
int v;

void add_edge(int src, int dest, bool un_dir = true) {
    graph[src].push_back(dest);
    if(un_dir) graph[dest].push_back(src);
}

void dfs(int node, vector<bool>& visited) {
    visited[node] = true;
    for(auto neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor,visited);
        }
    }
}

void bfs(int node, vector<bool>& visited) {
    queue<int> q;
    q.push(node);

    visited[node] = true;
    while(q.size() > 0) {
        int curr = q.front();
        q.pop();

        for(auto neighbor : graph[curr]) {
            if(!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int connected_components() {
    vector<bool> visited(v,false);
    int count = 0;
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            count++;
            dfs(i,visited);
        }
    }
    return count;
}

int main() {
    int e;
    cin>>v>>e;
    graph.resize(v, list<int>());

    while(e--) {
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }

    cout<<"There are "<<connected_components()<<" connected components in the given graph"<<endl;


    return 0;
}