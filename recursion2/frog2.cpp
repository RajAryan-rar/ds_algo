#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Approach -1
int f(vector<int>& arr, int k, int i) {
    if(i >= arr.size()) return INT_MAX;
    if(i == arr.size()-1) return 0;
    if(i == arr.size()-2) {
        return f(arr, k, i+1) + abs(arr[i] - arr[i+1]);
    }
    int minCost = INT_MAX;
    for(int j=1; j<=k && i+j<arr.size(); j++) {
        minCost = min(minCost, f(arr,k,i+j) + abs(arr[i] - arr[i+j]));
    }
    return minCost;
}

//Approach -2

int main() {
    int n,k;
    cin>>n>>k;

    vector<int> arr;
    arr.push_back(0);

    for(int i=0; i<n; i++) {
        int x;
        cin>>x;

        arr.push_back(x);
    }

    cout<<f(arr,k,1);

    return 0;
}