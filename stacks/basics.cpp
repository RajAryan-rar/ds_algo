#include<iostream>
#include<stack>
using namespace std;

void f(stack<int> &s1, stack<int> &s2) {
    if(s1.size() == 0) return;
    int x = s1.top();
    s1.pop();
    f(s1,s2);
    s2.push(x);
}

void display(stack<int> st) {
    while(st.size() > 0) {
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<endl;
}
 
void insertAtBottom(stack<int>& st, int val) {
    if(st.size() == 0) {
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    insertAtBottom(st,val);
    st.push(x);
}

void insertAtIdx(stack<int>& st, int val, int idx) {
    if(idx > st.size()) {
        cout<<"Overflow!!"<<endl;
        return;
    }
    if(idx == st.size()) {
        st.push(val);
        return;
    }
    if(st.size() == idx) {
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    insertAtIdx(st,val,idx);
    st.push(x);
}

void removeAtBottom(stack<int>& st) {
    if(st.size() == 1) {
        st.pop();
        return;
    }
    int x = st.top();
    st.pop();
    removeAtBottom(st);
    st.push(x);
}

void removeAtIdx(stack<int>& st, int idx) {
    if(idx < 0 || idx >= st.size()) {
        if(idx < 0) cout<<"Underflow!"<<endl;
        else cout<<"Overflow!"<<endl;
        return;
    }
    if(idx == st.size()-1) {
        st.pop();
        return;
    }
    int x = st.top();
    st.pop();
    removeAtIdx(st,idx);
    st.push(x);
}

void reverse(stack<int>& st) {
    if(st.size() == 0) return;
    int x = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,x);
}

int main() {
    stack<int> s1,s2;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    display(s1);
    // f(s1,s2);
    // display(s2);

    // insertAtBottom(s1,100);

    // insertAtIdx(s1,100,1);
    
    // removeAtBottom(s1);

    // removeAtIdx(s1,1);

    reverse(s1);

    display(s1);
    
    return 0;
}