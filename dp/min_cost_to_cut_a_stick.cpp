#include<iostream>
#include<vector>
#include<climits>
#include<algorithm> 
using namespace std;

vector<int> arr;
vector<vector<int>> dp;

int f(int i, int j) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;

    for(int k=i; k<=j; k++) {
        ans = min(ans, f(i,k-1) + f(k+1,j) + arr[j+1]-arr[i-1]);
    }
    return dp[i][j] = ans;
}

int main() {
    int n,c;
    cin>>n>>c;

    vector<int> cuts(c);
    for(int i=0; i<c; i++) {
        cin>>cuts[i];
    }

    arr = cuts;
    arr.insert(arr.begin(), 0);
    arr.push_back(n);

    sort(arr.begin(), arr.end());

    dp.clear();
    dp.resize(arr.size(), vector<int>(arr.size(),-1));

    cout<<f(1,arr.size()-2);


    return 0;
}