#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;

        int totalRabbits = 0;
        for(int ele : answers) {
            if(ele == 0) totalRabbits++;
            else if(mp.find(ele+1) == mp.end()) {
                totalRabbits += (ele+1);
                mp[ele+1] = 1;
            } else {
                mp[ele+1]++;
                if(mp[ele+1] == ele+1) mp.erase(ele+1);
            }
        }
        return totalRabbits;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> answers(n);
    for(int i=0; i<n; i++) {
        cin>>answers[i];
    }

    Solution s;
    cout<<s.numRabbits(answers);

    return 0;
}