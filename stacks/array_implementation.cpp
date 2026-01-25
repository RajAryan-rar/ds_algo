#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Stack {
    int capacity;
    int top;
    vector<int> arr;

    public:
    Stack(int c) {
        this->capacity = c;
        this->arr.resize(c,0);
        this->top = -1;
    }

    void push(int ele) {
        if(this->top == this->capacity-1) {
            cout<<"Stack overflow!"<<endl;
        } else {
            this->top++;
            this->arr[this->top] = ele;
        }
    }

    void pop() {
        if(this->top == -1) {
            cout<<"Underflow!"<<endl;
        }
        this->top--;
    }

    int topEle() {
        if(this->top == -1) {
            cout<<"Underflow!"<<endl;
            return INT_MIN;
        } else {
            return this->arr[this->top];
        }
    }

    bool isEmpty() {
        return this->top == -1;
    }

    int size() {
        return this->top+1;
    }

    bool isFull() {
        return this->top == this->capacity-1;
    }

};

int main() {
    Stack st(5);

    st.push(3);
    st.push(1);
    st.push(2);

    cout<<st.topEle();

    return 0;
}