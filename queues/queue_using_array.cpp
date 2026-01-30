#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Queue {
public : 
    vector<int> v;
    int front;
    int back;

    Queue() {
        this->front = -1;
        this->back = -1;
    }

    void enqueue(int data) {
        v.push_back(data);
        if(this->front == -1) {
            this->front++;
            this->back++;
        }
        else this->back++;
    }

    void dequeue() {
        if(this->front == -1 || this->front > this->back) {
            cout<<"Queue is empty!!!"<<endl;
            return;
        }
        this->front++;
    }

    int getFront() {
        if(this->front == -1 || this->front > this->back) {
            cout<<"Queue is empty!!!"<<endl;
            return INT_MIN;
        }
        return v[this->front];
    }

    bool isEmpty() {
        if(this->front == -1 || this->front > this->back) {
            return true;
        } else return false;
    }

    int getSize() {
        return this->back - this->front + 1;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout<<q.getFront()<<endl;

    q.dequeue();

    cout<<q.getFront()<<endl;

    while(!q.isEmpty()) {
        cout<<q.getFront()<<endl;
        q.dequeue();
    }

    cout<<q.getSize();

    return 0;
}