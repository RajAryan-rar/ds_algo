#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<unordered_map<int,int>> graph;

void add_edge(int src, int dest, int wt, bool bi_dir = true) {
    graph[src][dest] = wt;
    if(bi_dir) {
        graph[dest][src] = wt;
    }
}

void display() {
    cout<<endl;
    for(int i=0; i<graph.size(); i++) {
        cout<<i<<" --> ";
        for(auto ele : graph[i]) {
            cout<<"("<<ele.first<<","<<ele.second<<") ,";
        }
        cout<<endl;
    }
}

int main() {
    int v;
    cin>>v;

    graph.resize(v, unordered_map<int,int>());

    int e;
    cin>>e;
    while(e--) {
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }

    display();

    return 0;
}