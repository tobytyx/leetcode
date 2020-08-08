#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode* fast = head, *slow = new_head;
        while(fast != NULL){
            for(int i=0; i<k; i++){
                if (fast == NULL){
                   head = new_head->next;
                   delete new_head;
                   return head;
                }
                fast = fast->next;
            }
            ListNode* buff = slow->next, *last = slow;
            slow = fast;
            while(buff != fast){
                ListNode* c = buff->next;
                buff->next = slow;
                slow = buff;
                buff = c;
            }
            last->next->next = fast;
            buff = last->next;
            last->next = slow;
            slow = buff;
        }
        head = new_head->next;
        delete new_head;
        return head;
    }
};