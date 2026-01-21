#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define ll long long int

vector<int> arr;
ll dp[5005][5005];

ll f(int i, int j) {
    if(j - i == 0) {
        return arr[i]; //single length subarray
    }
    if(j - i == 1) {
        return max(arr[i], arr[j]); // 2 length subarray
    }
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(arr[i] + min(f(i+2,j), f(i+1,j-1)), arr[j] + min(f(i,j-2), f(i+1,j-1)));
}

ll f_bu() {
    int n = arr.size();
    for(int len=1; len<=n; len++) {
        for(int i=0; i+len<=n; i++) {
            int j = i+len-1;
            if(len == 1) {
                dp[i][j] = arr[i];
            } 
            else if(len == 2) {
                dp[i][j] = max(arr[i],arr[j]);
            }
            else {
                ll x = (i+2 <= j) ? dp[i+2][j] : 0;
                ll y = (i+1 <= j-1) ? dp[i+1][j-1] : 0;
                ll z = (i <= j-2) ? dp[i][j-2] : 0;

                dp[i][j] = max(arr[i] + min(x,y), arr[j] + min(y,z));
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int n;
    cin>>n;

    arr.resize(n);
    memset(dp,-1,sizeof(dp));

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<f_bu();

    return 0;
}