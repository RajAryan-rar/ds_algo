#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int find(int x, vector<int>& parent) {
        return parent[x] = (parent[x] == x) ? x : find(parent[x],parent);
    }

    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find(a, parent);
        b = find(b, parent);

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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0; i<n; i++) parent[i] = i;
        for(int i=0; i<connections.size(); i++) {
            int a = connections[i][0];
            int b = connections[i][1];

            Union(a,b,parent,rank);
        }

        int cc = 0;
        for(int i=0; i<n; i++) {
            if(parent[i] == i) {
                cc++;
                cout<<parent[i]<<" ";
            }
        
        }
        return cc-1;
    }
};

int main() {
    int v,e;
    cin>>v>>e;

    vector<vector<int>> connections(e,vector<int>(2));

    for(int i=0; i<e; i++) {
        cin>>connections[i][0]>>connections[i][1];
    }

    Solution s;
    cout<<s.makeConnected(v,connections);

    return 0;
}