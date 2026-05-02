#include<iostream>
using namespace std;

struct Node {
    string val;
    Node *next;
    Node *prev;
    Node(string val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
public:
    Node *head;
    Node *curr;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        curr = head;
    }
    
    void visit(string url) {
        //deleting forward history
        if(curr->next != NULL) {
            curr->next = NULL;
        }
        //adding new node
        Node *newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    
    string back(int steps) {
        if(steps == 0) return curr->val;
        for(int i=0; i<steps; i++) {
            if(curr == head) return head->val;
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        if(curr->next == NULL) return curr->val;
        for(int i=0; i<steps; i++) {
            if(curr->next == NULL) return curr->val;
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {
    

    return 0;
}