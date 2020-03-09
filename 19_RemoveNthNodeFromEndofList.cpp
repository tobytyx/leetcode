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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* fast = head;
        for(int i=1; i<n; i++){
            fast = fast->next;
            if (fast == NULL){
                return head;
            }
        }
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode* cur = new_head;
        while(fast->next != NULL){
            fast = fast->next;
            cur = cur->next;
        }
        ListNode* tmp = cur->next->next;
        delete cur->next;
        cur->next = tmp;
        cur = new_head->next;
        delete new_head;
        return cur;
    }
};