#include<iostream>
#include<vector>
using namespace std;


vector<int> parent;
vector<int> Rank;

int find(int x) {
    return parent[x] = (parent[x] == x) ? parent[x] : find(parent[x]);
}

void get(int a, int b) {
    a = find(a);
    b = find(b);

    (a == b) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if(a != b) {
        if(Rank[a] == Rank[b]) {
            parent[b] = a;
            Rank[a]++;
        } else if(Rank[a] > Rank[b]) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    
    parent.resize(n+1);
    for(int i=0; i<n+1; i++) parent[i] = i;

    Rank.resize(n+1,0);

    while(m--) {
        string s;
        cin>>s;
        if(s == "union") {
            int a,b;
            cin>>a>>b;

            Union(a,b);
        } else {
            int a,b;
            cin>>a>>b;
            get(a,b);
        }
    }

    return 0;
}