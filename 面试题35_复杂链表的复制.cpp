#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
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
        if(head == NULL) return NULL;
        Node* cur = head;
        while(cur != NULL){
            Node* copy_node = new Node(cur->val);
            copy_node->next = cur->next;
            cur->next = copy_node;
            cur = cur->next->next;
        }
        cur = head;
        while(cur != NULL){
            if(cur->random != NULL)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node* copy_head = head->next, *copy_cur=head->next;
        cur = head;
        while(cur != NULL){
            cur->next = copy_cur->next;
            cur = cur->next;
            if(cur != NULL){
                copy_cur->next = cur->next;
                copy_cur = copy_cur->next;
            }
        }
        return copy_head;
    }
};