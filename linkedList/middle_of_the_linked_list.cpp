#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //Method -1:
        /*
        int len = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            temp = temp->next;
            len++;
        }
        temp = head;
        for(int i=0; i<len/2; i++) {
            temp = temp->next;
        }
        return temp;
        */

        //Method -2:
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }
};

int main() {
    

    return 0;
}