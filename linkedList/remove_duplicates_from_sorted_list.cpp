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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *a = head, *b = head->next;

        while(b) {
            while(b != NULL && a->val == b->val) {
                b = b->next;
            }
            a->next = b;
            a = b;
            if(b) b = b->next;
        }
        return head;
    }
};

int main() {
    

    return 0;
}