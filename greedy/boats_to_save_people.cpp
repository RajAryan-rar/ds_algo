#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int n = people.size();
        int i=0, j=n-1;

        int shipCount = 0;
        while(i <= j) {
            if(i == j) {
                shipCount++;
                break;
            }
            if(people[i]+people[j] <= limit) {
                shipCount++;
                i++;
                j--;
            } else {
                shipCount++;
                j--;
            }
        }
        return shipCount;
    }
};

int main() {
    int n, limit;
    cin>>n>>limit;
    vector<int> people(n);

    for(int i=0; i<n; i++) {
        cin>>people[i];
    }

    Solution s;
    cout<<s.numRescueBoats(people,limit);

    return 0;
}