#include<iostream>
#include<vector>
using namespace std;

int find(int x, vector<int>& parent) {
    return parent[x] = (parent[x] == x) ? parent[x] : find(parent[x], parent);
}

bool Union(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a, parent);
    b = find(b, parent);

    //Below logic maintains a particular representive
    if(a != b) {
        if(rank[a] >= rank[b]) {
            parent[b] = a;
            rank[a]++;
        } else {
            parent[a] = b;
            rank[b]++;
        }
        return false;
    }
    return true;

    //Below logic is better it doesn't maintains a particular representive(like union by size)
    /*
    if (a != b) { // Important: Only union if they are in different sets
        if (rank[a] < rank[b]) {
            parent[a] = b; // Attach smaller tree under the taller one
        } else if (rank[a] > rank[b]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rank[a]++; // ONLY increment when heights are equal
        }
    }
    */
}

int main() {
    int n,m;
    //n->no of elements  m->no of queries
    cin>>n>>m;

    vector<int> parent(n+1);
    for(int i=0; i<n+1; i++) {
        parent[i] = i;
    }
    vector<int> rank(n+1,0);

    while(m--) {
        int a, b;
        cin>>a>>b;
        bool check = Union(a,b,parent,rank);
        if(check == true) {
            cout<<"cycle detected!!!"<<endl;
            break;  
        }
    }

    return 0;
}