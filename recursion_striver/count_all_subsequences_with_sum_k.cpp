#include<iostream>
#include<vector>
using namespace std;


int f(vector<int>& nums, int i, int target) {
    if(target == 0) return 1;
    if(target < 0 || i >= nums.size()) return 0;
    
    return f(nums,i+1,target) + f(nums,i+1,target-nums[i]);
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }

    cout<<f(v,0,k);

    return 0;
}