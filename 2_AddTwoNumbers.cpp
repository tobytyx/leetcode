#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        ListNode* cur = head;
        carry = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != NULL && l2 != NULL){
            cur->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL){
            cur->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2 != NULL){
            cur->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            cur = cur->next;
            l2 = l2->next;
        }
        if(carry > 0){
            cur->next = new ListNode(carry);
        }
        return head;
    }
};

int main(){
    int m = 0, n = 0;
    cin >> m;
    ListNode* l1_head = new ListNode(0), *l2_head = new ListNode(0);
    ListNode* l1 = l1_head, *l2 = l2_head;
    for(int i=0; i<m; i++){
        int num = 0;
        cin >> num;
        l1->next = new ListNode(num);
        l1 = l1->next;
    }
    cin >> n;
    for(int i=0; i<n; i++){
        int num = 0;
        cin >> num;
        l2->next = new ListNode(num);
        l2 = l2->next;
    }
    Solution s;
    ListNode* res =  s.addTwoNumbers(l1_head->next, l2_head->next);
    ListNode* cur = res;
    while(cur != NULL){
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
    return 0;
}