#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp;

int f(vector<vector<char>>& arr, int i, int j) {
    if(i == arr.size()-1 && j == arr[0].size()-1) {
        if(arr[i][j] == '*') return 0;
        return 1;
    }
    if(i >= arr.size() || j >= arr[0].size() || arr[i][j] == '*') return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = f(arr,i+1,j) + f(arr,i,j+1);
    return dp[i][j] = ans % 1000000007;
}

int main() {
    int n;
    cin>>n;

    vector<vector<char>> v(n, vector<char>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char ch;
            cin>>ch;
            v[i][j] = ch;
        }
    }
    dp.clear();
    //matrix.resize(rows, std::vector<int>(columns, initialValue));
    dp.resize(n,vector<int>(n,-1));
    cout<<f(v,0,0);

    return 0;
}