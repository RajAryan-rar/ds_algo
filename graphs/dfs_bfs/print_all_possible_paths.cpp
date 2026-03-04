#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph;

void add_edge(int src, int dest, bool un_dir = true) {
    graph[src].push_back(dest);
    if(un_dir) graph[dest].push_back(src);
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
    cout<<endl;
}

vector<bool> visited;
vector<string> result;
void dfs(int start, int end, string path) {
    path += to_string(start) + ((start == end) ? "" : "->");
    if(start == end) {
        result.push_back(path);
        return;
    }
    visited[start] = true;
    for(auto neighbor : graph[start]) {
        if(!visited[neighbor]) {
            dfs(neighbor,end,path);
        }
    }
    visited[start] = false;
}

int main() {
    int v,e;
    cin>>v>>e;

    graph.resize(v, list<int>());
    visited.resize(v,false);
    
    while(e--) {
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();

    int source, destination;
    cin>>source>>destination;

    dfs(source,destination,"");

    for(auto s : result) cout<<s<<endl;

    return 0;
}