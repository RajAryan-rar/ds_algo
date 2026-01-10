#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int maxElement(vector<int> &v, int i) {
    // if(i >= v.size()) return -1;
    // return max(v[i], maxElement(v, i+1));

    return (i == v.size()-1) ? v[i] : max(v[i], maxElement(v, i+1));
}

int main() {
    vector<int> v = {3,5,4,2,7,1,6};
    cout<<maxElement(v, 0);

    return 0;
}