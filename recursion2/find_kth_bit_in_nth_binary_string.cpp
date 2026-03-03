#include<iostream>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        int len = (1 << n) - 1;
        int mid = len/2 + 1;

        if(k == mid) return '1';

        else if(k < mid) return findKthBit(n-1, k);

        else {                                 //new k
            char mirroredBit = findKthBit(n-1, len-k+1);
            return (mirroredBit == '0') ? '1' : '0';
        }
    }
};

int main() {
    int n,k;
    cin>>n>>k;

    Solution s;
    cout<<s.findKthBit(n,k);

    return 0;
}