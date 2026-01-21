#include<iostream>
#include<vector>
using namespace std;

#include<iostream>
#include<vector>
using namespace std;

int K,L;
vector<int> dp;

int f(int x) {
    if(x < 0) return 1;
    if(x == 0) return 0;
    if(x == 1 || x == K || x == L) return 1;
    if(dp[x] != -1) return dp[x];

    return dp[x] = !(f(x-1) && f(x-K) && f(x-L));
}

int main() {
    cin>>K>>L;
    int m;
    cin>>m;

    while(m--) {
        int n;
        cin>>n;
        dp.clear();
        dp.resize(1000006,-1);
        int res = f(n);
        if(res == 1) cout<<"A";
        else cout<<"B";
    }

    return 0;
}

int main() {
    

    return 0;
}