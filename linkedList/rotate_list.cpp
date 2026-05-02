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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *temp = head, *tail = head;
        int len = 0;
        while(temp) {
            if(temp->next == NULL) tail = temp;
            temp = temp->next;
            len++;
        }

        temp = head;
        k = k%len;
        for(int i=1; i<len-k; i++) {
            temp = temp->next;
        }

        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

int main() {
    

    return 0;
}