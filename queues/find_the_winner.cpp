#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n; i++) {
            q.push(i);
        }

        while(q.size() > 1) {
            int x = 1;
            while(x < k) {
                q.push(q.front());
                q.pop();
                x++;
            }
            q.pop();
        }
        return q.front();
    }
};

int main() {
    int n,k;
    cin>>n>>k;

    Solution s;
    cout<<s.findTheWinner(n,k);

    return 0;
}