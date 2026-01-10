#include<iostream>
#include<vector>
using namespace std;

int uniqueElement(vector<int>& arr) {
    int result = 0;
    for(int i=0; i<arr.size(); i++) {
        result = result ^ arr[i];
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }    

    cout<<uniqueElement(v);

    return 0;
}