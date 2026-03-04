#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dag;
    vector<vector<int>> result;
    vector<bool> visited;
    void dfs(int start, int end, vector<int> v) {
        v.push_back(start);
        if(start == end) {
            result.push_back(v);
            return;
        }
        visited[start] = true;
        for(auto neighbor : dag[start]) {
            if(!visited[neighbor]) {
                dfs(neighbor,end,v);
            }
        }
        v.pop_back();
        visited[start] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dag = graph;
        visited.resize(dag.size(), false);
        int source = 0, destination = dag.size()-1;
        vector<int> paths;
        dfs(source,destination, paths);
        return result;
    }
};

int main() {
    int n;
    cin>>n;

    vector<vector<int>> graph(n);
    for(int i=0; i<n; i++) {
        int e;
        cin>>e;
        while(e--) {
            int x;
            cin>>x;
            graph[i].push_back(x);
        }
    }

    Solution s;
    vector<vector<int>> result = s.allPathsSourceTarget(graph);

    for(auto v : result) {
        for(auto ele : v) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}