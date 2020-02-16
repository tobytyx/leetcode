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
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        int curLen = 0;
        ListNode h_head(0);
        h_head.next = head;
        ListNode* cur = head;
        while(cur != NULL){
            curLen++;
            cur = cur->next;
        }
        int len = 1;
        while(len < curLen){
            int i = 0;
            cur = &h_head;
            for(; i+2*len < curLen; i=i+2*len){
                ListNode *second = cur->next;
                for(int k=0; k<len; k++)
                    second = second->next;
                ListNode* next_head = second;
                for(int k=0; k<len; k++){
                    next_head = next_head->next;
                }
                cur = merge_sort(cur, len, second, len);
                cur->next = next_head;
            }
            if(i + len < curLen){
                ListNode *second = cur->next;
                for(int k=0; k<len; k++)
                    second = second->next;
                cur = merge_sort(cur, len, second, curLen-i-len);
                cur->next = NULL;
            }
            len *= 2;
        }
        return h_head.next;
    }

    ListNode* merge_sort(ListNode* head, int first_len, ListNode* second_cur, int second_len){
        int i = 0, j = 0;
        ListNode *first_cur = head->next;
        while(i < first_len && j < second_len){
            if(first_cur->val < second_cur->val){
                head->next = first_cur;
                head = head->next;
                first_cur = first_cur->next;
                i++;
            }
            else{
                head->next = second_cur;
                head = head->next;
                second_cur = second_cur->next;
                j++;
            }
        }
        while(i < first_len){
            head->next = first_cur;
            head = head->next;
            first_cur = first_cur->next;
            i++;
        }
        while(j < second_len){
            head->next = second_cur;
            head = head->next;
            second_cur = second_cur->next;
            j++;
        }
        return head;
    }
};

int main(){
    ListNode a(5), b(4), c(3), d(2), e(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution s;
    ListNode *head = s.sortList(&a);
    while(head != NULL){
        printf("%d-", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
