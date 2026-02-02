#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int cost = prices[0];
        for(int i=1; i<prices.size(); i++) {
            cost = min(cost, prices[i]);
            if(prices[i] > cost) {
                profit = max(profit, prices[i] - cost);
            }
        }
        return profit;
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