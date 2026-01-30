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

class Queue {
    public : 
    Node* head;
    Node* tail;
    int size;

    Queue() {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    void enqueue(int val) {
        Node* temp = new Node(val);
        if(this->head == NULL) {
            this->head = temp;
            this->tail = temp;
        } else {
            this->tail->next = temp;
            this->tail = temp;
        }
        this->size++;
    }

    void dequeue() {
        if(this->head == NULL) {
            cout<<"underflow"<<endl;
            return;
        } 
        this->head = this->head->next;
        this->size--;
    }

    int front() {
        if(this->size == 0) {
            cout<<"queue is empty";
            return INT_MIN;
        }
        else return this->head->val;
    }

    bool isEmpty() {
        if(this->size == 0) return true;
        else return false;
    }

    int getSize() {
        return this->size;
    }

};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<q.front();

    q.dequeue();

    cout<<q.front();

    cout<<q.getSize();

    return 0;
}