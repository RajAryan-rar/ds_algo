#include<iostream>
#include<vector>
using namespace std;

class Solution{
public :
    int BruteForce(string s) {
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            vector<int> hash(3,0);
            for(int j=i; j<s.length(); j++) {
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3) {
                    count++;
                }
            }
        }
        return count;
    }

    int numberOfSubstrings(string s) {
        int count = 0;
        vector<int> hash(3,-1);

        for(int i=0; i<s.length(); i++) {
            hash[s[i] - 'a'] = i;
            if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1) {
                count += (1 + min(hash[0], min(hash[1],hash[2])));
            }
        }
        return count;
    }
};

int main() {
    string str;
    cin>>str;

    Solution s;
    cout<<s.numberOfSubstrings(str);

    return 0;
}