#include<iostream>
#include<vector>
using namespace std;

//Q1. Count total no of ways
//Approach -1 : (0,0) se (m-1,n-1)
//Approach -2 : (m-1,n-1) se (0,0)

/*
int f(vector<vector<int>>& grid, int i, int j) {
    if(i >= grid.size() || j >= grid[0].size()) return 0;
    if(i == grid.size()-1 && j == grid[0].size()-1) return 1;
    
    return f(grid,i,j+1) + f(grid,i+1,j);
}
*/

//Q2. Print all possible ways
//Approach -1 : 

void f(vector<vector<int>>& grid, int i, int j, string s) {
    if(i >= grid.size() || j >= grid[0].size()) return;
    if(i == grid.size()-1 && j == grid[0].size()-1) {
        cout<<s<<endl;
        return;
    }

    f(grid,i,j+1,s+"R");
    f(grid,i+1,j,s+"D");
}

int main() {
    vector<vector<int>> grid;
    int m,n;
    cin>>m>>n;
    grid.resize(m, vector<int>(n));

   // cout<<f(grid,0,0); // (0,0) -> start point
   f(grid,0,0,"");

    return 0;
}