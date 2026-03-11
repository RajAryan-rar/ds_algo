#include<iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while(mask < n) {
            mask = (mask << 1) | 1; 
        }
        return mask ^ n;
    }
};

int main() {
    int n;
    cin>>n;

    Solution s;
    cout<<s.bitwiseComplement(n);

    return 0;
}