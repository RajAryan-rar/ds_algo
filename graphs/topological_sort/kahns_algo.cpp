#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

vector<list<int>> graph;
int v;

void add_edge(int a, int b, bool bi_dir = true) {
    graph[a].push_back(b);
    if(bi_dir) graph[b].push_back(a);
}

void topoBFS() {
    //kahn's algorithm

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

    int count = 0;
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        count++;
        cout<<curr<<" ";
        
        for(auto neighbor : graph[curr]) {
            indeg[neighbor]--;
            if(indeg[neighbor] == 0) q.push(neighbor);
        }
    }
    if(count != v) {
        cout << "\nCycle detected! This is not a DAG.";
    }
}

int main() {
    cin>>v;
    graph.resize(v);
    
    int e;
    cin>>e;

    while(e--) {
        int a,b;
        cin>>a>>b;
        add_edge(a,b,false); //false --> directed graph
    }

    topoBFS();


    return 0;
}