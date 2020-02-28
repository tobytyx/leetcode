#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* m_ptr = new_head;
        for(int i=1; i<m; i++) m_ptr = m_ptr->next;
        ListNode* cur = m_ptr->next;
        for(int i=0; i<n-m; i++){
            ListNode* cache = cur->next;
            cur->next = cache->next;
            cache->next = m_ptr->next;
            m_ptr->next = cache;
        }
        return new_head->next;
    }
};