#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//m1 a.
int f(vector<int> arr, int idx) {
    return (idx >= arr.size()) ? 0 : max(arr[idx]+f(arr,idx+2), f(arr,idx+1));
}


int main() {
    cout<<f({3,1,1,9}, 3);

    return 0;
}