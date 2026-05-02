#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int val) {
        this -> val = val;
        this -> next = NULL;
    }
};
class MyLinkedList {
public:
    Node *head;
    Node *tail;
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) {
        if(head == NULL) return -1;
        Node *temp = head;
        for(int i=1; i<=index; i++) {
            temp = temp->next;
            if(temp == NULL) return -1;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0) {
            addAtHead(val);
            return;
        }
        Node *temp = head;
        for(int i=1; i<=index-1; i++) {
            if(temp == NULL) return;
            temp = temp->next;
        }
        if(temp == NULL) return;
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if(newNode->next == NULL) tail = newNode;
    }
    
    void deleteAtIndex(int index) {
        if(head == NULL) return;
        else if(index == 0) {
            head = head->next;
            if(head == NULL) tail = head;
            return;
        } else {
            Node *temp = head;
            for(int i=1; i<index; i++) {
                temp = temp->next;
            }
            if(temp == NULL || temp->next == NULL) return;
            temp->next = temp->next->next;
            if(temp->next == NULL) {
                tail = temp;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    

    return 0;
}