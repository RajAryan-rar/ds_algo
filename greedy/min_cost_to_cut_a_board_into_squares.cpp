#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        int hPieces = 1, vPieces = 1;
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        
        int totalCost = 0;
        
        int i = 0, j = 0;
        while(i < x.size() && j < y.size()) {
            if(x[i] >= y[j]) {   //vertical cut
                totalCost += (x[i] * hPieces);
                vPieces++;
                i++;
            } else {    //horizontal cut
                totalCost += (y[j] * vPieces);
                hPieces++;
                j++;
            }
        }
        while(i < x.size()) {
            totalCost += (x[i] * hPieces);
            vPieces++;
            i++;
        }
        while(j < y.size()) {
            totalCost += (y[j] * vPieces);
            hPieces++;
            j++;
        }
        return totalCost;
    }
};


int main() {
    int n, m;
    cin>>n>>m;

    int xs,ys;
    cin>>xs>>ys;

    vector<int> x(xs), y(ys);

    for(int i=0; i<xs; i++) cin>>x[i];
    for(int i=0; i<ys; i++) cin>>y[i];

    Solution s;
    cout<<s.minCost(n,m,x,y);

    return 0;
}