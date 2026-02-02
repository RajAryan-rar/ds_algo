#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    vector<int> price;
    int dp[1005][105][2];

    int f(int i, int k, bool on) {
        if(i == price.size() || k <= 0) return 0;
        if(dp[i][k][on] != -1) return dp[i][k][on];

        int ans = f(i+1,k,on); //ignore

        if(on == false && k > 0) { //buy
            ans = max(ans, -price[i] + f(i+1,k,true));
        } else { //sell
            ans = max(ans, price[i] + f(i+1,k-1,false));
        }

        return dp[i][k][on] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        price = prices;
        memset(dp, -1, sizeof dp);
        return f(0,k,false);
    }
};

int main() {
    int n,k;
    cin>>n>>k;

    vector<int> prices(n);

    for(int i=0; i<n; i++) {
        cin>>prices[i];
    }

    Solution s;
    cout<<s.maxProfit(k,prices);

    return 0;
}