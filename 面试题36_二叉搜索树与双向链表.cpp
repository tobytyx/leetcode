#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return root;
        vector<Node*> stack(1, root);
        Node* p = root->left, *r = NULL;
        Node* head = NULL;
        while(!stack.empty() || p != NULL){
            while(p != NULL){
                stack.push_back(p);
                p = p->left;
            }
            Node* cur = stack.back();
            stack.pop_back();
            if(head == NULL) head = cur;
            if(r != NULL) r->right = cur;
            cur->left = r;
            r = cur;
            p = cur->right;
        }
        if(r != NULL){
            head->left = r;
            r->right = head;
        }
        return head;
    }
};