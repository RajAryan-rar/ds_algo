#include<iostream>
#include<vector>
using namespace std;

void f(vector<int> arr, int idx) {
    if(idx >= arr.size()) return;

    cout<<arr[idx]<<" ";

    f(arr, idx+1);
}

int main() {
    f({2,1,3,5,4}, 0);

    return 0;
}