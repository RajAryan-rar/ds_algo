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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *tempA = headA, *tempB = headB;
        while(tempA != NULL) {
            tempA = tempA->next;
            lenA++;
        }
        while(tempB != NULL) {
            tempB = tempB->next;
            lenB++;
        }
        tempA = headA;
        tempB = headB;
        int diff = abs(lenA - lenB);
        if(lenA > lenB) {
            for(int i=1; i<=diff; i++) tempA = tempA->next;
        } else {
            for(int i=1; i<=diff; i++) tempB = tempB->next;
        }
        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};

int main() {
    

    return 0;
}