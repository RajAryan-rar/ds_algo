#include<iostream>
#include<climits>
using namespace std;

class Node{
public :
    int val;
    Node* next;
    Node(int val) {;
        this->val = val;
        this->next = NULL;
    }
};

class Stack {
    int capacity;
    int sizee;
    Node* head = new Node(INT_MIN);

    public :
    Stack(int c) {
        this->capacity = c;
        this->sizee = 0;
    }

    void push(int val) {
        if(sizee == capacity) {
            cout<<"Overflow!"<<endl;
            return;
        }
        Node* temp = new Node(val);
        temp->next = this->head;
        this->head = temp;
        this->sizee++;
    }

    int getsizee() {
        if(this->head->val == INT_MIN) {
            cout<<"Underflow!"<<endl;
            return INT_MIN;
        }
        return this->head->val;
    }

    void pop() {
        if(this->head->val == INT_MIN) {
            cout<<"Underflow!"<<endl;
            return;
        }
        this->head = this->head->next;
        this->sizee--;
    }

    bool isEmpty() {
        return this->head->val == INT_MIN;
    }

    int size() {
        return this->sizee;
    }

    bool isFull() {
        return this->sizee == this->capacity;
    }
};

int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.getsizee();

    st.pop();
    cout<<st.getsizee();

    return 0;
}