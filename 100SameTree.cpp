#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameSubTree(p, q);
    }

    bool isSameSubTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        return (p->val == q->val) && isSameSubTree(p->left, q->left) && isSameSubTree(p->right, q->right);
    }
};