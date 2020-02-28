#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)  return head;
        ListNode *smaller = new ListNode(0), *s_ptr = smaller;
        ListNode *larger = new ListNode(0), *l_ptr = larger;
        while(head != NULL){
            if(head->val < x){
                s_ptr->next = head;
                head = head->next;
                s_ptr = s_ptr->next;
                s_ptr->next = NULL;
            }
            else{
                l_ptr->next = head;
                head = head->next;
                l_ptr = l_ptr->next;
                l_ptr->next = NULL;
            }
        }
        s_ptr->next = larger->next;
        head = smaller->next;
        delete smaller;
        delete larger;
        return head;
    }
};

int main(){
    Solution s;
    int a[] = {1,4,3,2,5,2};
    ListNode head(0);
    ListNode *ptr = &head;
    for(auto i: a){
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    ptr = head.next;
    ListNode* res = s.partition(ptr, 3);
    ptr = res;
    while(ptr){
        printf("%d-", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}
