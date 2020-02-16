# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode *slow=head, *fast=head->next;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        fast = slow->next;
        slow = NULL;
        while(head2){
            fast = head2->next;
            head2->next = slow;
            slow = head2;
            head2 = fast;
        }
        while(slow){
            if(head->val != slow->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
