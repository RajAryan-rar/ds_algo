#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int>> dp;

//TLE!!! for top down
int f(int i, int j) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int vCut = INT_MAX;

    for(int k=1; k<j; k++) {
        vCut = min(vCut, 1+ f(i,k) + f(i,j-k));
    }

    int hCut = INT_MAX;
    for(int k=1; k<i; k++) {
        hCut = min(hCut, 1+ f(k,j)+ f(i-k,j));
    }

    return dp[i][j] = min(hCut,vCut);
}

int f_bu(int a, int b) {
    for(int i=0; i<=a; i++) {
        for(int j=0; j<=b; j++) {
            if(i == j) dp[i][j] = 0;
            else {
                //horizontal cuts
                for(int k=1; k<i; k++) {
                    dp[i][j] = min(dp[i][j], 1+ dp[i-k][j] + dp[k][j]);
                }
                //vertical cuts
                for(int k=1; k<j; k++) {
                    dp[i][j] = min(dp[i][j], 1+ dp[i][k] + dp[i][j-k]);
                }
            }
        }
    }
    return dp[a][b];
}

int main() {
    int a,b;
    cin>>a>>b;

    dp.resize(a+1, vector<int>(b+1,INT_MAX));
    
    cout<<f_bu(a,b);

    return 0;
}