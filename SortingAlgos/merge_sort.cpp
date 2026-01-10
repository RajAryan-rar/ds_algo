#include<iostream>
#include<vector>
using namespace std;

vector<int> merge_two_sorted_arrays(vector<int>& a, vector<int>& b) {
    int m = a.size(), n = b.size();
    int i=0,j=0,k=0;

    vector<int> result(m+n);

    while(i<m && j<n) {
        if(a[i] < b[j]) result[k++] = a[i++]; 
        else result[k++] = b[j++];
    }

    while(i<m) result[k++] = a[i++];
    while(j<n) result[k++] = b[j++];

    return result;
}

vector<int> f(vector<int> &arr, int i, int j) {
    if(i == j) return vector<int> {arr[i]};

    int mid = (i+j)/2;

    vector<int> left = f(arr,i,mid);
    vector<int> right = f(arr,mid+1,j);
    vector<int> result = merge_two_sorted_arrays(left,right);

    return result;
}

void merge_sort(vector<int> &arr) {
    arr = f(arr,0,arr.size()-1);
}

int main() {
    vector<int> arr = {6,5,4,3,2,1};

    merge_sort(arr);

    for(auto ele : arr) {
        cout<<ele<<" ";
    }

    return 0;
}