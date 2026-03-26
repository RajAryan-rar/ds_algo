#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minCost(vector<int>& x, vector<int>& y) {
    sort(x.begin(),x.end(),greater<int>());
    sort(y.begin(),y.end(),greater<int>());

    int hPieces = 1, vPieces = 1;
    int i = 0, j = 0, cost = 0;
    while(i < x.size() && j < y.size()) {
        if(x[i] > y[j]) {
            cost += x[i] * vPieces;
            hPieces++;
            i++;
        } else {
            cost += y[j] * hPieces;
            vPieces++;
            j++;
        }
    }
    while(i < x.size()) {
        cost += x[i] * vPieces;
        hPieces++;
        i++;
    }
    while(j < y.size()) {
        cost += y[j] * hPieces;
        vPieces++;
        j++;
    }
    return cost;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int m,n;
        cin>>m>>n;
        vector<int> x(m-1), y(n-1);
        for(int i=0; i<m-1; i++) cin>>x[i];
        for(int i=0; i<n-1; i++) cin>>y[i];
        cout<<minCost(x,y)<<endl;
    }

    return 0;
}