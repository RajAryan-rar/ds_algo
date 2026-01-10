#include<iostream>
#include<vector>
using namespace std;

//Qs. given an array sorted in ascending order.
    //find the index of the first element greater than or equals x
int findIndex(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    int idx = -1;
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;

        if(arr[mid] >= target) {
            idx = mid;
            hi = mid-1;
        } 
        else {
            lo = mid + 1;
        }
    }
    return idx;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr;

    while(n--) {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int target;
    cin>>target;

    cout<<findIndex(arr,target);

    return 0;
}