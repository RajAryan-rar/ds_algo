#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int x = INT_MIN;
        int n = q.size();
        for(int i=0; i<n-1; i++) {
            q.push(q.front());
            q.pop();
        }
        x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        int x = INT_MIN;
        for(int i=0; i<q.size(); i++) {
            if(i == q.size()-1) {
                x = q.front();
            }
            q.push(q.front());
            q.pop();
        }
        return x;
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    

    return 0;
}