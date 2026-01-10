#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int f(vector<int>& arr, int i) {
    if(i >= arr.size()) return 0;
    if(dp[i] != -1) return dp[i];

    return dp[i] = max(arr[i] + f(arr,i+2), f(arr,i+1));

}

int rob2(vector<int>& arr) {
    if(arr.size() == 1) return arr[0];
    else if(arr.size() == 2) return max(arr[0],arr[1]);
    dp.clear();
    dp.resize(105,-1);
    int a = f(arr,0);
    dp.clear();
    dp.resize(105,-1);
    int b = f(arr,1);

    return max(a,b);

}

int main() {
    int n;
    cin>>n;

    vector<int> nums;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    cout<<rob2(nums);

    return 0;
}