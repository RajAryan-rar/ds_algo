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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *odd = head, *even = head->next;
        ListNode *evenHead = even;

        while(odd->next && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

int main() {
    

    return 0;
}