#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* cur = head;
        int len = 1;
        while(cur->next != NULL){
            len++;
            cur = cur->next;
        }
        cur->next = head;
        cur = head;
        k = len - k % len;
        for(;k > 1; k--){
            cur = cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};