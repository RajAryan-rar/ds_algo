#include<iostream>
#include<vector>
using namespace std;

// Qs. given an array of non negative elements. Find smallest missing element
int smallestMissingElement(vector<int>& arr) {
    if(arr[0] != 0) return 0;
    int lo = 0, hi = arr.size()-1;
    int ele = arr.size();

    while(lo <= hi) {
        int mid = (lo + (hi-lo)/2);
        if(arr[mid] == mid) lo = mid+1;
        else {
            ele = mid;
            hi = mid-1;
        }
    }
    return ele;
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

    cout<<smallestMissingElement(arr);

    return 0;
}