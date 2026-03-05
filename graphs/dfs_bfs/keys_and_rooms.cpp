#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    unordered_set<int> visited;
    
    bool bfs(vector<vector<int>>& rooms) {
        visited.insert(0);
        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(auto neighbor : rooms[curr]) {
                if(visited.count(neighbor) == 0) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return visited.size() == rooms.size();
    }

    void dfs(int src, vector<vector<int>>& rooms) {
        visited.insert(src);
        for(auto neighbor : rooms[src]) {
            if(!visited.count(neighbor)) {
                visited.insert(neighbor);
                dfs(neighbor,rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // return bfs(rooms);

        dfs(0,rooms);
        return visited.size() == rooms.size();
    }
};

int main() {
    int n;
    cin>>n;

    vector<vector<int>> rooms(n);
    for(int i=0; i<n; i++) {
        int s;
        cin>>s;
        while(s--) {
            int x;
            cin>>x;
            rooms[i].push_back(x);
        }
    }

    Solution s;
    if(s.canVisitAllRooms(rooms)) cout<<"true";
    else cout<<"false";

    return 0;
}