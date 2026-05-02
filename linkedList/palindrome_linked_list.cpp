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
    ListNode *reverseList(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = head, *tempC = dummy;

        while(temp) {
            ListNode *newNode = new ListNode(temp->val);
            tempC->next = newNode;
            temp = temp->next;
            tempC = tempC->next;
        }
        dummy = dummy->next;
        dummy = reverseList(dummy);

        tempC = dummy;
        temp = head;
        while(temp) {
            if(temp->val != tempC->val) return false;
            temp = temp->next;
            tempC = tempC->next;
        }
        return true;

    }
};

int main() {
    

    return 0;
}