# include <iostream>
# include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = NULL, *next_ptr = head;
        while(head != NULL){
            next_ptr = head->next;
            head->next = cur;
            cur = head;
            head = next_ptr;
        }
        return cur;
    }

    ListNode* reverseList2(ListNode* head) {
        if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverseList2(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
};
