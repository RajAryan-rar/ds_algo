#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, leftSum = 0, rightSum = 0;
        for(int i=0; i<k; i++) {
            leftSum += cardPoints[i];
        }
        sum = leftSum;
        int l = k-1;
        int r = cardPoints.size()-1;

        while(l >= 0) {
            leftSum -= cardPoints[l];
            l--;
            rightSum += cardPoints[r];
            r--;
            sum = max(sum, leftSum + rightSum);
        }
        return sum;
    }
};

int main() {
    int n,k;
    cin>>n>>k;

    vector<int> cardPoints(n);
    for(int i=0; i<n; i++) {
        cin>>cardPoints[i];
    }

    Solution s;
    cout<<s.maxScore(cardPoints,k);

    return 0;
}