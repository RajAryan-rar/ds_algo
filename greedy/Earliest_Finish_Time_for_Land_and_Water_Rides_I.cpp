#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& start1, vector<int>& dur1, vector<int>& start2, vector<int>& dur2) {
        int endTime1 = INT_MAX;
        for(int i=0; i<start1.size(); i++) {
            endTime1 = min(endTime1,start1[i]+dur1[i]);
        }
        int ans = INT_MAX;
        for(int j=0; j<start2.size(); j++) {
            int startTime2 = max(endTime1,start2[j]);
            int finishTime = startTime2+dur2[j];
            ans = min(ans,finishTime);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landThenWater = helper(landStartTime,landDuration,waterStartTime,waterDuration);

        int waterThenLand = helper(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(landThenWater,waterThenLand);
    }
};

int main() {
	int n,m;
	vector<int> landStartTime(n), landDuration(n), waterStartTime(m), waterDuration(m);
	
	Solution s;
	cout<<s.earliestFinishTime(landStartTime,landDuration,waterStartTime,WaterDuration)<<endl;


	return 0;
}
