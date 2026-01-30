#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()) {
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        helper.pop();
        while(helper.size() > 0) {
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() {
        while(!st.empty()) {
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        while(helper.size() > 0) {
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    bool empty() {
        cout<<st.size();
        return st.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    

    return 0;
}