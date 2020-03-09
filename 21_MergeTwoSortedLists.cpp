#include<iostream>
#include<string>
#include<vector>
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
        ListNode* new_head = new ListNode(0);
        new_head->next = l1;
        ListNode* c1 = new_head, *c2 = l2;
        while(c1->next != NULL && c2 != NULL){
            
            if(c1->next->val > c2->val){
                ListNode* tmp = c2->next;
                c2->next = c1->next;
                c1->next = c2;
                c2 = tmp;
                c1 = c1->next;
            }
            else{
                c1 = c1->next;
            }
        }
        if(c1->next == NULL) c1->next = c2;
        c1 = new_head->next;
        delete new_head;
        return c1;
    }
};