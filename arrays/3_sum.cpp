#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;

class Solution {
public :
    vector<vector<int>> threeSumBrute(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    if(nums[i]+nums[j]+nums[k] == 0) {
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }

    vector<vector<int>> threeSumBetter(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0; i<n; i++) {
            unordered_set<int> hashSet;
            for(int j=i+1; j<n; j++) {
                int ele = -(nums[i] + nums[j]);
                if(hashSet.find(ele) != hashSet.end()) {
                    vector<int> temp = {nums[i],ele,nums[j]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }

    vector<vector<int>> threeSumOptimal(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k++;
                }
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=0; i<n; i++) cin>>nums[i];

    Solution s;
    vector<vector<int>> ans = s.threeSumOptimal(nums);

    for(auto v : ans) {
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    }

    return 0;
}