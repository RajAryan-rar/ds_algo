#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        vector<int> v(3,0); //0 -> 5, 1 -> 10, 2 -> 20
        for(int i=0; i<n; i++) {
            if(bills[i] == 5) v[0]++;
            else if(bills[i] == 10) {
                if(v[0] <= 0) return false;
                v[0]--;
                v[1]++;
            } else {
                if(v[0] <= 0) return false;
                if(v[1] > 0) {
                    v[1]--;
                    v[0]--;
                    v[2]++;
                } else {
                    if(v[0] < 3) return false;
                    v[0]-=3;
                    v[2]++;
                }
            }
        }
        return true;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> bills(n);

    for(int i=0; i<n; i++) {
        cin>>bills[i];
    }
    
    Solution s;
    cout<<s.lemonadeChange(bills)<<"\n";

    return 0;
}