#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL) return NULL;
        if(head->val == val) return head->next;
        ListNode* cur = head;
        while(cur->next != NULL){
            if(cur->next->val == val){
                cur->next = cur->next->next;
                return head;
            }
            cur = cur->next;
        }
        return head;
    }
};