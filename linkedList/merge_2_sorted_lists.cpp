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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *a = list1, *b = list2, *temp = dummy;

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
};

int main() {
    

    return 0;
}