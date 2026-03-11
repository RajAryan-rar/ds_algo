#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;


int find(int x, vector<int>& parent) {
    return parent[x] = (parent[x] == x) ? x : find(parent[x],parent);
}

void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a,parent);
    b = find(b,parent);

    if(a == b) return;
    
    if(rank[a] >= rank[b]) {
        parent[b] = parent[a];
        rank[a]++;
    } else {
        parent[a] = parent[b];
        rank[b]++;
    }
    return;
}

struct Edge
{
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}

ll kruskal(vector<Edge>& input, int v) {
    sort(input.begin(),input.end(),cmp);
    vector<int> parent(v+1);
    vector<int> rank(v+1,0);

    for(int i=0; i<v+1; i++) parent[i] = i;

    int edgeCount = 0; //v-1
    int i = 0;
    ll ans = 0;

    while(edgeCount < v-1 && i < input.size()) {
        Edge curr = input[i];
        int srcPar = find(curr.src,parent);
        int destPar = find(curr.dest,parent);

        if(srcPar != destPar) {
            Union(srcPar,destPar,parent,rank);
            ans += curr.wt;
            edgeCount++;
        }
        i++;
    }
    return ans;
}


int main() {
    int v, e;
    cin>>v>>e;

    vector<Edge> edges(e);

    for(int i=0; i<e; i++) {
        cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
    }

    cout<<kruskal(edges,v)<<endl;
    

    return 0;
}