#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}

bool dfs(int src, int parent, unordered_set<int>& visited) {
    visited.insert(src);
    for(auto neighbor : graph[src]) {
        if(visited.count(neighbor) != 0 && neighbor != parent) {
            return true;
        } else if(visited.count(neighbor) == 0) dfs(neighbor,src,visited);
    }
    return false;
}

bool hasCycle() {
    unordered_set<int> visited;
    bool result = false;

    for(int i=0; i<v; i++) {
        if(visited.count(i) == 0) {
            result = dfs(i,-1,visited);
            if(result == true) return true;
        }
    }
    return false;
}

void display() {
    cout<<endl;
    for(int i=0; i<graph.size(); i++) {
        cout<<i<<" --> ";
        for(auto ele : graph[i]) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
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

    display();

    if(hasCycle()) cout<<"Cycle detected!!!"<<endl;
    else cout<<"No cycle present in the graph";

    return 0;
}