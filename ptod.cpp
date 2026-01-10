#include<iostream>
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

void display(Node* temp) {
    while(temp) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}



int main() {
    Node* a = new Node(5);
    Node* b = new Node(4);
    Node* c = new Node(3);
    Node* d = new Node(2);
    Node* e = new Node(1);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    display(a);

    return 0;
}