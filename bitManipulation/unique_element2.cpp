#include<iostream>
#include<vector>
using namespace std;

void unique_elements(vector<int>& arr) {
    int res = 0;
    for(int i=0; i<arr.size(); i++) res ^= arr[i];

    int temp = res;
    int k = 0;

    while(true) {
        if((temp & 1) == 1) break;
        temp >>= 1;
        k++;
    }

    int retVal = 0;
    for(int i=0; i<arr.size(); i++) {
        if(((arr[i] >> k) & 1) == 1) retVal ^= arr[i];
    }
    int num1 = retVal;
    int num2 = res^retVal;

    cout<<num1<<" "<<num2;
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

    unique_elements(v);

    return 0;
}