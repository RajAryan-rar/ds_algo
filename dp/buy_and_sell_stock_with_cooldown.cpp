#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    vector<int> price;
    int dp[5005][2];

    int f(int i, bool on) {
        if(i >= price.size() ) return 0;
        if(dp[i][on] != -1) return dp[i][on];

        int ans = f(i+1,on); //ignore

        if(on == false) { //buy
            ans = max(ans, -price[i] + f(i+1,true));
        } else { //sell
            ans = max(ans, price[i] + f(i+2,false)); //cooldown
        }

        return dp[i][on] = ans;
    }

    int maxProfit(vector<int>& prices) {
        price = prices;
        memset(dp, -1, sizeof dp);
        return f(0,false);
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    Solution s;
    cout<<s.maxProfit(arr);

    return 0;
}