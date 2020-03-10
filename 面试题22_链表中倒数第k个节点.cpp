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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(k <= 0) return NULL;
        ListNode* slow = head, *fast = head;
        for(int i=0; i<k; i++){
            if(fast == NULL) return head;
            fast = fast->next;
        }
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};