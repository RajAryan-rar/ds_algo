#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<climits>
using namespace std;

#define pp pair<int,int>
#define ll long long int
#define inf INT_MAX

vector<list<pp>> graph;

void add_edge(int src, int dest, int wt, bool bi_dir = true) {
    graph[src].push_back({dest,wt});
    if(bi_dir) graph[dest].push_back({src,wt});
}

ll prims(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> visited;
    vector<int> par(n+1);
    unordered_map<int,int> mp;

    for(int i=0; i<=n; i++) mp[i] = inf;

    pq.push({0,src});
    mp[src] = 0;

    int totalVertices = 0; //n
    ll result = 0; //sum of weights

    while(totalVertices<n && !pq.empty()) {
        pp curr = pq.top();
        pq.pop();

        if(visited.count(curr.second)) continue;

        visited.insert(curr.second);
        totalVertices++;
        result += curr.first;

        for(auto neighbor : graph[curr.second]) {
            if(!visited.count(neighbor.first) && mp[neighbor.first] > neighbor.second) {
                pq.push({neighbor.second, neighbor.first});
                par[neighbor.first] = curr.second;
                mp[neighbor.first] = neighbor.second; 
            }
        }
    }
    return result;
}


int main() {
    int v,e;
    cin>>v>>e;
    
    graph.resize(v+1, list<pp>());

    while(e--) {
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }

    int src;
    cin>>src;
    cout<<prims(src,v);

    

    return 0;
}