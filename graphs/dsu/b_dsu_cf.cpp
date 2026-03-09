#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;
vector<int> minimal;
vector<int> maximal;
vector<int> Size;

int find(int x) {
    return parent[x] = (parent[x] == x) ? parent[x] : find(parent[x]);
}

void get(int x) {
    x = find(x);
    cout<<minimal[x]<<" "<<maximal[x]<<" "<<Size[x]<<endl;
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if(a != b) {
        if(Size[a] >= Size[b]) {
            parent[b] = parent[a];
            minimal[a] = min(minimal[a],minimal[b]);
            maximal[a] = max(maximal[a],maximal[b]);
            Size[a] += Size[b];
        } else {
            parent[a] = parent[b];
            minimal[b] = min(minimal[a],minimal[b]);
            maximal[b] = max(maximal[a],maximal[b]);
            Size[b] += Size[a];
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;

    parent.resize(n+1);
    minimal.resize(n+1);
    maximal.resize(n+1);
    Size.resize(n+1,1);

    for(int i=0; i<n+1; i++) {
        parent[i] = i;
        minimal[i] = i;
        maximal[i] = i;
    }

    while(m--) {
        string s;
        cin>>s;
        if(s == "union") {
            int a, b;
            cin>>a>>b;
            Union(a,b);
        } else {
            int x;
            cin>>x;
            get(x);
        }
    }


    return 0;
}