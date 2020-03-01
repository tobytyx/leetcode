#include<iostream>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        deque<TreeNode*> q;
        q.push_front(root);
        int depth = 0;
        while(!q.empty()){
            int len = q.size();
            depth++;
            for(int i=0; i<len; i++){
                TreeNode* cur = q.back();
                q.pop_back();
                if(cur->left == NULL && cur->right == NULL) return depth;
                if(cur->left != NULL) q.push_front(cur->left);
                if(cur->right != NULL) q.push_front(cur->right);
            }
        }
        return depth;
    }
};