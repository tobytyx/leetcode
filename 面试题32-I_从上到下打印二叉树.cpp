#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        deque<TreeNode*> q(1, root);
        while(!q.empty()){
            TreeNode *cur = q.back();
            q.pop_back();
            res.push_back(cur->val);
            if(cur->left != NULL) q.push_front(cur->left);
            if(cur->right != NULL) q.push_front(cur->right);
        }
        return res;
    }
};