#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //now slow is at right middle

        ListNode *temp = head;
        while(temp->next != slow) temp = temp->next;

        temp->next = temp->next->next;
        return head;
    }
};

int main() {
    

    return 0;
}