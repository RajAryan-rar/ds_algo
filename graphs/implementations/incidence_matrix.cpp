#include<iostream>
#include<vector>
using namespace std;

int main() {
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>> mat(v, vector<int>(e));

    for(int i=0; i<e; i++) {
        int u,v;
        cin>>u>>v;

        if(u == v) {
            mat[u][i] = 2;
            continue;
        }
        mat[u][i] = 1;
        mat[v][i] = 1;
    }

    for(int i=0; i<v; i++) {
        for(int j=0; j<e; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}