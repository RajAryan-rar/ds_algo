#include<iostream>
using namespace std;


struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverseList(Node *head) {
        Node *prev = NULL, *curr = head, *Next = head;
        while(curr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        head = reverseList(head);
        Node *dummy = new Node(-1);
        Node *t = head, *temp = dummy;
        int sum = 0, carry = 1;
        while(t) {
            sum = carry;
            sum += t->data;
            Node *curr = new Node(sum%10);
            carry = sum / 10;
            temp->next = curr;
            temp = temp->next;
            t = t->next;
        }
        if(carry != 0) {
            Node *c = new Node(carry);
            temp->next = c;
            temp = temp->next;
        }
        dummy = dummy->next;
        dummy = reverseList(dummy);
        
        return dummy;
    }
};

int main() {
    

    return 0;
}