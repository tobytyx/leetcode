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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL)  return false;
        vector<TreeNode*> stack(1, A);
        while(!stack.empty()){
            TreeNode* root = stack.back();
            stack.pop_back();
            if(isSub(root, B)) return true;
            if(root->right != NULL) stack.push_back(root->right);
            if(root->left != NULL) stack.push_back(root->left);
        }
        return false;
    }

    bool isSub(TreeNode* A, TreeNode* B){
        if(B == NULL) return true;
        if(A == NULL) return false;
        if(A->val == B->val && isSub(A->left, B->left) && isSub(A->right, B->right)) return true;
        return false;
    }
};