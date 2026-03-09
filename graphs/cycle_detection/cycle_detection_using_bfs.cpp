#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}

bool bfs(int src, vector<bool>& visited) {
    vector<int> parent(v,-1);
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while(q.size() > 0) {
        int curr = q.front(); //this is parent
        q.pop();

        for(auto neighbor : graph[curr]) {
            if(visited[neighbor] && neighbor != parent[curr]) {
                return true;
            } else if(!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }
    return false;
}   

bool hasCycle() {
    vector<bool> visited(v,false);
    bool result = false;
    for(int i=0; i<v; i++) {
        if(visited[i] == false) {
            result = bfs(i, visited);
            if(result) return true;
        }
    }
    return false;
}

int main() {
    cin>>v;

    graph.resize(v, list<int>());

    int e;
    cin>>e;
    while(e--) {
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }

    bool result = hasCycle();
    if(result) cout<<"Cycle Detected!!!"<<endl;
    else cout<<"No cycle present!"<<endl;

    return 0;
}