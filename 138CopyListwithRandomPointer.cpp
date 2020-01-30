# include <iostream>
# include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node* cur = head;
        while (cur != NULL){
            Node* n = new Node(cur->val);
            n->next = cur->next;
            cur->next = n;
            cur = cur->next->next;
        }
        cur = head;
        while (cur != NULL){
            if (cur->random != NULL)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node* head_cp = head->next;
        Node* cur_cp = head_cp;
        cur = head;
        while (cur != NULL){
            cur->next = cur_cp->next;
            cur = cur->next;
            if(cur != NULL){
                cur_cp->next = cur->next;
                cur_cp = cur_cp->next;
            } 
        }
        return head_cp;
    }
};

int main(){
    Node a(7), b(13), c(11), d(10), e(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    b.random = &a;
    c.random = &e;
    d.random = &c;
    e.random = &a;
    Solution s;
    Node* cur = s.copyRandomList(&a);
    while (cur != NULL)
    {
        printf("%d_", cur->val);
        if (cur->random != NULL){
            printf("%d", cur->random->val);
        }
        printf("\n");
        cur = cur->next;
    }
    
    return 0;
}
