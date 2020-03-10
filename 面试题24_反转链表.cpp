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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *pre = head, *cur = head->next;
        while(cur != NULL){
            head->next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = head->next;
        }
        return pre;
    }
};