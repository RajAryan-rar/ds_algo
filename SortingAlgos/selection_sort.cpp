#include<iostream>
#include<vector>
using namespace std;

//selection sort -> first part of the array is sorted and other is not sorted

int getMinIndex(vector<int>& arr, int i) {
    int minIdx = i;
    for(int j=i; j<arr.size(); j++) { //search for minElement in the unsorted array
        if(arr[j] < arr[minIdx]) minIdx = j;
    }
    return minIdx; //return index of minElement in the unsorted part of the array
}

void selectionSort(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) {
        int minIdx = getMinIndex(arr,i);
        swap(arr[i],arr[minIdx]);
    }
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

    selectionSort(arr);

    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}