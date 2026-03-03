#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph;
/**
 * bi_dir == true ==> undirected graph basically
 *           false ==> directed graph basically
 * 
 * Below is implementation for unweighted graph
 */
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
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
    int v;
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

    return 0;
}