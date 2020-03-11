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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        vector<TreeNode*> cache(1, root);
        while(!cache.empty()){
            TreeNode* cur = cache.back();
            cache.pop_back();
            res.push_back(cur->val);
            if(cur->right != NULL) cache.push_back(cur->right);
            if(cur->left != NULL) cache.push_back(cur->left);
        }
        return res;
    }
};