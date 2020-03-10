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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL)  return root;
        TreeNode* mirror = new TreeNode(root->val);
        mirror->left = mirrorTree(root->right);
        mirror->right = mirrorTree(root->left);
        return mirror;
    }
};