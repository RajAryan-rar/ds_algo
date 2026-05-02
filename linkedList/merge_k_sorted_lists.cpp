#include<iostream>
#include<vector>
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

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size() == 0) return NULL;
        while(arr.size() > 1) {
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());
            ListNode* c = mergeTwoLists(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};

int main() {
    

    return 0;
}