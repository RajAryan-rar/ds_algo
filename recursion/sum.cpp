#include<iostream>
#include<vector>
using namespace std;

int f(vector<int> &v, int i) {
    if(i == v.size()-1) return v[i];
    return v[i] + f(v,i+1);
}

int main() {
    vector<int> v = {1,2,3,4,5};
    cout<<f(v,0);

    return 0;
}