#include<iostream>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        long long ans = 0;
        long long x = n;
        while(x > 0) {
            if(x%2 == 0) x /= 2;
            else {
                if((x&3) == 3 && x!=3) x++;
                else x--;
            }
            ans++;
        }
        return ans-1;
    }
};

int main() {
    int n;
    cin>>n;
    
    Solution s;
    cout<<s.integerReplacement(n)<<endl;

    return 0;
}