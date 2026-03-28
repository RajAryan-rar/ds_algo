#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,0), right(n,0);

        //distributing while considering left neighbors only
        left[0] = 1;
        for(int i=1; i<n; i++) {
            if(ratings[i-1] >= ratings[i]) left[i] = 1;
            else left[i] = left[i-1] + 1;
        }
        //distribution while considering right neighbors only
        right[n-1] = 1;
        for(int i=n-2; i>=0; i--) {
            if(ratings[i+1] >= ratings[i]) right[i] = 1;
            else right[i] = right[i+1] + 1;
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += max(left[i],right[i]);
        }
        return ans;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> ratings(n);

    for(int i=0; i<n; i++) cin>>ratings[i];

    Solution s;
    cout<<s.candy(ratings)<<endl;


    return 0;
}