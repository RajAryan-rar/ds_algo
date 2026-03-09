#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Solution {
public:
    vector<list<int>> graph;
    int v;

    void add_edge(int a, int b, bool bi_dir=true) {
        graph[a].push_back(b);
        if(bi_dir) graph[b].push_back(a);
    }

    bool canFinish(int numCourses , vector<vector<int>>& prerequisites ) {
        v = numCourses ;
        graph.clear();
        graph.resize(v);
        for(int i=0; i<prerequisites .size(); i++) {
            int a = prerequisites [i][1];
            int b = prerequisites [i][0];

            add_edge(a,b,false);
        }
        
        vector<int> indeg(v,0);
        for(int i=0; i<v; i++) {
            for(auto neighbor : graph[i]) {
                indeg[neighbor]++;
            }
        }

        queue<int> q;
        for(int i=0; i<v; i++) {
            if(indeg[i] == 0) q.push(i);
        }

        int count = 0;
        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            count++;

            for(auto neighbor : graph[curr]) {
                indeg[neighbor]--;
                if(indeg[neighbor] == 0) q.push(neighbor);    
            }
        }
        return count == v;
    }
};

int main() {
    int numCourses;
    cin>>numCourses;
    
    int e;
    cin>>e;
    vector<vector<int>> prereqs(e, vector<int>(2));

    for(int i=0; i<e; i++) {
        cin>>prereqs[i][0]>>prereqs[i][1];
    }

    Solution s;
    if(s.canFinish(numCourses,prereqs)) cout<<"true";
    else cout<<"false";

    return 0;
}