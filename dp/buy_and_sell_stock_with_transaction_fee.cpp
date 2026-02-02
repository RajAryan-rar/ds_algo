#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define ll long long int

class Solution {
public:

    vector<int> price;
    ll dp[50005][2];
    int fees;

    ll f(int i, bool on) {
        if(i == price.size()) return 0;
        if(dp[i][on] != -1) return dp[i][on];

        ll ans = f(i+1,on); //ignore

        if(on == false) { //buy
            ans = max(ans, (ll)(-price[i] + f(i+1,true)));
        } else { //sell
            ans = max(ans, (ll)(price[i] + f(i+1,false) - fees));
        }

        return dp[i][on] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        price = prices;
        fees = fee;
        memset(dp, -1, sizeof dp);
        return f(0,false);
    }
};

int main() {
    int fee,n;
    cin>>fee>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    Solution s;
    cout<<s.maxProfit(arr,fee);

    return 0;
}