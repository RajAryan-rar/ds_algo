#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
using namespace std;

#define inf INT_MAX

vector<list<int>> graph;

void add_edge(int src, int dest, bool un_dir = true) {
    graph[src].push_back(dest);
    if(un_dir) graph[dest].push_back(src);
}

int bfs(int source, int destination) {
    vector<bool> visited(graph.size(), false);
    vector<int> distance(graph.size(), inf);
    queue<int> q;

    distance[source] = 0;
    q.push(source);
    visited[source] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for(auto neighbor : graph[curr]) {
            if(!visited[neighbor]) {
                distance[neighbor] = distance[curr] + 1;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return distance[destination];
}

int main() {
    int v,e;
    cin>>v>>e;

    graph.resize(v, list<int> ());
    while(e--) {
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }

    cout<<endl;

    int source, destination;
    cin>>source>>destination;

    cout<<bfs(source,destination);

    return 0;
}