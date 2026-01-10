#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<int> arr;

// Approach -1
int f(int i) {
    if(i == arr.size() - 1) return 0;
    if(i == arr.size() - 2) {
        return f(i+1) + abs(arr[i] - arr[i+1]);
    }

    return min(f(i+1) + abs(arr[i] - arr[i+1]), f(i+2) + abs(arr[i] - arr[i+2]));
}

//Approach -2 : fixed -> both the solutions are working fine
int g(int n) {
    if(n == 1) return 0;
    if(n == 2) return g(n-1) + abs((arr[n] - arr[n-1]));

    return min(g(n-1) + abs(arr[n-1] - arr[n]), g(n-2) + abs(arr[n-2] - arr[n]));
}

int main() {
    int n;
    cin>>n;
    arr.push_back(0);

    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<g(n);

    return 0;
}