#include<iostream>
#include<vector>
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
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *pre = new_head, *cur = head;
        while(cur != NULL){
            while(cur->next != NULL && cur->val == cur->next->val){
                ListNode *buff = cur->next;
                delete cur;
                cur = buff;
            }
            if(pre->next == cur){ //非重复
                pre = pre->next;
            }
            else{
                pre->next = cur->next;
                delete cur;
            }
            cur = pre->next;
        }
        pre = new_head->next;
        delete new_head;
        return pre;
    }
};