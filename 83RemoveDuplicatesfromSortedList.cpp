#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* pre = head, *cur = head->next;
        while(cur != NULL){
            if(pre->val == cur->val){
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else{
                pre = pre->next;
                cur = cur->next;
            }
        }
        return head;
    }
};
