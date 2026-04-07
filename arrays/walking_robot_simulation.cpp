#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

#define ll long long int
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<ll> st;
        for(int i=0; i<obstacles.size(); i++) {
            int x = obstacles[i][0];
            int y = obstacles[i][1];

            ll key = ((ll)x << 32) | (unsigned int)y;

            st.insert(key);
        }

        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int ans = 0;
        int d = 0, x = 0, y = 0;

        for(int cmd : commands) {
            if(cmd == -1) d = (d+1)%4; //turn right
            else if(cmd == -2) d = (d+3)%4;
            else {
                while(cmd--) {
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];

                    ll key = ((ll)nx << 32) | (unsigned int)ny;

                    if(st.count(key)) break;

                    x = nx;
                    y = ny;

                    ans = max(ans, nx*nx+ny*ny);
                }
            }
        }
        return ans;
    }
};

int main() {
    int n,m;
    cin>>n>>m;

    vector<int> commands(n);
    vector<vector<int>> obstacles(m, vector<int>(2));

    Solution s;
    cout<<s.robotSim(commands,obstacles)<<endl;

    return 0;
}