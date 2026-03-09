#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int find(int x, vector<int>& parent) {
        return parent[x] = (parent[x] == x) ? parent[x] : find(parent[x],parent);
    }
    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find(a,parent);
        b = find(b,parent);

        if(a != b) {
            if(rank[a] >= rank[b]) {
                parent[b] = parent[a];
                rank[a]++;
            } else {
                parent[a] = parent[b];
                rank[b]++;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,int> mr;
        unordered_map<int,int> mc;

        int v = stones.size();

        vector<int> parent(v);
        vector<int> rank(v,0);
        for(int i=0; i<v; i++) parent[i] = i;

        for(int i=0; i<v; i++) {
            int r = stones[i][0];
            int c = stones[i][1];

            if(mr.find(r) != mr.end()) {
                Union(mr[r],i,parent,rank);
            } else {
                mr[r] = i;
            }
            if(mc.find(c) != mc.end()) {
                Union(mc[c],i,parent,rank);
            } else {
                mc[c] = i;
            }
        }    

        int cc = 0;
        for(int i=0; i<v; i++) {
            if(parent[i] == i) cc++;
        } 
        return v - cc;   

    }
};

int main() {
    int n;
    cin>>n;

    vector<vector<int>> stones(n, vector<int>(2));

    for(int i=0; i<n; i++) {
        cin>>stones[i][0]>>stones[i][1];
    }

    Solution s;
    cout<<s.removeStones(stones);

    return 0;
}