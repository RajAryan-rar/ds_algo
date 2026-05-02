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
    /* data */
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Method -1:   
        // int len = 0;
        // ListNode *temp = head;
        // while(temp != NULL) {
        //     temp = temp->next;
        //     len++;
        // }
        // if(n == len) {
        //     head = head->next;
        //     return head;
        // }
        // temp = head;
        // for(int i=1; i<len-n; i++) {
        //     temp = temp->next;
        // }
        // temp->next = temp->next->next;
        // return head;

        //Method -2
        ListNode *slow = head, *fast = head;
        for(int i=1; i<=n+1; i++) {
            if(fast == NULL) return head->next;
            fast = fast->next;
        }

        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow -> next = slow->next->next;
        return head;
    }
};

int main() {
    

    return 0;
}