#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<climits>
using namespace std;

#define pp pair<int,int>
#define inf INT_MAX

vector<list<pp>> graph;
 
void add_edge(int src, int dest, int wt, bool bi_dir = true) {
    graph[src].push_back({dest,wt});
    if(bi_dir) graph[dest].push_back({src,wt});
}

unordered_map<int,int> dijkstra(int src, int v) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_map<int,int> mp;
    unordered_set<int> visited;
    vector<int> via(v);

    for(int i=0; i<v; i++) mp[i] = inf;

    pq.push({0,src});
    mp[src] = 0;

    while(!pq.empty()) {
        pp curr = pq.top();
        pq.pop();

        if(visited.count(curr.second)) continue;

        visited.insert(curr.second);

        for(auto neighbor : graph[curr.second]) {
            if(!visited.count(neighbor.first) && mp[neighbor.first] > mp[curr.second] + neighbor.second) {
                pq.push({mp[curr.second] + neighbor.second, neighbor.first});
                mp[neighbor.first] = mp[curr.second] + neighbor.second;
                via[neighbor.first] = curr.second;
            }
        }
    }
    return mp;
}

int main() {
    int v,e;
    cin>>v>>e;

    graph.resize(v, list<pp>());

    while(e--) {
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
    cout<<"Graph construction is done!"<<endl;
    int source;
    cin>>source;
    unordered_map<int,int> shortest_dist = dijkstra(source,v);

    for(auto p : shortest_dist) {
        //first -> node, second -> shortest dist from src to node
        cout<<p.first<<" "<<p.second<<endl; 
    }


    return 0;
}