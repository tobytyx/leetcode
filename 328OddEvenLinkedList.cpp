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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *odd_ptr = head->next, *even_ptr = head, *odd_head = head->next;
        ListNode *ptr = odd_ptr->next;
        while(ptr){
            even_ptr->next = ptr;
            even_ptr = ptr;
            ptr = ptr->next;
            if(ptr == NULL) break;
            odd_ptr->next = ptr;
            odd_ptr = ptr;
            ptr = ptr->next;
        }
        even_ptr->next = odd_head;
        odd_ptr->next = NULL;
        return head;
    }
};
