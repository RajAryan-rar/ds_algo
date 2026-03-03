#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<unordered_set<int>> graph;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].insert(dest);
    if(bi_dir) {
        graph[dest].insert(src);
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

    graph.resize(v, unordered_set<int>());

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