#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n == 1) return cost[0];
        else if(n == 2) return cost[0] + cost[1];
        sort(cost.begin(),cost.end());

        int minCost = 0, currMin = INT_MAX;
        for(int i=n-1; i>=0; i-=3) {
            minCost += cost[i];
            if(i-1 >= 0) minCost += cost[i-1];
        }
        return minCost;
    }
};

int main() {
	int n;
	cin>>n;
	vector<int> cost(n);

	for(int i=0; i<n; i++) cin>>cost[i];

	Solution s;
	cout<<s.minimumCost(cost)<<endl;

	return 0;
}
