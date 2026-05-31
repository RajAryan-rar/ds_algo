#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        ll planet = mass;

        for(int i=0; i<n; i++) {
            if(planet >= asteroids[i]) planet += asteroids[i];
            else return false;
        }   
        return true;
    }
};

int main() {
    int n, mass;
    cin>>n>>mass;

    vector<int> asteroids(n);
    
    Solution s;
    if(s.asteroidsDestroyed(mass,asteroids)) cout<<"True\n";
    else cout<<"False\n";

    return 0;
}