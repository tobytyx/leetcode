#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* cur1 = l1, *cur2 = l2;
        ListNode* newhead = new ListNode(0);
        newhead->next = l1;
        cur1 = newhead;
        while(cur1->next != NULL && cur2 != NULL){
            if(cur1->next->val > cur2->val){
                ListNode* tmp = cur1->next;
                cur1->next = cur2;
                cur2 = cur2->next;
                cur1->next->next = tmp;
            }
            cur1 = cur1->next;
        }
        if(cur2 != NULL){
            cur1->next = cur2;
        }
        cur1 = newhead->next;
        delete newhead;
        return cur1;
    }
};