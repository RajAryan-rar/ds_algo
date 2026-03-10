#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> revGraph(v);
        vector<int> indeg(v);

        for(int i=0; i<v; i++) {
            for(auto node : graph[i]) {
                revGraph[node].push_back(i);
                indeg[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<v; i++) {
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> result;
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            result.push_back(curr);

            for(auto neighbor : revGraph[curr]) {
                indeg[neighbor]--;
                if(indeg[neighbor] == 0) q.push(neighbor);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};

int main() {    
    int v;
    vector<vector<int>> graph(v);

    for(int i=0; i<v; i++) {
        int e;
        cin>>e;
        while(e--) {
            int x;
            cin>>x;
            graph[i].push_back(x);
        }
    }

    Solution s;

    vector<int> ans = s.eventualSafeNodes(graph);

    for(auto ele : ans) cout<<ele<<" ";

    return 0;
}