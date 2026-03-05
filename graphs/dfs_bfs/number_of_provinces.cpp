#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
        visited[node] = true;
        for(auto neighbor : graph[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor,visited,graph);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1 && i != j) adjList[i].push_back(j);
            }
        }     

        vector<bool> visited(n,false);

        int count = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(i,visited,adjList);
            }
        } 
        return count;
    }
};

int main() {
    int n;
    cin>>n;

    vector<vector<int>> isConnected(n,vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>isConnected[i][j];
        }
    }

    Solution s;
    cout<<s.findCircleNum(isConnected);

    return 0;
}