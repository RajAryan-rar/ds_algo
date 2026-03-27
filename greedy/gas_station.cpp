#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total = 0, tank = 0, start = 0;

        for(int i=0; i<n; i++) {
            int diff = gas[i]-cost[i];
            total += diff;
            tank += diff;

            if(tank < 0) {
                tank = 0;
                start = i+1;
            }
        }
        return total >= 0 ? start : -1;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> gas(n), cost(n);

    for(int i=0; i<n; i++) cin>>gas[i];
    for(int i=0; i<n; i++) cin>>cost[i];

    Solution s;
    cout<<s.canCompleteCircuit(gas,cost)<<endl;

    return 0;
}