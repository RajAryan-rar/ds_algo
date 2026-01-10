#include<iostream>
#include<vector>
using namespace std;

int f(vector<int> arr, int idx, int target) {
    if(idx >= arr.size()) return -1;

    // if(arr[idx] == target) return idx;
    // return f(arr,idx+1,target);

    return (arr[idx] == target) ? idx : f(arr,idx+1,target); 
}

int main() {
    cout<<f({2,1,3,5,4}, 0, 3);

    return 0;
}