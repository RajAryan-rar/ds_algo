#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int transform(string A, string B) {
        vector<int> count(200,0);
        
        for(char c : A) count[c]++;
        for(char c : B) count[c]--;
        
        for(int c : count) {
            if(c != 0) return -1;
        }
        
        int i = A.length()-1, j = B.length()-1;
        int ans = 0;
        
        while(i >= 0) {
            if(A[i] == B[j]) {
                i--;
                j--;
            } else {
                ans++;
                i--;
            }
        }
        return ans;
    }
};


int main() {
    string s1,s2;
    cin>>s1>>s2;

    Solution s;
    cout<<s.transform(s1, s2)<<endl;

    return 0;
}