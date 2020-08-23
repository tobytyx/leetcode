#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            Node* pre = NULL;
            for(int i=0; i<len; i++){
                Node* cur = q.front();
                q.pop();
                if(pre != NULL){
                    pre->next = cur;  
                }
                pre = cur;
                if(cur->left != NULL) q.push(cur->left);
                if(cur->right != NULL) q.push(cur->right);
            }
        }
        return root;
    }
};