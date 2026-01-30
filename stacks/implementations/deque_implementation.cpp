#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class Stack {
public :
    deque<int> q;

    void push(int data) {
        this->q.push_back(data);
    }

    void pop() {
        if(this->q.empty()) {
            cout<<"Underflow!!!";
            return;
        }
        this->q.pop_back();
    }

    int top() {
        if(this->q.empty()) {
            cout<<"Underflow!!!";
            return INT_MIN;
        }
        return this->q.back();
    }

    bool isEmpty() {
        return this->q.empty();
    }

    int size() {
        return this->q.size();
    }
};



int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    cout<<st.size()<<endl;

    while(st.size() > 0) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    cout<<st.size();


    return 0;
}