#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

unordered_set<int> st;
vector<int> arr;
vector<int> cost;

vector<int> dp;

int f(int d) {
    if(d > arr[arr.size()-1]) return 0;
    if(dp[d] != -1) return dp[d];
    if(st.find(d) == st.end()) return f(d+1);

    return dp[d] = min(cost[0]+f(d+1), min(cost[1]+f(d+7), cost[2]+f(d+30)));
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    for(int i=0; i<days.size(); i++) {
        st.insert(days[i]);
    }
    arr = days;
    cost = costs;
    dp.clear();
    dp.resize(370,-1);

    return f(1);
}

int main() {
    int n;
    cin>>n;

    vector<int> days(n);
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        days[i] = x;
    }

    vector<int> costs(3);
    for(int i=0; i<3; i++) {
        int x;
        cin>>x;
        costs[i] = x;
    }

    cout<<mincostTickets(days,costs);

    return 0;
}