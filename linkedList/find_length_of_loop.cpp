#include<iostream>
using namespace std;

class Node{
public :
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node *slow = head, *fast = head;
        bool flag = false;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                flag = true;
                break;
            }
        }
        if(!flag) return 0;
        Node *temp = head;
        while(temp != slow) {
            temp = temp->next;
            slow = slow->next;
        }
        temp = temp->next;
        int len = 1;
        while(temp != slow) {
            len++;
            temp = temp->next;
        }
        return len;
    }
};

int main() {
    

    return 0;
}