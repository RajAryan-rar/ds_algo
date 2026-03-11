#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int find(int x, vector<int>& parent) {
        return parent[x] = (parent[x] == x) ? x : find(parent[x], parent);
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

    struct Edge {
        int src;
        int dest;
        int wt;
    };

    static bool cmp(Edge &e1, Edge &e2) {
        return e1.wt < e2.wt;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<int> parent(v+1);
        vector<int> rank(v+1,0);

        for(int i=0; i<v+1; i++) parent[i] = i;
        vector<Edge> input;
        for(int i=0; i<v; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<v; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int cost = abs(x2-x1) + abs(y2-y1);
                input.push_back({i,j,cost});
            }
        }
        sort(input.begin(), input.end(), cmp);

        int edgeCount = 0;
        int i = 0;
        int ans = 0;

        while(edgeCount < v-1 && i < input.size()) {
            Edge curr = input[i];
            int srcPar = find(curr.src, parent);
            int destPar = find(curr.dest, parent);
            if(srcPar != destPar) {
                Union(srcPar, destPar, parent, rank);
                edgeCount++;
                ans += curr.wt;
            }
            i++;
        }
        return ans;
    }
};

int main() {
    int v;
    cin>>v;

    vector<vector<int>> points(v, vector<int>(2));

    for(int i=0; i<v; i++) {
        cin>>points[i][0]>>points[i][1];
    }

    Solution s;
    cout<<s.minCostConnectPoints(points);

    return 0;
}