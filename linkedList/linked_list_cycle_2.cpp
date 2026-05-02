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
    ListNode *detectCycle(ListNode *head) {
        bool flag = false;
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                flag = true;
                break;
            }
        }
        if(!flag) return NULL;
        ListNode *temp = head;
        while(temp != slow) {
            temp = temp->next;
            slow = slow->next;
        }
        return temp;
    }
};

int main() {
    

    return 0;
}