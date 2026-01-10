#include<iostream>
#include<vector>
using namespace std;

void f(vector<int> &arr, int k, int i) {
    if(k == 0) return;
    if(i == k) {
        f(arr,k-1,0);
        return;
    }

    if(arr[i] > arr[i+1]) {
        swap(arr[i],arr[i+1]);
        f(arr,k,i+1);
    }
    if(i == arr.size()-1) f(arr,k-1,0);
}


int main() {
    vector<int> arr = {5,4,3,2,1};
    
    f(arr,arr.size()-1,0);

    for(auto ele : arr) {
        cout<<ele<<" ";
    }

    return 0;
}