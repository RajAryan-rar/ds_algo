#include<iostream>
#include<vector>
#include<algorithm>
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

    static bool cmp(vector<int>& c1, vector<int>& c2) {
        /**
         * c1 --> connection 1
         * c2 --> connection 2
         *  */        

        return c1[2] < c2[2];
    }

    
    // n-->no_of_cities or vertices       
    int minimumCost(int n, vector<vector<int>>& connections) {
        //connections[i] -> city1, city2, cost

        sort(connections.begin(), connections.end(), cmp);

        vector<int> parent(n+1);
        vector<int> rank(n+1,0);
        for(int i=0; i<n+1; i++) parent[i] = i;

        int edgeCount = 0; //n-1;
        int i = 0;
        int minCost = 0;

        while(edgeCount < n-1 && i < connections.size()) {
            vector<int> edge = connections[i];
            int srcPar = find(edge[0],parent);
            int destPar = find(edge[1],parent);

            if(srcPar != destPar) {
                Union(srcPar,destPar,parent,rank);
                edgeCount++;
                minCost += edge[2];
            }
            i++;
        }
        return (edgeCount == n-1) ? minCost : -1;
    }
};

int main() {
    int v,e;
    cin>>v>>e;

    vector<vector<int>> connections(e, vector<int>(3));

    for(int i=0; i<e; i++) {
        cin>>connections[i][0]>>connections[i][1]>>connections[i][2];
    }

    Solution s;

    cout<<s.minimumCost(v,connections);


    return 0;
}