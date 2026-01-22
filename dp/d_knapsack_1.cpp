#include<iostream>
#include<vector>
using namespace std;

#define ll long long int

vector<vector<int>> arr;
vector<vector<ll>> dp;

ll f(int i, int capacity) {
    if(i >= arr.size()) return 0;
    if(dp[i][capacity] != -1) return dp[i][capacity];
    
    ll pick = 0;
    if(arr[i][0] <= capacity) {
        pick = arr[i][1] + f(i+1,capacity-arr[i][0]);
    }
    ll not_pick = f(i+1,capacity);

    return dp[i][capacity] = max(pick, not_pick);
}


int main() {
    int N,W;
    cin>>N>>W;

    arr.resize(N,vector<int>(2));

    for(int i=0; i<N; i++) {
        cin>>arr[i][0]>>arr[i][1];
    }
    dp.resize(105, vector<ll>(100005,-1));
    cout<<f(0,W);


    return 0;
}