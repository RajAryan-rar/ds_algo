#include<iostream>
#include<vector>
using namespace std;

#define ll long long int 
class Solution {
public:
    int find(int x, vector<int>& parent) {
        return parent[x] = (parent[x] == x) ? parent[x] : find(parent[x],parent);
    }

    void Union(int a, int b, vector<int>& parent, vector<int>& size) {
        a = find(a, parent);
        b = find(b, parent);
    
        if(a != b) {
            if(size[a] >= size[b]) {
                parent[b] = parent[a];
                size[a] += size[b];
            } else {
                parent[a] = parent[b];
                size[b] += size[a];
            }
        }

    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<int> parent(n), size(n,1);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        for(int i=0; i<e; i++) {
            Union(edges[i][0],edges[i][1],parent,size);
        }

        vector<int> componentSize;

        for(int i=0; i<n; i++) {
            if(parent[i] == i) componentSize.push_back(size[i]);
        }        
        int s = componentSize.size();
        
        ll totalPairs = (ll)n * (n-1) / 2;
        ll reachablePairs = 0;

        for(ll ele : componentSize) {
            reachablePairs += (ll)(ele * (ele-1) / 2);
        }

        return totalPairs - reachablePairs;
    }
};

int main() {
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>> edges(e, vector<int>(2));

    for(int i=0; i<e; i++) {
        cin>>edges[i][0]>>edges[i][1];
    }

    Solution s;
    cout<<s.countPairs(v,edges);

    return 0;
}