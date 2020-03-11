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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        vector<TreeNode*> stack(1, root);
        TreeNode* p = root->left;
        while(!stack.empty() || p != NULL){
            while(p != NULL){
                stack.push_back(p);
                p = p->left;
            }
            TreeNode* cur = stack.back();
            stack.pop_back();
            res.push_back(cur->val);
            p = cur->right;
        }
        return res;
    }
};