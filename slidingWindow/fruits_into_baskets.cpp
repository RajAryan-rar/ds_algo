#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int totalFruitsBruteForce(vector<int> nums) {
        int maxLen = 0;
        
        for(int i=0; i<nums.size(); i++) {
            unordered_set<int> st;
            for(int j=i; j<nums.size(); j++) {
                st.insert(nums[j]);
                if(st.size() > 2) break;
                else maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }

    int totalFruitsBetter(vector<int> nums) {
        unordered_map<int,int> mp;
        int l = 0, r = 0, maxLen = 0;

        while(r < nums.size()) {
            mp[nums[r]]++;
            if(mp.size() <= 2) maxLen = max(maxLen,r-l+1);
            else {
                while(mp.size() != 2) {
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) mp.erase(nums[l]);
                    l++;
                }
            }
            r++;
        }
        return maxLen;
    }

    int totalFruitOptimal(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int maxLen = 0, l = 0, r = 0;
        while(r < fruits.size()) {
            mp[fruits[r]]++;
            if(mp.size() <= 2) maxLen = max(maxLen, r-l+1);
            else {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            r++;
        }
        return maxLen;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    Solution s;
    cout<<s.totalFruits(arr);

    return 0;
}