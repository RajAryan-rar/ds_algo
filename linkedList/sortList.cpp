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
    ListNode* merge(ListNode *a, ListNode *b) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while(a && b) {
            if(a->val <= b->val) {
                temp->next = a;
                temp = a;
                a = a->next;
            } else {
                temp->next = b;
                temp = b;
                b = b->next;
            }
        }
        if(a) temp->next = a;
        else if(b) temp->next = b;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //now slow is at left middle
        ListNode *a = head, *b = slow->next;
        slow->next = NULL;
        a = sortList(a);
        b = sortList(b);
        ListNode *c = merge(a,b);
        return c;
    }
};

int main() {
    

    return 0;
}