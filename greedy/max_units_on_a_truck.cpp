#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),cmp);

        int maxUnits = 0;
        for(int i=0; i<n; i++) {
            int boxes = boxTypes[i][0];
            int units = boxTypes[i][1];

            if(boxes <= truckSize) {
                maxUnits += (boxes * units);
                truckSize -= boxes;
            } else {
                maxUnits += (truckSize * units);
                return maxUnits;
            }
        }
        return maxUnits;
    }
};

int main() {
    int n, truckSize;
    cin>>n>>truckSize;

    vector<vector<int>> boxTypes(n, vector<int>(2));
    for(int i=0; i<n; i++) {
        cin>>boxTypes[i][0]>>boxTypes[i][1];
    }

    Solution s;
    cout<<s.maximumUnits(boxTypes,truckSize)<<endl;

    return 0;
}